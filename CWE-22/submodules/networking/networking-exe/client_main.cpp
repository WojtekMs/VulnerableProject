#include "networking/Client.hpp"
#include "networking/config.hpp"
#include "networking/EndConnection.hpp"

#include <iostream>


int main(int, char*[])
{
    networking::Client client(networking::config::SERVER_IP_ADDR,
                              networking::config::SERVER_PORT);
    std::string input(320, '-');
    client.send_data(input);
    while (true) {
        std::getline(std::cin, input);
        try {
            client.send_data(input);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
            continue;
        }
        catch (const networking::EndConnection& e) {
            std::cerr << e.what() << '\n';
            break;
        }
    }
}
