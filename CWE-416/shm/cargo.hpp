#pragma once
#include <string>
#include <memory>
#include "Time.hpp"
#include "TimeEffectable.hpp"

//Class responsible for representing cargo in game
class Cargo : public TimeEffectable
{
public:
    virtual Cargo &operator+=(size_t );
    virtual Cargo &operator-=(size_t );
    virtual bool operator==(const Cargo &) const;
    
    virtual size_t getPrice() const {return 0;};
    virtual const std::string &getName() const { return name_; }
    virtual size_t getAmount() const { return amount_; }
    virtual size_t getBasePrice() const { return basePrice_; }

    virtual Cargo* clone(){return this;}
    void printCargo(int) const;
    std::string getCargoInfo();
    void reduceAmount(size_t);
    void loadCargo();
    void increaseAmount(size_t);
    void setAmount(size_t);
    Cargo() = default;
    Cargo(std::string name, size_t amount, size_t basePrice, Time* time);
    virtual ~Cargo() = default;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    Time* time_;
};
