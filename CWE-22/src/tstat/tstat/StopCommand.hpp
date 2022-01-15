#pragma once

#include "tstat/ICommand.hpp"

#include <memory>
#include <vector>

class TimeCounter;

namespace networking
{
class IServer;
}

class StopCommand : public ICommand
{
    TimeCounter& counter_;
    networking::IServer& server_;

   public:
    StopCommand() = delete;
    StopCommand(TimeCounter& tc, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeStopCommand(TimeCounter& tc,
                                          networking::IServer& server,
                                          const std::vector<std::string>& = {}) noexcept;
