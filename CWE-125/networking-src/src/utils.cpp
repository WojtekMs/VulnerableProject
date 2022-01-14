#include "networking/utils.hpp"

#include "networking/config.hpp"
#include "networking/EndConnection.hpp"

#include <cstring>
#include <stdexcept>
#include <sys/socket.h>
#include <errno.h>

#include <iostream>
#include <sstream>

namespace networking::utils
{
void send_str(const std::string& string, int socket_fd, int send_flags);
std::string receive_str(int socket_fd, int message_size, int recv_flags);

void log_error(const std::string& error_msg) noexcept
{
    perror(error_msg.data());
    exit(1);
}

std::string receive_string(int socket_fd, int recv_flags)
{
    auto message_header = receive_str(socket_fd, config::MESSAGE_HEADER_SIZE, recv_flags);
    auto message_size = to_<int>(message_header.c_str());
    auto message = receive_str(socket_fd, message_size, recv_flags);
    return message;
}

std::string receive_str(int socket_fd, int message_size, int recv_flags)
{
    int buffer_size = 256;
    char buffer[buffer_size];
    int total_bytes_received{};
    std::string message{};
    while (total_bytes_received < message_size) {
        std::memset(buffer, 0, buffer_size);
        auto bytes_received =
            recv(socket_fd, buffer, message_size - total_bytes_received, recv_flags);
        if (bytes_received == -1) {
            utils::log_error("ERROR on receiving data!");
        }
        if (bytes_received == 0) {
            shutdown(socket_fd, SHUT_RD);
            throw networking::EndConnection("Connection was closed!");
        }
        total_bytes_received += bytes_received;
        message += std::string(buffer, buffer + strlen(buffer));
    }
    return message;
}

void send_string(const std::string& string, int socket_fd, int send_flags)
{
    if (string.size() < 1) {
        throw std::invalid_argument(
            "Message you are trying to send is too short! Min size: 0");
    }
    if (string.size() > utils::max_message_size()) {
        throw std::invalid_argument(
            "Message you are trying to send is too long! Max size: " +
            std::to_string(utils::max_message_size()));
    }
    utils::send_str(utils::get_message_header(string.size() + 1), socket_fd, send_flags);
    utils::send_str(string, socket_fd, send_flags);
}

int max_message_size() noexcept
{
    std::string max_msg_value{};
    for (int i = 0; i < config::MESSAGE_HEADER_SIZE; ++i) {
        max_msg_value += '9';
    }
    return to_<int>(max_msg_value);
}

std::string get_message_header(int message_size)
{
    std::string header = std::to_string(message_size);
    int zero_padding = config::MESSAGE_HEADER_SIZE - (header.size() + 1);
    for (int i = 0; i < zero_padding; i++) {
        header.insert(header.begin(), '0');
    }
    return header;
}

void send_str(const std::string& string, int socket_fd, int send_flags)
{
    int total_bytes_sent{};
    std::string message{string};
    int message_size = message.size() + 1;
    while (total_bytes_sent < message_size) {
        auto bytes_sent =
            send(socket_fd, message.c_str(), message_size - total_bytes_sent, send_flags);
        if (bytes_sent == -1) {
            if (errno == EPIPE) {
                shutdown(socket_fd, SHUT_RDWR);
                throw networking::EndConnection("Connection was closed!");
            }
            utils::log_error("ERROR on sending data to the server!");
        }
        total_bytes_sent += bytes_sent;
        if (bytes_sent < message_size) {
            message.erase(
                message.begin(),
                std::min(std::next(message.begin(), bytes_sent), message.end()));
        }
    }
}

}  // namespace networking::utils
