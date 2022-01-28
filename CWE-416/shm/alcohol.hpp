#pragma once
#include <iostream>
#include "cargo.hpp"

//Class responsible for representing alcohol in the game
class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, Time *time, size_t percentage)
        : Cargo(name, amount, basePrice, time)
        , percentage_ (percentage)
        {}

    ~Alcohol() override;

    // override from Cargo
    Cargo* clone() override;
    size_t getPrice() const override;
    const std::string &getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPercentage() const { return percentage_; }

    Cargo& operator+=(size_t) override;
    Cargo& operator-=(size_t) override;
    bool operator==(const Cargo &) const override;
    void nextDay(size_t) override;

private:
    size_t percentage_;
};