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

class StartCommand : public ICommand
{
    TimeCounter& time_counter_;
    networking::IServer& server_;
    std::string task_name_{};

   public:
    StartCommand(TimeCounter& time_counter,
                 networking::IServer& server,
                 const std::vector<std::string>& args);
    void execute() override;
};

std::shared_ptr<ICommand> makeStartCommand(TimeCounter& tc,
                                           networking::IServer& server,
                                           const std::vector<std::string>&);
