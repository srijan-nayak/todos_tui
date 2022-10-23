//
// Created by Srijan Nayak on 22-10-2022.
//

#ifndef TODOS_TUI_SRC_TODOITEM_H_
#define TODOS_TUI_SRC_TODOITEM_H_

#include <string>

namespace todos {

class TodoItem {
private:
  int _id;
  std::string _todo_text;
  bool _is_completed;

public:
  TodoItem(int id, std::string todo_text, bool is_completed);

  [[nodiscard]] int GetId() const;
  [[nodiscard]] const std::string &GetTodoText() const;
  [[nodiscard]] bool IsIsCompleted() const;

  void SetIsCompleted(bool is_completed);
};

} // namespace todos

#endif // TODOS_TUI_SRC_TODOITEM_H_
