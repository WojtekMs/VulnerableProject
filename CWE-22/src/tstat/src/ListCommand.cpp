#include "tstat/ListCommand.hpp"

#include "networking/IServer.hpp"
#include "tstat/TimeCounter.hpp"
#include "tstat/config.hpp"
#include "tstat/CommandError.hpp"
#include "tstat/utils.hpp"

#include <filesystem>
#include <sstream>

ListCommand::ListCommand(TimeCounter& tc, networking::IServer& server) :
  counter_(tc),
  server_(server)
{
}

//check if log_save_path even exists!
void ListCommand::execute()
{
    if (!std::filesystem::exists(config::log_save_path)) {
        throw CommandError(utils::join(' ', "directory", config::log_save_path, "doesn't exist!"));
    }
    std::stringstream stream{};
    stream << config::log_save_path << ":\n";
    for (const auto& entry : std::filesystem::directory_iterator(config::log_save_path)) {
        stream << "- " << entry.path().filename() << '\n';
    }
    server_.send_data(stream.str());
}

std::shared_ptr<ICommand> makeListCommand(TimeCounter& tc,
                                          networking::IServer& server,
                                          const std::vector<std::string>&) noexcept
{
    return std::make_shared<ListCommand>(tc, server);
}
