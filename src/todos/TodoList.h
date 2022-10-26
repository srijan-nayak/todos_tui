//
// Created by Srijan Nayak on 23-10-2022.
//

#ifndef TODOS_TUI_SRC_TODOLIST_H_
#define TODOS_TUI_SRC_TODOLIST_H_

#include "TodoItem.h"

#include <string>
#include <vector>

namespace todos {

class TodoList {
public:
  explicit TodoList(std::vector<TodoItem> todo_items);

  [[nodiscard]] std::vector<TodoItem> GetTodoItems() const;
  void AddNewTodoItem(std::string todo_text);
  void RemoveTodoItem(int id);
  void ToggleTodoItemIsCompleted(int id);

private:
  std::vector<TodoItem> todo_items_;
  static int todo_item_id_counter_;
};

} // namespace todos

#endif // TODOS_TUI_SRC_TODOLIST_H_
