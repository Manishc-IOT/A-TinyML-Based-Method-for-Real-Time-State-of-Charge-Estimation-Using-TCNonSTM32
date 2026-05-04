# A TinyML-Based Method for Real-Time State of Charge Estimation Using TCNonSTM32

## Overview
This project presents a TinyML-based approach for real-time State of Charge (SoC) estimation of lithium-ion batteries using an STM32 microcontroller. A machine learning model is trained using battery data and deployed on embedded hardware using X-CUBE-AI for efficient, low-power inference.

---

## System Workflow
Dataset → Model Training (Colab) → Quantization (INT8) → X-CUBE-AI Conversion → STM32 Deployment → Real-time SoC Output

---

## Repository Structure
- `Core/` → Main STM32 application code  
- `Drivers/` → HAL and CMSIS drivers  
- `Middlewares/` → AI middleware and libraries  
- `X-CUBE-AI/` → Generated model and inference files  
- `TinyML.ipynb` → Model training and preprocessing (Google Colab)  
- `dataset_with_soc.csv` → Dataset used for training  
- `README.md` → Project documentation  
- `Report/` → Detailed project report (methodology, results, analysis)  

---

## Hardware Used
- STM32L432KCU Microcontroller  
- UART interface for output monitoring  

---

## Machine Learning Details
- Model Type: Temporal Convolutional Network (TCN)  
- Framework: TensorFlow / Keras  
- Quantization: INT8 (optimized for embedded deployment)  
- Deployment Tool: X-CUBE-AI  

---

## How to Run
1. Open the project in STM32CubeIDE  
2. Build the project  
3. Flash the code to STM32 board  
4. Monitor output via UART terminal  

---

## Output
- Real-time SoC estimation on STM32  
- Optimized inference for low-power embedded systems  
- Accurate battery monitoring using TinyML  

---

## Project Report
A detailed explanation of the methodology, model development, and results is provided in the `Report/` folder.

---

## Key Features
- Real-time TinyML inference on embedded hardware  
- Efficient deployment using X-CUBE-AI  
- Integration of machine learning with STM32 microcontroller  
- Low memory footprint and power-efficient design  

---

## Author
Manish C
