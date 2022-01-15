#include "tstat/StoppedState.hpp"

#include "tstat/IdleState.hpp"
#include "tstat/TimeCounter.hpp"
#include "tstat/config.hpp"
#include "tstat/utils.hpp"

#include <filesystem>
#include <fstream>

StoppedState::StoppedState(TimeCounter& counter) : counter_(counter) {}

void StoppedState::start(const std::string&)
{
    return;
}

void StoppedState::stop()
{
    return;
}

void StoppedState::save()
{
    auto file_path = getFilePath();
    auto task_directory = utils::join('/', config::log_save_path, counter_.task_name_);
    if (!std::filesystem::exists(task_directory)) {
        std::filesystem::create_directories(task_directory);
    }
    std::ios_base::openmode file_flags{};
    if (std::filesystem::exists(file_path)) {
        file_flags = std::ios_base::out | std::ios_base::app;
    }
    std::ofstream output_file(file_path, file_flags);
    output_file << getElapsedTime() << '\n';
    counter_.reset();
    counter_.counter_state_ = std::make_unique<IdleState>(counter_);
}

void StoppedState::abort()
{
    counter_.reset();
    counter_.counter_state_ = std::make_unique<IdleState>(counter_);
}

std::string StoppedState::getElapsedTime() const {
    return utils::getElapsedTime(counter_.stop_, counter_.start_);
}

std::string StoppedState::getFilePath() const {
    return utils::join('/', config::log_save_path, counter_.task_name_, utils::getCurrentDate());
}

std::string StoppedState::getCurrentStateInfo() const noexcept {
    std::stringstream stream{};
    stream << "State: stopped \n";
    stream << "Task: " << counter_.task_name_ << '\n';
    stream << "Time elapsed: " << getElapsedTime();
    return stream.str();
}
