#pragma once

#include "tstat/ICommand.hpp"

#include <memory>
#include <string>
#include <vector>

class TimeCounter;

namespace networking
{
class IServer;
}
class ShowCommand : public ICommand
{
    TimeCounter& counter_;
    networking::IServer& server_;

   public:
    ShowCommand(TimeCounter& tc, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeShowCommand(TimeCounter& tc,
                                          networking::IServer& server,
                                          const std::vector<std::string>& = {}) noexcept;
