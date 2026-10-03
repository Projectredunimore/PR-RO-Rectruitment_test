# Esercizio 1 — Telemetria della batteria (C++)


Il rover registra la tensione della batteria a intervalli regolari in un `std::vector<double>`. Implementa in `src/telemetry.cpp` le tre funzioni dichiarate in `include/telemetry.hpp` (le specifiche complete sono nei commenti dell'header):

Implementare nel file `src/telemetry.cpp` i seguenti metodi:

- **A. `movingAverage(samples, window)`** restituisce la media mobile su finestre di `window` campioni consecutivi (il risultato ha `samples.size() - window + 1` elementi) e lancia `std::invalid_argument` se `window == 0` o `window > samples.size()`.
- **B. `longestRunAbove(samples, threshold)`** restituisce la lunghezza della più lunga sequenza di campioni consecutivi **strettamente** maggiori di `threshold`.
- **C. `findDrops(samples, minDrop)`** restituisce gli indici `i ≥ 1` in cui `samples[i-1] - samples[i] >= minDrop` e lancia `std::invalid_argument` se `minDrop <= 0`.

**Usa solo la libreria standard.**

Per compilare ed eseguire i test eseguire i seguenti comandi all'interno della cartella che contiene questo file:

```bash
cmake -S . -B build && cmake --build build
./build/test_public
```