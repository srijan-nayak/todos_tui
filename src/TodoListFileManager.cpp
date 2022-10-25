//
// Created by Srijan Nayak on 25-10-2022.
//

#include "TodoListFileManager.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace todos {

std::filesystem::path TodoListFileManager::_data_directory =
    std::filesystem::current_path() / "data";
std::filesystem::path TodoListFileManager::_file =
    _data_directory / "todos.txt";

std::vector<TodoItem> TodoListFileManager::ReadTodoItems() { return {}; }

void TodoListFileManager::WriteTodoItems(
    const std::vector<TodoItem> &todo_items) {
  if (!std::filesystem::exists(_data_directory))
    std::filesystem::create_directory(_data_directory);

  std::ofstream todo_file_stream{_file};
  for (const auto &todo_item : todo_items) {
    std::string todo_text = todo_item.GetTodoText();
    std::replace(todo_text.begin(), todo_text.end(), ' ', '_');
    todo_file_stream << todo_item.GetId() << " " << todo_text << " "
                     << todo_item.IsCompleted() << std::endl;
  }
}

} // namespace todos