<div align="center">
  <h1>🚀 MLDuino</h1>
  <p><b>Un lanzador TinyML ultrarrápido y bare-metal para Arduino Uno R3.</b></p>
  
  [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
  [![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)<br>
  [English README](README.md) | [Polski README](PL_README.md) | [Español README](ES_README.md)<br>
  [English QUICKSTART](QUICKSTART.md) | [Polski QUICKSTART](PL_QUICKSTART.md) | [Español QUICKSTART](ES_QUICKSTART.md)<br>
</div>

## 🧠 Resumen

**MLDuino** es una plantilla altamente optimizada, sin código innecesario, para ejecutar inferencia de Machine Learning en dispositivos con recursos muy limitados como el Arduino Uno R3 (que solo tiene 2KB de SRAM). 

En lugar de depender de frameworks pesados como TensorFlow Lite para Microcontroladores (que generalmente requieren MCUs de 32 bits y mucha más memoria), MLDuino adopta un **enfoque C bare-metal**. Al compilar Árboles de Decisión, Máquinas de Vectores de Soporte (SVM) o pequeñas Redes Neuronales directamente a código C puro, puedes ejecutar lógicas complejas de ML directamente en una arquitectura AVR de 8 bits.

## ✨ Características
- **Huella de memoria ultrabaja**: Diseñado específicamente para los límites de 2KB de RAM y 32KB de Flash.
- **C++ Moderno**: Aprovecha `constexpr`, tipado estricto (`uint8_t`) y patrones de diseño seguros para la memoria.
- **Agnóstico al framework**: Simplemente pega el código C generado desde `Edge Impulse`, `micromlgen` o `sklearn-porter`.
- **Cero dependencias**: No requiere librerías ML de Arduino externas.

## 🛠️ Uso

Simplemente reemplaza el contenido de `model.cpp` con tu propio modelo C generado. ¡Conecta tus sensores a los pines analógicos, flashea la placa y observa cómo ocurre la inferencia!

Consulta el [ES_QUICKSTART.md](ES_QUICKSTART.md) para obtener una guía detallada sobre cómo entrenar y desplegar tu primer modelo de IA.

---
*Si te gusta este proyecto, ¡por favor considera darle una ⭐!*
