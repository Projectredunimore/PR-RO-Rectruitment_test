// telemetry.cpp — Exercise 1. Implement here the three functions declared in telemetry.hpp.
//
// Rules:
//   - use the standard library only (<vector>, <stdexcept>, <numeric>, <algorithm>, ...);
//   - do not change the signatures;
//   - you may add helper functions in this file if you need them.

#include "telemetry.hpp"

#include <stdexcept>

namespace telemetry {

std::vector<double> movingAverage(const std::vector<double>& samples, std::size_t window) {
    // TODO: Part A
    (void)samples;
    (void)window;
    throw std::runtime_error("movingAverage: not implemented yet");
}

std::size_t longestRunAbove(const std::vector<double>& samples, double threshold) {
    // TODO: Part B
    (void)samples;
    (void)threshold;
    throw std::runtime_error("longestRunAbove: not implemented yet");
}

std::vector<std::size_t> findDrops(const std::vector<double>& samples, double minDrop) {
    // TODO: Part C
    (void)samples;
    (void)minDrop;
    throw std::runtime_error("findDrops: not implemented yet");
}

}  // namespace telemetry
