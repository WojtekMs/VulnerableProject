#include "tstat/CommandLoader.hpp"

#include "networking/IServer.hpp"
#include "tstat/TimeCounter.hpp"
#include <stdexcept>
#include <iostream>

CommandLoader::CommandLoader(TimeCounter& tc,
                             networking::IServer& server,
                             const std::vector<std::string>& args) :
  counter_(tc),
  server_(server),
  args_(args)
{
}

std::shared_ptr<ICommand> CommandLoader::getCommand(const std::string& command) const
{
  try {
    return commands_.at(command)(counter_, server_, args_);
  }
  catch (std::out_of_range& e) {
    std::cerr << e.what() << '\n';
    std::cerr << "Please remember to add all commands to CommandLoader command map!\n";
    exit(0);
  }
}
