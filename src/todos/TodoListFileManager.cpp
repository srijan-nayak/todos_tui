//
// Created by Srijan Nayak on 25-10-2022.
//

#include "TodoListFileManager.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace todos {

std::filesystem::path TodoListFileManager::data_directory_ =
    std::filesystem::current_path() / "data";
std::filesystem::path TodoListFileManager::file_ =
    data_directory_ / "todos.txt";

std::vector<TodoItem> TodoListFileManager::ReadTodoItems() {
  std::ifstream todo_file_stream{file_};

  if (!todo_file_stream.is_open())
    return {};

  std::vector<TodoItem> todo_items;
  std::string line;
  int id;
  std::string todo_text;
  bool completed;

  while (std::getline(todo_file_stream, line)) {
    std::istringstream line_stream{line};
    line_stream >> id >> todo_text >> completed;
    std::replace(todo_text.begin(), todo_text.end(), '_', ' ');
    todo_items.emplace_back(TodoItem{id, todo_text, completed});
  }
  return todo_items;
}

void TodoListFileManager::WriteTodoItems(
    const std::vector<TodoItem> &todo_items) {
  if (!std::filesystem::exists(data_directory_))
    std::filesystem::create_directory(data_directory_);

  std::ofstream todo_file_stream{file_};
  for (const auto &todo_item : todo_items) {
    std::string todo_text = todo_item.GetTodoText();
    std::replace(todo_text.begin(), todo_text.end(), ' ', '_');
    todo_file_stream << todo_item.GetId() << " " << todo_text << " "
                     << todo_item.IsCompleted() << std::endl;
  }
}

} // namespace todos