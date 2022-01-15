#include "tstat/ShowCommand.hpp"

#include "networking/IServer.hpp"
#include "tstat/TimeCounter.hpp"

ShowCommand::ShowCommand(TimeCounter& tc, networking::IServer& server) :
  counter_(tc),
  server_(server)
{
}

void ShowCommand::execute()
{
    server_.send_data(counter_.getCurrentStateInfo());
}

std::shared_ptr<ICommand> makeShowCommand(TimeCounter& tc,
                                          networking::IServer& server,
                                          const std::vector<std::string>&) noexcept
{
    return std::make_shared<ShowCommand>(tc, server);
}
