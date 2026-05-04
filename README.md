# A-TinyML-Based-Method-for-Real-Time-State-of-Charge-Estimation-Using-TCNonSTM32
A TinyML-based approach for real-time State of Charge (SoC) estimation of lithium-ion batteries using STM32 microcontrollers. The project implements an optimized machine learning model for efficient, low-power, and accurate battery monitoring in embedded systems.


## Repository Structure

- Core/ → Main STM32 application code
- Drivers/ → HAL and CMSIS drivers
- Middlewares/ → AI libraries (X-CUBE-AI)
- X-CUBE-AI/ → Generated AI model files
- TinyML.ipynb → Model training and preprocessing
- dataset_with_soc.csv → Dataset used for training


- STM32L432KCU Microcontroller
- Sensors (if any — mention yours)
- USB / UART for output


- Model type: (e.g., TCN / Neural Network)
- Framework: TensorFlow / Keras
- Quantization: INT8 (important — mention this)
- Deployment: X-CUBE-AI

1. Open STM32CubeIDE
2. Import project
3. Build and flash to STM32 board
4. Monitor output via UART

- Real-time SoC estimation
- Low latency inference on STM32
- Efficient memory usage


- Real-time embedded ML inference
- Low-power TinyML implementation
- Hardware + ML integration
