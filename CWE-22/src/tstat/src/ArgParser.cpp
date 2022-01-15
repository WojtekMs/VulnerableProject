#include "tstat/ArgParser.hpp"

#include "tstat/utils.hpp"
#include "tstat/config.hpp"
#include <stdexcept>
#include <sstream>

ArgParser::ArgParser(const std::string& input) {
    auto args = utils::parseArgs(input);
    if (args.empty()) {
        throw std::logic_error("At least one argument is necessary!");
    }
    if (!utils::contains(config::COMMANDS, args[0])) {
        throw std::invalid_argument("First argument must be command!");
    }
    command_ = args[0];
    if (args.size() > 1u) {
        args_ = std::vector<std::string>(std::next(args.begin()), args.end());
    }
}

ArgParser::ArgParser(char* argv[], int argc) {
    if (argc == 1) {
        throw std::logic_error("At least one argument is necessary!");
    }
    if (!utils::contains(config::COMMANDS, argv[1])) {
        throw std::invalid_argument("First argument must be command!");
    }
    command_ = argv[1];
    for (int i = 2; i < argc; ++i) {
        args_.push_back(argv[i]);
    }
}

std::vector<std::string> ArgParser::getCommandArgs() const noexcept {
    return args_;
}

std::string ArgParser::getCommand() const noexcept {
    return command_;
}

std::string ArgParser::getArgsAsString() const noexcept {
    std::stringstream stream{};
    stream << command_ << " ";
    for (const auto& arg: args_) {
        stream << arg << " ";
    }
    return stream.str();
}
