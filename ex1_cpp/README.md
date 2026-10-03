# Exercise 1 — Battery telemetry (C++)


The rover logs the battery voltage at regular intervals in a `std::vector<double>`. Implement in `src/telemetry.cpp` the three functions declared in `include/telemetry.hpp` (the full specifications are in the header comments):

- **A. `movingAverage(samples, window)`** returns the moving average over windows of `window` consecutive samples (the result has `samples.size() - window + 1` elements) and throws `std::invalid_argument` if `window == 0` or `window > samples.size()`.
- **B. `longestRunAbove(samples, threshold)`** returns the length of the longest run of consecutive samples **strictly** greater than `threshold`.
- **C. `findDrops(samples, minDrop)`** returns the indices `i ≥ 1` where `samples[i-1] - samples[i] >= minDrop` and throws `std::invalid_argument` if `minDrop <= 0`.

**Use the standard library only.**

To build and run the tests, run the following commands from the folder that contains this file:

```bash
cmake -S . -B build && cmake --build build
./build/test_public
```