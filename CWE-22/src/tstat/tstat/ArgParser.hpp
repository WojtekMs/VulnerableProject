#pragma once

#include <vector>
#include <string>

class ArgParser
{
    std::string command_{};
    std::vector<std::string> args_{};
   public:
    ArgParser() = delete;
    explicit ArgParser(const std::string& input);
    ArgParser(char*[], int);
    std::string getCommand() const noexcept;
    std::vector<std::string> getCommandArgs() const noexcept;
    std::string getArgsAsString() const noexcept;
};
