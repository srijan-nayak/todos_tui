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

int TodoList::todo_item_id_counter_ = 0;

TodoList::TodoList(std::vector<TodoItem> todo_items)
  : todo_items_(std::move(todo_items)) {
  for (const auto &todo_item : todo_items_) {
    int todo_item_id = todo_item.GetId();
    if (todo_item_id > todo_item_id_counter_)
      todo_item_id_counter_ = todo_item_id;
  }
}

std::vector<TodoItem> TodoList::GetTodoItems() const { return todo_items_; }

void TodoList::AddNewTodoItem(std::string todo_text) {
  TodoItem new_todo_item{++todo_item_id_counter_, std::move(todo_text), false};
  todo_items_.emplace_back(new_todo_item);
}

void TodoList::RemoveTodoItem(int id) {
  todo_items_.erase(std::remove_if(todo_items_.begin(), todo_items_.end(),
                                   [&id](const TodoItem &todo_item) {
                                     return todo_item.GetId() == id;
                                   }),
                    todo_items_.end());

  if (todo_items_.empty())
    todo_item_id_counter_ = 0;
}

void TodoList::ToggleTodoItemIsCompleted(int id) {
  auto found_todo_item = std::find_if(
    todo_items_.begin(), todo_items_.end(),
    [&id](const TodoItem &todo_item) { return todo_item.GetId() == id; });

  if (found_todo_item != todo_items_.end())
    found_todo_item->SetCompleted(!found_todo_item->IsCompleted());
}

} // namespace todos