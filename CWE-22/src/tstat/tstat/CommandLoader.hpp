#pragma once

#include "tstat/AbortCommand.hpp"
#include "tstat/ShowCommand.hpp"
#include "tstat/StartCommand.hpp"
#include "tstat/StopCommand.hpp"
#include "tstat/ListCommand.hpp"
#include "tstat/config.hpp"

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

class TimeCounter;
class ICommand;

namespace networking
{
class IServer;
}

class CommandLoader
{
    TimeCounter& counter_;
    networking::IServer& server_;
    std::vector<std::string> args_{};
    std::unordered_map<
        std::string,
        std::function<std::shared_ptr<ICommand>(TimeCounter&,
                                                networking::IServer&,
                                                const std::vector<std::string>&)>>
        commands_{std::make_pair(config::START_COMMAND, makeStartCommand),
                  std::make_pair(config::STOP_COMMAND, makeStopCommand),
                  std::make_pair(config::ABORT_COMMAND, makeAbortCommand),
                  std::make_pair(config::LIST_COMMAND, makeListCommand),
                  std::make_pair(config::SHOW_COMMAND, makeShowCommand)};

   public:
    CommandLoader() = delete;
    CommandLoader(TimeCounter&, networking::IServer&, const std::vector<std::string>&);
    std::shared_ptr<ICommand> getCommand(const std::string& command) const;
};
