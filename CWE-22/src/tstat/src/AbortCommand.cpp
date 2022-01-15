#include "tstat/AbortCommand.hpp"

#include "networking/IServer.hpp"
#include "tstat/TimeCounter.hpp"

#include <sstream>

AbortCommand::AbortCommand(TimeCounter& time_counter, networking::IServer& server) :
  time_counter_(time_counter),
  server_(server)
{
}

void AbortCommand::execute()
{
  try {
    time_counter_.abort();
    server_.send_data(time_counter_.getCurrentStateInfo());
  }
  catch (std::logic_error& e) {
    server_.send_data(e.what());
  }
}

std::shared_ptr<ICommand> makeAbortCommand(TimeCounter& tc, networking::IServer& server, const std::vector<std::string>&) {
    return std::make_shared<AbortCommand>(tc, server);
}
