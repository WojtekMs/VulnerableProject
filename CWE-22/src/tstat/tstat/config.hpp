#pragma once
#include <vector>
#include <string>

namespace config{

constexpr char START_COMMAND[] = "start";
constexpr char STOP_COMMAND[] = "stop";
constexpr char ABORT_COMMAND[] = "abort";
constexpr char SHOW_COMMAND[] = "show";
constexpr char LIST_COMMAND[] = "list";
constexpr char log_save_path[] = "/home/wojtek/networking/tstat/data";

const std::vector<std::string> UNARY_COMMANDS = {STOP_COMMAND, ABORT_COMMAND, SHOW_COMMAND, LIST_COMMAND};
const std::vector<std::string> BINARY_COMMANDS = {START_COMMAND};
const std::vector<std::string> COMMANDS = [](){
    std::vector<std::string> commands{};
    for (const auto& unary_comm : UNARY_COMMANDS) {
        commands.push_back(unary_comm);
    }
    for (const auto& binary_comm : BINARY_COMMANDS) {
        commands.push_back(binary_comm);
    }
    return commands;
}();
// const std::vector<std::string> COMMANDS = {START_COMMAND, STOP_COMMAND, ABORT_COMMAND, SHOW_COMMAND, LIST_COMMAND};
}
