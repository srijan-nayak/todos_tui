//
// Created by Srijan Nayak on 26-10-2022.
//

#ifndef TODOS_TUI_SRC_TUI_TODOSTUI_H_
#define TODOS_TUI_SRC_TUI_TODOSTUI_H_

#include "../todos/TodoList.h"
#include "../todos/TodoItem.h"

#include <ftxui/component/component.hpp>

namespace tui {

class TodosTui {
 public:
  explicit TodosTui(todos::TodoList &todo_list);

  void StartLoop();

 private:
  todos::TodoList &todo_list_;
  std::string new_todo_text_;
  ftxui::Component todo_list_component_ = ftxui::Container::Vertical({});

  ftxui::Component NewTodoForm();
  ftxui::Component TodoItemComponent(const todos::TodoItem &todo_item);

  void ReloadTodoListComponent();
};

} // namespace tui

#endif //TODOS_TUI_SRC_TUI_TODOSTUI_H_
