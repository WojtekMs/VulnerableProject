#include "tstat/CountingState.hpp"

#include "tstat/StoppedState.hpp"
#include "tstat/IdleState.hpp"
#include "tstat/TimeCounter.hpp"
#include "tstat/utils.hpp"
#include "tstat/config.hpp"

#include <chrono>
#include <sstream>


CountingState::CountingState(TimeCounter& counter) : counter_(counter) {}

void CountingState::start(const std::string&)
{
    return;
}

void CountingState::stop()
{
    counter_.stop_ = std::chrono::system_clock::now();
    counter_.counter_state_ = std::make_unique<StoppedState>(counter_);
}

void CountingState::save()
{
    return;
}

void CountingState::abort()
{
    counter_.reset();
    counter_.counter_state_ = std::make_unique<IdleState>(counter_);
}

std::string CountingState::getElapsedTime() const {
    return utils::getElapsedTime(std::chrono::system_clock::now(), counter_.start_);
}

std::string CountingState::getFilePath() const {
    return utils::join('/', config::log_save_path, counter_.task_name_, utils::getCurrentDate());
}

std::string CountingState::getCurrentStateInfo() const noexcept {
    std::stringstream stream{};
    stream << "State: counting\n";
    stream << "Task: " << counter_.task_name_ << '\n';
    stream << "Time elapsed: " << getElapsedTime();
    return stream.str();
}
