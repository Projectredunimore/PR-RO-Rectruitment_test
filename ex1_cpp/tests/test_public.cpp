// test_public.cpp — public tests for Exercise 1.
// During evaluation, additional (hidden) tests covering the same requirements will also be run:
// passing only these is not enough, make sure you also handle the edge cases described in telemetry.hpp.

#include <stdexcept>
#include <vector>

#include "mini_test.hpp"
#include "telemetry.hpp"

using telemetry::findDrops;
using telemetry::longestRunAbove;
using telemetry::movingAverage;

// ---------------------------------------------------------------- Part A
TEST_CASE("A1 moving average - example") {
    CHECK_VEC_NEAR(movingAverage({1, 2, 3, 4, 5}, 2), (std::vector<double>{1.5, 2.5, 3.5, 4.5}), 1e-9);
}

TEST_CASE("A2 moving average - window of 1 returns the input") {
    const std::vector<double> in{12.4, 12.3, 12.1};
    CHECK_VEC_NEAR(movingAverage(in, 1), in, 1e-9);
}

TEST_CASE("A3 moving average - window as large as the input") {
    CHECK_VEC_NEAR(movingAverage({2, 4, 6, 8}, 4), (std::vector<double>{5.0}), 1e-9);
}

TEST_CASE("A4 moving average - invalid window") {
    CHECK_THROWS_AS(movingAverage({1, 2, 3}, 0), std::invalid_argument);
    CHECK_THROWS_AS(movingAverage({1, 2, 3}, 4), std::invalid_argument);
}

// ---------------------------------------------------------------- Part B
TEST_CASE("B1 run above threshold - example") {
    CHECK_EQ(longestRunAbove({12.1, 12.5, 11.0, 12.6, 12.7, 12.8, 10.9}, 12.0), std::size_t{3});
}

TEST_CASE("B2 run above threshold - no sample above threshold") {
    CHECK_EQ(longestRunAbove({10.0, 11.0, 9.5}, 12.0), std::size_t{0});
}

TEST_CASE("B3 run above threshold - empty input") {
    CHECK_EQ(longestRunAbove({}, 12.0), std::size_t{0});
}

// ---------------------------------------------------------------- Part C
TEST_CASE("C1 voltage drops - example") {
    CHECK_EQ(findDrops({12.6, 12.5, 11.9, 12.0, 11.2}, 0.5), (std::vector<std::size_t>{2, 4}));
}

TEST_CASE("C2 voltage drops - increasing series, no drop") {
    CHECK_EQ(findDrops({11.0, 11.5, 12.0, 12.5}, 0.1), (std::vector<std::size_t>{}));
}

TEST_CASE("C3 voltage drops - invalid threshold") {
    CHECK_THROWS_AS(findDrops({12.0, 11.0}, 0.0), std::invalid_argument);
}

// ---------------------------------------------------------------- Your tests (optional, but appreciated)
// Add here at least 2 tests of your own covering edge cases you consider important.
// Example:
// TEST_CASE("my test - ...") {
//     CHECK_EQ(..., ...);
// }

int main() { return mini_test::run_all(); }
