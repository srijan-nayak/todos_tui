//
// Created by Srijan Nayak on 23-10-2022.
//

#include "TodoList.h"

namespace todos {

std::vector<TodoItem> TodoList::GetTodoItems() const { return _todo_items; }

void TodoList::AddNewTodoItem(std::string todo_text) {}

void TodoList::RemoveTodoItem(int id) {}

void TodoList::ToggleTodoItemIsComplete(int id) {}

} // namespace todos