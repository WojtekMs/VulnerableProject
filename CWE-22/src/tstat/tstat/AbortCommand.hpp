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
class AbortCommand : public ICommand
{
    TimeCounter& time_counter_;
    networking::IServer& server_;

   public:
    AbortCommand(TimeCounter& time_counter, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeAbortCommand(TimeCounter& tc,
                                           networking::IServer& server,
                                           const std::vector<std::string>& = {});
