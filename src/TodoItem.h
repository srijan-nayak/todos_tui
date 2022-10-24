//
// Created by Srijan Nayak on 22-10-2022.
//

#ifndef TODOS_TUI_SRC_TODOITEM_H_
#define TODOS_TUI_SRC_TODOITEM_H_

#include <string>

namespace todos {

class TodoItem {
public:
  TodoItem(int id, std::string todo_text, bool completed);

  [[nodiscard]] int GetId() const;
  [[nodiscard]] const std::string &GetTodoText() const;
  [[nodiscard]] bool IsCompleted() const;

  void SetCompleted(bool completed);

private:
  int _id;
  std::string _todo_text;
  bool _completed;
};

} // namespace todos

#endif // TODOS_TUI_SRC_TODOITEM_H_
