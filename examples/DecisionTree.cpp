// Example: Decision Tree Classifier (3 features, Binary Output)
// Generated using micromlgen/sklearn-porter style for Arduino Uno R3

int predict_decision_tree(float *x) {
    if (x[0] <= 0.5f) {
        if (x[1] <= 0.3f) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (x[2] <= 0.7f) {
            return 1;
        } else {
            return 0;
        }
    }
}
