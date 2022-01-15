#pragma once

#include <string>

class IState {
    public:

    virtual ~IState() = default;
    virtual void start(const std::string&) = 0;
    virtual void stop() = 0;
    virtual void abort() = 0;
    virtual void save() = 0;
    virtual std::string getElapsedTime() const = 0;
    virtual std::string getFilePath() const = 0;
    virtual std::string getCurrentStateInfo() const noexcept = 0;

};
