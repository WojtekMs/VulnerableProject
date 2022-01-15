#include "networking/Client.hpp"
#include "networking/EndConnection.hpp"
#include "networking/config.hpp"
#include "tstat/ArgParser.hpp"
#include "tstat/TimeCounter.hpp"

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

void getCommandFromCin()
{
    networking::Client client(networking::config::SERVER_IP_ADDR,
                              networking::config::SERVER_PORT);
    while (true) {
        try {
            std::string input{};
            std::getline(std::cin, input);
            ArgParser args(input);
            client.send_data(args.getArgsAsString());
            std::cout << client.receive_data() << '\n';

        } catch (const networking::EndConnection& e) {
            std::cerr << e.what() << '\n';
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
            continue;
        }
        catch (const std::logic_error& e) {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
}

void getCommandFromCLI(int argc, char* argv[]) {
    networking::Client client(networking::config::SERVER_IP_ADDR,
                              networking::config::SERVER_PORT);
    try {
        ArgParser args(argv, argc);
        client.send_data(args.getArgsAsString());
        std::cout << client.receive_data() << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
        return;
    }
    catch (const std::logic_error& e) {
        std::cerr << e.what() << '\n';
        return;
    }
    catch (const networking::EndConnection& e) {
        std::cerr << e.what() << '\n';
        return;
    }

}

int main(int argc, char* argv[])
{
    // getCommandFromCin();
    getCommandFromCLI(argc, argv);
}
