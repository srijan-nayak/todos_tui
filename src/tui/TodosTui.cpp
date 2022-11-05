//
// Created by Srijan Nayak on 26-10-2022.
//

#include "TodosTui.h"

#include "../todos/TodoList.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include <utility>
#include <vector>

namespace tui {

TodosTui::TodosTui(todos::TodoList &todo_list) : todo_list_(todo_list) {
  ReloadTodoListComponent();
}

void TodosTui::StartLoop() {
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  auto layout = ftxui::Container::Vertical(
    {
      NewTodoForm() | ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, 6),
      todo_list_component_
        | ftxui::Renderer([&](ftxui::Element element) {
          return todo_list_.GetTodoItems().empty()
                 ? ftxui::text("") // display nothing if list is empty
                 : std::move(element);
        })
        | ftxui::yframe
    }
  )
    | ftxui::Renderer([](ftxui::Element element) {
      return ftxui::vbox(
        {
          ftxui::text("Todos TUI") | ftxui::center | ftxui::bold | ftxui::inverted,
          ftxui::separator(),
          std::move(element)
        }
      ) | ftxui::border;
    });

  screen.Loop(layout);
}

ftxui::Component TodosTui::NewTodoForm() {
  auto new_todo_input = ftxui::Input(&new_todo_text_, "type new todo")
    | ftxui::Renderer([](ftxui::Element element) {
      return ftxui::hbox({ftxui::text("New todo: "), std::move(element)}); // add label to input
    });

  auto add_todo_button = ftxui::Button("Add todo", [&] {
    if (!new_todo_text_.empty()) {
      todo_list_.AddNewTodoItem(new_todo_text_);
      new_todo_text_ = "";
      ReloadTodoListComponent();
    }
  })
    | ftxui::color(ftxui::Color::Green)
    | ftxui::Renderer([](ftxui::Element element) {
      return ftxui::hbox({std::move(element), ftxui::filler()}); // left-align button
    });

  return ftxui::Container::Vertical({new_todo_input, add_todo_button})
    | ftxui::border;
}

ftxui::Component TodosTui::TodoItemComponent(const todos::TodoItem &todo_item) {
  auto completed_button = ftxui::Button(todo_item.IsCompleted() ? " ✓ " : "   ", [=] {
    todo_list_.ToggleTodoItemIsCompleted(todo_item.GetId());
    ReloadTodoListComponent();
  });
  auto delete_button = ftxui::Button("Delete", [=] {
    todo_list_.RemoveTodoItem(todo_item.GetId());
    ReloadTodoListComponent();
  }) | ftxui::color(ftxui::Color::Red);
  auto buttons = ftxui::Container::Horizontal({completed_button, delete_button});
  return ftxui::Renderer(buttons, [=] {
    return ftxui::hbox(
      {
        ftxui::text(todo_item.GetTodoText()) | ftxui::border | ftxui::flex,
        buttons->Render()
      }
    );
  });
}

void TodosTui::ReloadTodoListComponent() {
  todo_list_component_->DetachAllChildren();
  for (const auto &todo_item : todo_list_.GetTodoItems())
    todo_list_component_->Add(TodoItemComponent(todo_item));
}

} // namespace tui