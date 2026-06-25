// Example: Support Vector Machine (SVM) Classifier (3 features, Linear Kernel)
// Highly optimized vector multiplication running in constant time

int predict_svm(float *x) {
    const float weights[3] = {0.85f, -0.42f, 1.15f};
    const float intercept = -0.25f;

    float decision_value = intercept;
    for (int i = 0; i < 3; i++) {
        decision_value += x[i] * weights[i];
    }

    return (decision_value > 0.0f) ? 1 : 0;
}
