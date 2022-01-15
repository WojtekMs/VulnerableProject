#include "tstat/IdleState.hpp"

#include "tstat/TimeCounter.hpp"
#include "tstat/CountingState.hpp"
#include "tstat/config.hpp"

#include <chrono>
#include <sstream>

IdleState::IdleState(TimeCounter& counter)
: counter_(counter) {

}

void IdleState::start(const std::string& task_name) {
    counter_.task_name_ = task_name;
    counter_.start_ = std::chrono::system_clock::now();
    counter_.counter_state_ = std::make_unique<CountingState>(counter_);
}

void IdleState::stop() {
    return;
}

void IdleState::save() {
    return;
}

void IdleState::abort() {
    return;
}

std::string IdleState::getElapsedTime() const {
    return "00:00:00";
}

std::string IdleState::getFilePath() const {
    return {};
}

std::string IdleState::getCurrentStateInfo() const noexcept {
    std::stringstream stream{};
    stream << "State: idle\n";
    stream << "Task: \n";
    stream << "Time elapsed: ";
    return stream.str();
}
