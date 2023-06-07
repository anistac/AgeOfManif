#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP
#include "Command.hpp"
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include <vector>

struct CmdTypeHash {
  template <typename I1, typename I2>
  std::size_t operator()(const std::pair<I1, I2> &initiators) const {
    auto h1 = initiators.first.hash_code();
    auto h2 = initiators.second.hash_code();
    return h1 ^ h2;
  }
};

struct CmdTypeEq {
  template <typename I1, typename I2>
  bool operator()(const std::pair<I1, I2> &initiator1,
                  const std::pair<I1, I2> &initiator2) const {
    return (initiator1.first == initiator2.first &&
                initiator1.second == initiator2.second ||
            initiator1.first == initiator2.second &&
                initiator1.second == initiator2.first);
  }
};

class CommandRegistry {

public:
  static void clear() {
    // iterate over all commands and delete them
    for (auto it = _commands.begin(); it != _commands.end(); ++it) {
      it->second.reset();
    }
    _commands.clear();
  }

  // Overload for two initiators
  template <typename I1, typename I2>
  static void addCmd(std::shared_ptr<Command> cmd) {
    std::type_index t1 = typeid(I1);
    std::type_index t2 = typeid(I2);
    _commands.insert(std::make_pair(std::make_pair(t1, t2), cmd));
  }

  // Overload for one initiator
  template <typename I1> static void addCmd(std::shared_ptr<Command> cmd) {
    std::type_index t1 = typeid(I1);
    _commands.insert(
        std::make_pair(std::make_pair(t1, std::type_index(typeid(void))), cmd));
  }

  // Overload for finding commands with two initiators
  template <typename I1, typename I2>
  static std::vector<std::shared_ptr<Command>>
  findAvailableCmds(const I1 init1, const I2 init2) {
    std::type_index t1 = typeid(*init1);
    std::type_index t2 = typeid(*init2);
    return findCmdsWithInitiators(t1, t2);
  }

  // Overload for finding commands with one initiator
  template <typename I1>
  static std::vector<std::shared_ptr<Command>>
  findAvailableCmds(const I1 init1) {
    std::type_index t1 = typeid(*init1);
    return findCmdsWithInitiators(t1, std::type_index(typeid(void)));
  }

  // Helper function to find commands with initiators
  static std::vector<std::shared_ptr<Command>>
  findCmdsWithInitiators(std::type_index t1, std::type_index t2) {
    std::vector<std::shared_ptr<Command>> cmds;
    auto range = _commands.equal_range(std::make_pair(t1, t2));
    for (auto it = range.first; it != range.second; ++it) {
      cmds.push_back(it->second);
    }
    if (cmds.size() == 0) {
      std::cout << "Command not found" << std::endl;
    }
    return cmds;
  }
  static std::vector<std::shared_ptr<Command>> getCmds() {
    std::vector<std::shared_ptr<Command>> cmds;
    for (auto &cmd : _commands) {
      std::cout << cmd.second->getName() << std::endl;
      cmds.push_back(cmd.second);
    }
    return cmds;
  }
private:
  inline static std::unordered_multimap<
      std::pair<std::type_index, std::type_index>, std::shared_ptr<Command>,
      CmdTypeHash, CmdTypeEq>
      _commands;
};

extern CommandRegistry cmdRegistry;

#endif // !COMMAND_REGISTRY_HPP
