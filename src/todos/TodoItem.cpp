//
// Created by Srijan Nayak on 22-10-2022.
//

#include "TodoItem.h"

#include <utility>

namespace todos {

TodoItem::TodoItem(int id, std::string todo_text, bool completed)
  : id_(id), todo_text_(std::move(todo_text)), completed_(completed) {}

int TodoItem::GetId() const { return id_; }
const std::string &TodoItem::GetTodoText() const { return todo_text_; }
bool TodoItem::IsCompleted() const { return completed_; }

void TodoItem::SetCompleted(bool completed) { completed_ = completed; }

} // namespace todos
