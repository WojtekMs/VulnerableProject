#include "tstat/StopCommand.hpp"

#include "networking/IServer.hpp"
#include "tstat/TimeCounter.hpp"

#include <sstream>

StopCommand::StopCommand(TimeCounter& tc, networking::IServer& server) :
  counter_(tc),
  server_(server)
{
}

void StopCommand::execute()
{
    try {
        std::stringstream stream{};
        counter_.stop();
        stream << counter_.getCurrentStateInfo() << '\n';
        stream << "Saved to file: " << counter_.getFilePath() << '\n';
        counter_.save();
        server_.send_data(stream.str());
    } catch (std::logic_error& e) {
        server_.send_data(e.what());
        return;
    }
}

std::shared_ptr<ICommand> makeStopCommand(TimeCounter& tc,
                                          networking::IServer& server,
                                          const std::vector<std::string>&) noexcept
{
    return std::make_shared<StopCommand>(tc, server);
}
