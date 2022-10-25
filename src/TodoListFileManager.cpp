//
// Created by Srijan Nayak on 25-10-2022.
//

#include "TodoListFileManager.h"

#include <filesystem>

namespace todos {

std::filesystem::path TodoListFileManager::_data_directory =
    std::filesystem::current_path() / "data";
std::filesystem::path TodoListFileManager::_file =
    _data_directory / "todos.txt";

std::vector<TodoItem> TodoListFileManager::ReadTodoItems() { return {}; }

void TodoListFileManager::WriteTodoItems(std::vector<TodoItem> todo_items) {}

} // namespace todos