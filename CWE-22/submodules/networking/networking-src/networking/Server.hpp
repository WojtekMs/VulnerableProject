#pragma once
#include "IServer.hpp"

#include <netinet/in.h>
#include <string>
namespace networking
{
/**
 * @brief Server class, wrapper for TCP/IP Server/Client communication
 * we have to state IP_Address of the server (??however it is localhost??)
 * we have to state port number on which the application will be running
 * this can be verified by running `netstat -tulpn` when server is accepting connections
 *
 * This class creates a socket bound to given ip address and port number,
 * you can activate accepting connections, then server will be actively waiting for
 * clients after the connection is started you can send or receive character data from
 * client
 */
class Server : public IServer
{
    std::string ip_address_{};
    uint16_t port_number_{};
    int server_socket_fd_{-1};
    int client_socket_fd_{-1};
    struct sockaddr_in server_address_ {
    };
    struct sockaddr_in client_address_ {
    };

   public:
    Server() = delete;
    Server(const std::string& ip_address, uint16_t port_number);
    Server(const Server&) = delete;
    Server(Server&&) = delete;
    Server& operator=(const Server&) = delete;
    Server& operator=(Server&&) = delete;
    ~Server() noexcept override;

    /**
     * @brief server is waiting for clients; this call is blocking;
     * 
     */
    void accept_connections() override;

    /**
     * @brief server sends char data to client; this call is blocking;
     * throws std::logic_error;
     * throws std::invalid_argument;
     * 
     * @param data 
     */
    void send_data(const std::string& data) const override;

    /**
     * @brief server receives char data from the client; this call is blocking;
     * throws std::logic_error;
     * throws networking::EndConnection
     * 
     * @return std::string 
     */
    std::string receive_data() const override;
};

}  // namespace networking
