#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP
#include "Command.hpp"
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

struct CmdTypeHash {
  template <typename I1, typename I2>
  std::size_t operator()(const std::pair<I1,I2> &initiators) const {
    auto h1 = std::type_index(initiators.first).hash_code();
    auto h2 = std::type_index(initiators.second).hash_code();
    return h1 ^ h2;
  }
};


struct CmdTypeEq {
  template <typename I1, typename I2>
  bool operator()(const std::pair<I1, I2> &initiator1, const std::pair<I1, I2> &initiator2) const {
    return (initiator1.first == initiator2.first && initiator1.second == initiator2.second || initiator1.first == initiator2.second && initiator1.second == initiator2.first);
  }
};

class CommandRegistry {

public:
  template <typename I1, typename I2>
   static void addCmd(Command *cmd) {
    std::type_index t1 = typeid(I1);
    std::type_index t2 = typeid(I2);

    _commands[std::make_pair(t1, t2)] = cmd;
  }
  template <typename I1, typename I2>
   static Command* findAvailableCmds(const I1 init1, const I2 init2) {
    auto it = _commands.find(std::make_pair(std::type_index(init1), std::type_index(init2)));
    if (it != _commands.end()) {
      return it->second;
    } else {
      throw std::runtime_error("Command not found");
    }
  }

private:
  static inline std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;
};

#endif // !COMMAND_REGISTRY_HPP
