// Example: Multi-Layer Perceptron (Neural Network)
// Architecture: 3 Inputs -> 2 Hidden Neurons (ReLU) -> 1 Output (Step Activation)
// Compact matrix multiplication perfect for AVR 8-bit microcontrollers

int predict_mlp(float *x) {
    const float w_hidden[2][3] = {
        {0.2f, -0.5f, 0.8f},
        {-0.4f, 0.9f, 0.1f}
    };
    const float b_hidden[2] = {0.1f, -0.2f};
    
    const float w_output[2] = {1.5f, -0.8f};
    const float b_output = 0.3f;

    float hidden_out[2];
    for (int i = 0; i < 2; i++) {
        float sum = b_hidden[i];
        for (int j = 0; j < 3; j++) {
            sum += x[j] * w_hidden[i][j];
        }
        hidden_out[i] = (sum > 0.0f) ? sum : 0.0f; // ReLU activation
    }

    float output_val = b_output;
    for (int i = 0; i < 2; i++) {
        output_val += hidden_out[i] * w_output[i];
    }

    return (output_val > 0.0f) ? 1 : 0;
}
