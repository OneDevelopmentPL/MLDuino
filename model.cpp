#include "model.h"

// ----------------------------------------------------
// Zastępcza funkcja modelu
// Tutaj wklejasz kod wygenerowany przez narzędzie ML
// ----------------------------------------------------
int run_model(float* x) {
  // to jest tylko fejkowa regresja, żeby kod się kompilował
  // przy normalnym modelu będą tu wygenerowane if-y (drzewo decyzyjne)
  // albo wygenerowane macierze wag.
  
  float weight[3] = {0.5, 1.2, -0.3};
  float bias = -0.5;
  
  float score = bias;
  for(int i=0; i<3; i++) {
    score += x[i] * weight[i];
  }
  
  // próg odcięcia
  return (score > 0.0) ? 1 : 0;
}
