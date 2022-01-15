#include "tstat/TimeCounter.hpp"

#include "networking/IServer.hpp"
#include "tstat/config.hpp"
#include "tstat/utils.hpp"

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

void TimeCounter::save()
{
    counter_state_->save();
}

std::string TimeCounter::getFilePath() const
{
    return counter_state_->getFilePath();
}

void TimeCounter::start(const std::string& task_name)
{
    counter_state_->start(task_name);
}

void TimeCounter::abort()
{
    counter_state_->abort();
}

void TimeCounter::stop()
{
    counter_state_->stop();
}

std::string TimeCounter::getElapsedTime() const
{
    return counter_state_->getElapsedTime();
}

std::string TimeCounter::getCurrentStateInfo() const noexcept
{
    return counter_state_->getCurrentStateInfo();
}

void TimeCounter::reset() noexcept {
    task_name_ = "";
    start_ = decltype(start_){};
    stop_ = decltype(stop_){};
}
