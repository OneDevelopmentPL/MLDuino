# 🚀 Inicio Rápido: Llevando la IA a MLDuino

[English README](README.md) | [Polski README](PL_README.md) | [Español README](ES_README.md)<br>
[English QUICKSTART](QUICKSTART.md) | [Polski QUICKSTART](PL_QUICKSTART.md) | [Español QUICKSTART](ES_QUICKSTART.md)<br>

Debido a que el Arduino Uno R3 tiene solo 2KB de RAM, no podemos ejecutar frameworks de ML estándar. En su lugar, entrenamos un modelo en una computadora y lo exportamos como lógica C simple codificada. 

¡Así es como lo haces usando Python y `micromlgen`!

## Paso 1: Instalar Dependencias
En tu PC, necesitas `scikit-learn` y `micromlgen` (una herramienta que convierte modelos entrenados de scikit-learn a código C).
```bash
pip install scikit-learn micromlgen
```

## Paso 2: Entrenar y Exportar (Plantilla en Python)
Crea un script de Python en tu computadora para entrenar un clasificador simple (por ejemplo, un Árbol de Decisión) y generar el código C.

```python
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from micromlgen import port

# 1. Cargar datos de ejemplo (3 características imitando nuestros 3 sensores analógicos)
# Aquí usamos el famoso conjunto de datos Iris y tomamos solo 3 características por simplicidad
X, y = load_iris(return_X_y=True)
X = X[:, :3] 

# 2. Entrenar un Clasificador de Árbol de Decisión
clf = DecisionTreeClassifier(max_depth=3)
clf.fit(X, y)

# 3. Exportar el modelo a código C
c_code = port(clf)

print("Copia el código a continuación y pégalo en tu model.cpp:\n")
print(c_code)
```

## Paso 3: Integrar con MLDuino

1. Ejecuta el script de Python de arriba.
2. Generará una función C (generalmente `predict()`).
3. Abre `model.cpp` en este proyecto.
4. Reemplaza la lógica `run_model` ficticia con la lógica generada por `micromlgen`. Puede que solo necesites envolver la función `predict()` dentro de `run_model()`.

Ejemplo de `model.cpp` después de la integración:
```cpp
#include "model.h"

// --- CÓDIGO GENERADO POR MICROMLGEN VA AQUÍ ---
int predict(float *x) {
    // ... declaraciones if/else del árbol de decisión generado ...
    if (x[0] <= 0.5f) {
        return 1;
    }
    return 0;
}
// ------------------------------------------------

int run_model(float* features) {
    // Envuelve la función generada aquí
    return predict(features);
}
```

## Paso 4: ¡Flashear!
1. Abre `MLDuino.ino` en el IDE de Arduino.
2. Conecta tu Arduino Uno R3.
3. Haz clic en **Subir (Upload)**.
4. ¡Abre el Monitor Serie (115200 baudios) para ver tu IA en acción!
