#include "networking/Server.hpp"
#include "networking/config.hpp"
#include "networking/EndConnection.hpp"

#include <algorithm>
#include <iostream>

int main()
{
    networking::Server server(networking::config::SERVER_IP_ADDR,
                              networking::config::SERVER_PORT);
    server.accept_connections();
    while (true) {
        try {
            auto data = server.receive_data();
            std::cout << data << '\n';
            std::cout << "size: " << data.size() << '\n';
        }
        catch (const networking::EndConnection& e) {
            std::cerr << e.what() << '\n';
            break;
        }
    }
}
