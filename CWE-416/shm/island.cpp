#include "island.hpp"
#include <algorithm>
#include <memory>
Island::Island(Coordinates position, Time  * time) 
    : store_(1000, 100, time) 
    , position_(position)
    {}

Store* Island::returnIslandStore()
{
    return &store_;
}