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

TodosTui::TodosTui(todos::TodoList &todo_list) : todo_list_(todo_list) {}

void TodosTui::StartLoop() {
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  auto layout = ftxui::Container::Vertical({NewTodoForm(), TodoList()})
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
    if (!new_todo_text_.empty())
      todo_list_.AddNewTodoItem(new_todo_text_);
    new_todo_text_ = "";
  })
    | ftxui::color(ftxui::Color::Green)
    | ftxui::Renderer([](ftxui::Element element) {
      return ftxui::hbox({std::move(element), ftxui::filler()}); // left-align button
    });

  return ftxui::Container::Vertical({new_todo_input, add_todo_button})
    | ftxui::border;
}

ftxui::Component TodosTui::TodoList() {
  return ftxui::Renderer([&] {
    std::vector<ftxui::Element> todo_item_texts;
    for (const auto &todo_item : todo_list_.GetTodoItems())
      todo_item_texts.emplace_back(ftxui::text(todo_item.GetTodoText()));

    return ftxui::vbox(todo_item_texts) | ftxui::border;
  });
}

} // namespace tui