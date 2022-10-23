//
// Created by Srijan Nayak on 23-10-2022.
//

#include "TodoList.h"

#include "TodoItem.h"

#include <string>
#include <vector>
#include <utility>

namespace todos {

std::vector<TodoItem> TodoList::GetTodoItems() const { return _todo_items; }

void TodoList::AddNewTodoItem(std::string todo_text) {
  TodoItem new_todo_item{++_todo_item_id_counter, std::move(todo_text), false};
  _todo_items.emplace_back(new_todo_item);
}

void TodoList::RemoveTodoItem(int id) {}

void TodoList::ToggleTodoItemIsComplete(int id) {}

} // namespace todos