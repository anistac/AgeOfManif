
#include "Command.hpp"
#include "Interactable.hpp"
#include <memory>

#ifndef ACTION_TYPE_HPP
#define ACTION_TYPE_HPP
typedef struct Action {
  Interactable *initiator1;
  Interactable *initiator2;
  std::shared_ptr<Command> cmd;
  Action(Interactable *init1, Interactable *init2, std::shared_ptr<Command> command) : initiator1(init1), initiator2(init2), cmd(command) {};
} Action;

#endif // !ACTION_


