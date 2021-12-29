#pragma once

#include <exception>
#include <string>

namespace networking
{
/**
 * @brief EndConnection error class, is supposed to be thrown when the connection is
 * ended;
 *
 */
class EndConnection : public std::exception
{
    std::string error_msg_{};

   public:
    EndConnection() = delete;
    explicit EndConnection(const std::string& msg) : error_msg_(msg) {}
    const char* what() const noexcept override { return error_msg_.c_str(); }
};

}  // namespace networking
