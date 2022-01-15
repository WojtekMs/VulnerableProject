#include "tstat/utils.hpp"

#include <chrono>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
namespace utils
{

std::vector<std::string> parseArgs(const std::string& data) noexcept
{
    std::stringstream stream{};
    stream.str(data);
    std::vector<std::string> args{};
    std::copy(std::istream_iterator<std::string>(stream),
              std::istream_iterator<std::string>{},
              std::back_inserter(args));
    return args;
}

std::string getElapsedTime(const TimePoint& stop, const TimePoint& start) noexcept
{
    std::stringstream stream{};
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
    auto minutes = seconds / 60;
    auto hours = minutes / 60;
    seconds %= 60;
    minutes %= 60;
    if (hours < 10) {
        stream << 0;
    }
    stream << hours << ":";
    if (minutes < 10) {
        stream << 0;
    }
    stream << minutes << ":";
    if (seconds < 10) {
        stream << 0;
    }
    stream << seconds;
    return stream.str();
}

std::string getCurrentDate() noexcept {
    std::stringstream stream{};
    auto time = std::time(nullptr);
    stream << std::put_time(std::localtime(&time), "%d_%m_%Y");
    return stream.str();
}

}  // namespace utils
