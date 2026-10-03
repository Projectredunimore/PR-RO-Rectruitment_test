// telemetry.hpp — Esercizio 1: analisi della telemetria della batteria del rover.
// NON modificare le firme delle funzioni: i test (pubblici e nascosti) le usano così come sono.
#pragma once

#include <cstddef>
#include <vector>

namespace telemetry {

/**
 * Parte A — Media mobile.
 *
 * Restituisce la media mobile di `samples` calcolata su finestre consecutive di
 * `window` campioni. L'elemento i del risultato è la media di
 * samples[i], samples[i+1], ..., samples[i+window-1].
 *
 * Il vettore restituito ha quindi samples.size() - window + 1 elementi.
 *
 * Lancia std::invalid_argument se window == 0 oppure window > samples.size().
 *
 * Esempio: movingAverage({1, 2, 3, 4, 5}, 2) -> {1.5, 2.5, 3.5, 4.5}
 */
std::vector<double> movingAverage(const std::vector<double>& samples, std::size_t window);

/**
 * Parte B — Tratto più lungo sopra soglia.
 *
 * Restituisce la lunghezza della più lunga sequenza di campioni CONSECUTIVI
 * strettamente maggiori di `threshold`. Restituisce 0 se nessun campione supera
 * la soglia (o se `samples` è vuoto).
 *
 * Esempio: longestRunAbove({12.1, 12.5, 11.0, 12.6, 12.7, 12.8, 10.9}, 12.0) -> 3
 */
std::size_t longestRunAbove(const std::vector<double>& samples, double threshold);

/**
 * Parte C — Rilevamento cali di tensione.
 *
 * Restituisce, in ordine crescente, gli indici i (con i >= 1) per cui
 *     samples[i-1] - samples[i] >= minDrop
 * cioè i punti in cui la tensione è calata di almeno `minDrop` rispetto al
 * campione precedente.
 *
 * Lancia std::invalid_argument se minDrop <= 0.
 *
 * Esempio: findDrops({12.6, 12.5, 11.9, 12.0, 11.2}, 0.5) -> {2, 4}
 */
std::vector<std::size_t> findDrops(const std::vector<double>& samples, double minDrop);

}  // namespace telemetry
