# 🚀 Quickstart: Jak wdrożyć AI do MLDuino

<br>
  [English README](README.md) | [Polski README](PL_README.md)<br>
  [English QUICKSTART](QUICKSTART.md) | [Polski QUICKSTART](PL_QUICKSTART.md)<br>
Z racji tego, że Arduino Uno R3 ma zaledwie 2KB RAM-u, odpalanie standardowych bibliotek ML odpada. Zamiast tego trenujemy model na komputerze i eksportujemy go do postaci surowych instrukcji języka C (tzw. bare-metal).

Oto instrukcja jak to zrobić przy użyciu Pythona i biblioteki `micromlgen`!

## Krok 1: Instalacja paczek na komputerze
Potrzebujesz środowiska Python oraz bibliotek `scikit-learn` i `micromlgen`.
```bash
pip install scikit-learn micromlgen
```

## Krok 2: Trening i Eksport (Szablon Python)
Poniższy skrypt uczy proste drzewo decyzyjne i generuje kod w C. Uruchom go na swoim komputerze.

```python
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from micromlgen import port

# 1. Ładowanie przykładowych danych (bierzemy 3 cechy, żeby pasowało do naszych 3 wejść analogowych)
X, y = load_iris(return_X_y=True)
X = X[:, :3] 

# 2. Trenowanie klasyfikatora (Drzewo Decyzyjne)
clf = DecisionTreeClassifier(max_depth=3)
clf.fit(X, y)

# 3. Wyeksportowanie modelu do czystego C
c_code = port(clf)

print("Skopiuj poniższy kod i wklej go do model.cpp:\n")
print(c_code)
```

## Krok 3: Integracja z MLDuino

1. Uruchom powyższy skrypt. Wygeneruje on na ekranie funkcję w C (zazwyczaj o nazwie `predict()`).
2. Otwórz plik `model.cpp` z tego projektu.
3. Podmień fałszywą logikę w `run_model` na tę wygenerowaną przez skrypt.

Przykładowy `model.cpp` po podmianie:
```cpp
#include "model.h"

// --- KOD WYGENEROWANY PRZEZ MICROMLGEN ---
int predict(float *x) {
    // ... wygenerowane instrukcje warunkowe if/else ...
    if (x[0] <= 0.5f) {
        return 1;
    }
    return 0;
}
// -----------------------------------------

int run_model(float* features) {
    // Wywołaj funkcję wygenerowaną przez pythona
    return predict(features);
}
```

## Krok 4: Wgrywanie na płytkę!
1. Otwórz `MLDuino.ino` w Arduino IDE.
2. Podłącz Arduino Uno R3 pod USB.
3. Kliknij **Wgraj (Upload)**.
4. Otwórz Monitor Portu Szeregowego (ustaw na 115200 baud) i ciesz się modelem TinyML działającym na Twojej płytce!
