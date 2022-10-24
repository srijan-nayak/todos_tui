//
// Created by Srijan Nayak on 22-10-2022.
//

#include "TodoItem.h"

#include <utility>

namespace todos {

TodoItem::TodoItem(int id, std::string todo_text, bool completed)
    : _id(id), _todo_text(std::move(todo_text)), _completed(completed) {}

int TodoItem::GetId() const { return _id; }
const std::string &TodoItem::GetTodoText() const { return _todo_text; }
bool TodoItem::IsCompleted() const { return _completed; }

void TodoItem::SetCompleted(bool completed) { _completed = completed; }

} // namespace todos
