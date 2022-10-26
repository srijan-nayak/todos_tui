//
// Created by Srijan Nayak on 26-10-2022.
//

#ifndef TODOS_TUI_SRC_TUI_TODOSTUI_H_
#define TODOS_TUI_SRC_TUI_TODOSTUI_H_

#include "../todos/TodoList.h"

namespace tui {

class TodosTui {
 public:
  explicit TodosTui(todos::TodoList &todo_list);

  void StartLoop();

 private:
  todos::TodoList &_todo_list;
};

} // tui

#endif //TODOS_TUI_SRC_TUI_TODOSTUI_H_
