#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdexcept>
namespace utils
{
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

std::string getElapsedTime(const TimePoint& stop, const TimePoint& start) noexcept;
std::string getCurrentDate() noexcept;
std::vector<std::string> parseArgs(const std::string&) noexcept;

template <typename ...T>
std::string join(char sign, T&&... args) noexcept {
    std::string joined_str = ((std::string(args) + sign) + ...);
    try {
        joined_str.erase(std::prev(joined_str.end()));
    }
    catch (std::out_of_range&) {

    }
    return joined_str;
}

template < template <typename T> typename Container >
bool contains(const Container<std::string>& container, const std::string& input) noexcept {
    return std::find(std::begin(container), std::end(container), input) != std::end(container);
}


}  // namespace utils
