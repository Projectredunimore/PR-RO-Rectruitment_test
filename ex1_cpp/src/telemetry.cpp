// telemetry.cpp — Esercizio 1. Implementa qui le tre funzioni dichiarate in telemetry.hpp.
//
// Regole:
//   - usa solo la libreria standard (<vector>, <stdexcept>, <numeric>, <algorithm>, ...);
//   - non modificare le firme;
//   - puoi aggiungere funzioni di supporto in questo file se ti servono.

#include "telemetry.hpp"

#include <stdexcept>

namespace telemetry {

std::vector<double> movingAverage(const std::vector<double>& samples, std::size_t window) {
    // TODO: Parte A
    (void)samples;
    (void)window;
    throw std::runtime_error("movingAverage: non ancora implementata");
}

std::size_t longestRunAbove(const std::vector<double>& samples, double threshold) {
    // TODO: Parte B
    (void)samples;
    (void)threshold;
    throw std::runtime_error("longestRunAbove: non ancora implementata");
}

std::vector<std::size_t> findDrops(const std::vector<double>& samples, double minDrop) {
    // TODO: Parte C
    (void)samples;
    (void)minDrop;
    throw std::runtime_error("findDrops: non ancora implementata");
}

}  // namespace telemetry
