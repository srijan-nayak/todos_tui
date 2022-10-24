//
// Created by Srijan Nayak on 23-10-2022.
//

#include "TodoList.h"

#include "TodoItem.h"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

namespace todos {

int TodoList::_todo_item_id_counter = 0;

std::vector<TodoItem> TodoList::GetTodoItems() const { return _todo_items; }

void TodoList::AddNewTodoItem(std::string todo_text) {
  TodoItem new_todo_item{++_todo_item_id_counter, std::move(todo_text), false};
  _todo_items.emplace_back(new_todo_item);
}

void TodoList::RemoveTodoItem(int id) {
  _todo_items.erase(std::remove_if(_todo_items.begin(), _todo_items.end(),
                                   [&id](const TodoItem &todo_item) {
                                     return todo_item.GetId() == id;
                                   }),
                    _todo_items.end());

  if (_todo_items.empty())
    _todo_item_id_counter = 0;
}

void TodoList::ToggleTodoItemIsCompleted(int id) {
  auto found_todo_item = std::find_if(
      _todo_items.begin(), _todo_items.end(),
      [&id](const TodoItem &todo_item) { return todo_item.GetId() == id; });

  if (found_todo_item != _todo_items.end())
    found_todo_item->SetCompleted(!found_todo_item->IsCompleted());
}

} // namespace todos