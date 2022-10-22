//
// Created by Srijan Nayak on 22-10-2022.
//

#ifndef TODOS_TUI_SRC_ITODOMANAGER_H_
#define TODOS_TUI_SRC_ITODOMANAGER_H_

#include "TodoItem.h"

#include <vector>

namespace todos {

class ITodoManager {
public:
  virtual std::vector<TodoItem> GetTodos() = 0;
  virtual void AddTodo(TodoItem todo_item) = 0;
  virtual void RemoveTodo(TodoItem todo_item) = 0;
  virtual void ToggleTodoIsCompleted(TodoItem todo_item) = 0;
};

} // namespace todos

#endif // TODOS_TUI_SRC_ITODOMANAGER_H_
