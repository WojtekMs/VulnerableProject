#pragma once

#include <exception>
#include <string>

class CommandError : public std::exception
{
    std::string msg_{};

   public:
    CommandError() = delete;
    CommandError(const std::string& msg) : msg_(msg) {}
    const char* what() const noexcept override { return msg_.c_str(); }
};
