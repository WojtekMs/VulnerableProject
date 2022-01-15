#include "networking/Server.hpp"

#include "networking/config.hpp"
#include "networking/utils.hpp"

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <poll.h>
#include <stdexcept>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>

namespace networking
{
Server::Server(const std::string& ip_address, uint16_t port_number) :
  ip_address_(ip_address),
  port_number_(port_number)
{
    if (networking::config::VERBOSE) {
        std::cout << "Starting server on IP: " << ip_address << ", port: " << port_number
                  << '\n';
    }
    // create a socket
    server_socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd_ < 0) {
        utils::log_error("ERROR opening socket");
    }

    /* setup the host_address (server address) structure for use in bind call */
    // clear address structure
    std::memset(reinterpret_cast<char*>(&server_address_), 0, sizeof(server_address_));
    // server byte order (internet socket -> TCP/IP or UDP)
    server_address_.sin_family = AF_INET;
    // integer value for port must be converted into network byte order which is unified
    server_address_.sin_port = htons(port_number_);
    // fill in ip address to the server address structure
    if (inet_aton(ip_address_.data(), &server_address_.sin_addr) == 0) {
        utils::log_error("Wrong IP Addres: " + ip_address_);
    }

    // This bind() call will bind the socket to the current IP address on port, portno
    if (bind(server_socket_fd_,
             reinterpret_cast<struct sockaddr*>(&server_address_),
             sizeof(server_address_)) < 0) {
        utils::log_error("ERROR on binding");
    }

    int queue_size = 5;
    if (listen(server_socket_fd_, queue_size) == -1) {
        utils::log_error("ERROR on listening");
    }
}

void Server::accept_connections()
{
    socklen_t client_socket_size{sizeof(client_address_)};
    client_socket_fd_ = accept(server_socket_fd_,
                               (struct sockaddr*)&client_address_,
                               &client_socket_size);
    if (client_socket_fd_ < 0) {
        utils::log_error("ERROR on accept");
    }
    if (networking::config::VERBOSE) {
        std::cout << "Server: received connection from "
                  << inet_ntoa(client_address_.sin_addr) << " port "
                  << ntohs(client_address_.sin_port) << '\n';
    }
}

void Server::send_data(const std::string& data) const
{
    if (client_socket_fd_ < 0) {
        throw std::logic_error(
            "Client socket is not valid, make sure you accepted connection first!\n");
    }
    utils::send_string(data, client_socket_fd_, MSG_NOSIGNAL);
}

std::string Server::receive_data() const
{
    if (client_socket_fd_ < 0) {
        throw std::logic_error(
            "Client socket is not valid, make sure you accepted connection first!\n");
    }
    return utils::receive_string(client_socket_fd_);
}

Server::~Server() noexcept
{
    close(server_socket_fd_);
    close(client_socket_fd_);
}
}  // namespace networking
