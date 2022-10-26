#include "todos/TodoList.h"
#include "todos/TodoListFileManager.h"
#include "tui/TodosTui.h"

int main() {
  todos::TodoList todo_list{todos::TodoListFileManager::ReadTodoItems()};
  tui::TodosTui todos_tui{todo_list};
  todos_tui.StartLoop();
  todos::TodoListFileManager::WriteTodoItems(todo_list.GetTodoItems());
}