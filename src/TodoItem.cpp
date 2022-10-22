//
// Created by Srijan Nayak on 22-10-2022.
//

#include "TodoItem.h"

#include <utility>

namespace todos {

TodoItem::TodoItem(int id, std::string todo_text, bool is_completed)
    : _id(id), _todo_text(std::move(todo_text)), _is_completed(is_completed) {}

int TodoItem::GetId() const { return _id; }
const std::string &TodoItem::GetTodoText() const { return _todo_text; }
bool TodoItem::IsIsCompleted() const { return _is_completed; }

void TodoItem::SetIsCompleted(bool is_completed) {
  _is_completed = is_completed;
}

} // namespace todos
