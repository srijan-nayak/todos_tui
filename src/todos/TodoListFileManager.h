//
// Created by Srijan Nayak on 25-10-2022.
//

#ifndef TODOS_TUI_SRC_TODOLISTFILEMANAGER_H_
#define TODOS_TUI_SRC_TODOLISTFILEMANAGER_H_

#include "TodoItem.h"

#include <filesystem>
#include <vector>

namespace todos {

class TodoListFileManager {
public:
  static std::vector<TodoItem> ReadTodoItems();
  static void WriteTodoItems(const std::vector<TodoItem> &todo_items);

private:
  static std::filesystem::path data_directory_;
  static std::filesystem::path file_;
};

} // namespace todos

#endif // TODOS_TUI_SRC_TODOLISTFILEMANAGER_H_
