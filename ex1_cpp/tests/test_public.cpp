// test_public.cpp — test pubblici dell'Esercizio 1.
// Durante la valutazione verranno eseguiti anche altri test (nascosti) sugli stessi requisiti:
// superare solo questi non basta, gestisci anche i casi limite descritti in telemetry.hpp.

#include <stdexcept>
#include <vector>

#include "mini_test.hpp"
#include "telemetry.hpp"

using telemetry::findDrops;
using telemetry::longestRunAbove;
using telemetry::movingAverage;

// ---------------------------------------------------------------- Parte A
TEST_CASE("A1 media mobile - esempio") {
    CHECK_VEC_NEAR(movingAverage({1, 2, 3, 4, 5}, 2), (std::vector<double>{1.5, 2.5, 3.5, 4.5}), 1e-9);
}

TEST_CASE("A2 media mobile - finestra di 1 restituisce l'input") {
    const std::vector<double> in{12.4, 12.3, 12.1};
    CHECK_VEC_NEAR(movingAverage(in, 1), in, 1e-9);
}

TEST_CASE("A3 media mobile - finestra grande quanto l'input") {
    CHECK_VEC_NEAR(movingAverage({2, 4, 6, 8}, 4), (std::vector<double>{5.0}), 1e-9);
}

TEST_CASE("A4 media mobile - finestra non valida") {
    CHECK_THROWS_AS(movingAverage({1, 2, 3}, 0), std::invalid_argument);
    CHECK_THROWS_AS(movingAverage({1, 2, 3}, 4), std::invalid_argument);
}

// ---------------------------------------------------------------- Parte B
TEST_CASE("B1 tratto sopra soglia - esempio") {
    CHECK_EQ(longestRunAbove({12.1, 12.5, 11.0, 12.6, 12.7, 12.8, 10.9}, 12.0), std::size_t{3});
}

TEST_CASE("B2 tratto sopra soglia - nessun campione sopra soglia") {
    CHECK_EQ(longestRunAbove({10.0, 11.0, 9.5}, 12.0), std::size_t{0});
}

TEST_CASE("B3 tratto sopra soglia - input vuoto") {
    CHECK_EQ(longestRunAbove({}, 12.0), std::size_t{0});
}

// ---------------------------------------------------------------- Parte C
TEST_CASE("C1 cali di tensione - esempio") {
    CHECK_EQ(findDrops({12.6, 12.5, 11.9, 12.0, 11.2}, 0.5), (std::vector<std::size_t>{2, 4}));
}

TEST_CASE("C2 cali di tensione - serie crescente, nessun calo") {
    CHECK_EQ(findDrops({11.0, 11.5, 12.0, 12.5}, 0.1), (std::vector<std::size_t>{}));
}

TEST_CASE("C3 cali di tensione - soglia non valida") {
    CHECK_THROWS_AS(findDrops({12.0, 11.0}, 0.0), std::invalid_argument);
}

// ---------------------------------------------------------------- I tuoi test (facoltativo, ma apprezzato)
// Aggiungi qui almeno 2 test tuoi che coprano casi limite che ritieni importanti.
// Esempio:
// TEST_CASE("mio test - ...") {
//     CHECK_EQ(..., ...);
// }

int main() { return mini_test::run_all(); }
