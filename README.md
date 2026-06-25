<div align="center">
  <h1>🚀 MLDuino</h1>
  <p><b>A bare-metal, ultra-optimized TinyML launcher for Arduino Uno R3.</b></p>
  
  [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
  [![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
</div>

## 🧠 Overview

**MLDuino** is a highly optimized, no-fluff template for running Machine Learning inference on severely resource-constrained devices like the Arduino Uno R3 (which has only 2KB of SRAM). 

Rather than relying on heavy frameworks like TensorFlow Lite for Microcontrollers (which typically require 32-bit MCUs and much more memory), MLDuino takes a **bare-metal C approach**. By compiling Decision Trees, Support Vector Machines (SVMs), or tiny Neural Networks directly into pure C code, you can easily run complex ML logic directly on an 8-bit AVR architecture.

## ✨ Features
- **Ultra-low footprint**: Designed specifically for 2KB RAM / 32KB Flash limits.
- **Modern C++**: Leverages `constexpr`, strict typing (`uint8_t`), and memory-safe design patterns.
- **Framework Agnostic**: Drop in C code generated from `Edge Impulse`, `micromlgen`, or `sklearn-porter`.
- **Zero dependencies**: No external Arduino ML libraries required.

## 🛠️ Usage

Simply replace the contents of `model.cpp` with your own generated C model. Connect your sensors to the analog pins, flash the board, and watch the inference happen!

Check out the [QUICKSTART.md](QUICKSTART.md) for a detailed guide on how to train and deploy your first AI model.

---
*If you like this project, please consider giving it a ⭐!*
