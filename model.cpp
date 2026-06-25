#include "model.h"

int run_model(float* features) {
  const float weight[3] = {0.5f, 1.2f, -0.3f};
  const float bias = -0.5f;
  
  float score = bias;
  for (int i = 0; i < 3; i++) {
    score += features[i] * weight[i];
  }
  
  return (score > 0.0f) ? 1 : 0;
}
