// telemetry.hpp — Exercise 1: analysis of the rover's battery telemetry.
// DO NOT change the function signatures: the tests (public and hidden) use them exactly as they are.
#pragma once

#include <cstddef>
#include <vector>

namespace telemetry {

/**
 * Part A — Moving average.
 *
 * Returns the moving average of `samples` computed over consecutive windows of
 * `window` samples. Element i of the result is the average of
 * samples[i], samples[i+1], ..., samples[i+window-1].
 *
 * The returned vector therefore has samples.size() - window + 1 elements.
 *
 * Throws std::invalid_argument if window == 0 or window > samples.size().
 *
 * Example: movingAverage({1, 2, 3, 4, 5}, 2) -> {1.5, 2.5, 3.5, 4.5}
 */
std::vector<double> movingAverage(const std::vector<double>& samples, std::size_t window);

/**
 * Part B — Longest run above threshold.
 *
 * Returns the length of the longest run of CONSECUTIVE samples strictly
 * greater than `threshold`. Returns 0 if no sample exceeds the threshold
 * (or if `samples` is empty).
 *
 * Example: longestRunAbove({12.1, 12.5, 11.0, 12.6, 12.7, 12.8, 10.9}, 12.0) -> 3
 */
std::size_t longestRunAbove(const std::vector<double>& samples, double threshold);

/**
 * Part C — Voltage drop detection.
 *
 * Returns, in ascending order, the indices i (with i >= 1) for which
 *     samples[i-1] - samples[i] >= minDrop
 * i.e. the points where the voltage dropped by at least `minDrop` compared to
 * the previous sample.
 *
 * Throws std::invalid_argument if minDrop <= 0.
 *
 * Example: findDrops({12.6, 12.5, 11.9, 12.0, 11.2}, 0.5) -> {2, 4}
 */
std::vector<std::size_t> findDrops(const std::vector<double>& samples, double minDrop);

}  // namespace telemetry
