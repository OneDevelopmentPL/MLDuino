<div align="center">
  <h1>🚀 MLDuino</h1>
  <p><b>Niskopoziomowy, ekstremalnie zoptymalizowany launcher TinyML dla Arduino Uno R3.</b></p>
  
  [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
  [![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)<br>
  [English README](README.md) | [Polski README](PL_README.md) | [Español README](ES_README.md)<br>
  [English QUICKSTART](QUICKSTART.md) | [Polski QUICKSTART](PL_QUICKSTART.md) | [Español QUICKSTART](ES_QUICKSTART.md)<br>
</div>

## 🧠 Przegląd

**MLDuino** to wysoce zoptymalizowany szablon pozbawiony zbędnego kodu, służący do uruchamiania modeli Machine Learning na urządzeniach o bardzo ograniczonych zasobach, takich jak Arduino Uno R3 (które posiada zaledwie 2KB pamięci SRAM).

Zamiast polegać na ciężkich frameworkach pokroju TensorFlow Lite for Microcontrollers (wymagających zazwyczaj układów 32-bitowych), MLDuino opiera się na **czystym języku C**. Kompilując Drzewa Decyzyjne, Maszyny Wektorów Nośnych (SVM) lub miniaturowe Sieci Neuronowe bezpośrednio do kodu C, możesz bez problemu uruchomić logikę ML na 8-bitowej architekturze AVR.

## ✨ Główne cechy
- **Minimalne zużycie pamięci**: Zaprojektowane specjalnie z myślą o limitach 2KB RAM / 32KB Flash.
- **Nowoczesny C++**: Wykorzystuje `constexpr`, ścisłe typowanie (`uint8_t`) i optymalizacje pamięciowe.
- **Niezależność od narzędzi**: Wklej po prostu kod C wygenerowany przez `Edge Impulse`, `micromlgen` lub `sklearn-porter`.
- **Brak zewnętrznych zależności**: Nie wymaga instalacji żadnych dodatkowych bibliotek ML dla Arduino.

## 🛠️ Jak używać?

Wystarczy podmienić zawartość pliku `model.cpp` na swój własny wygenerowany model C. Podłącz czujniki do pinów analogowych, wgraj kod na płytkę i gotowe!

Zajrzyj do pliku [PL_QUICKSTART.md](PL_QUICKSTART.md) po instrukcję krok po kroku, pokazującą jak wytrenować i wdrożyć swój pierwszy model sztucznej inteligencji.

---
*Jeśli projekt okazał się przydatny, zostaw ⭐!*
