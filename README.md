# CodeGreen - Pollution Data Analysis using IoT

## Overview

This project focuses on collecting and analyzing pollution data using IoT devices. The system includes a NodeMCU microcontroller, a potentiometer, a 16x2 LCD display, an MQ 125 sensor, jumper wires, and a breadboard. The data collected over two days in **JK Lakshmipat University, Jaipur (India)**, including both weekdays and weekends, is utilized to train a Long Short-Term Memory (LSTM) machine learning model. The trained model is then used to predict pollution levels in the local area based on the latest 50 parameters recorded by the IoT device.
Components Used

- NodeMCU: The NodeMCU microcontroller is used to interface with sensors, collect data, and communicate with the ThingSpeak cloud service.

- Potentiometer: A potentiometer is used to adjust sensitivity or calibrate the sensor based on environmental conditions.

- 16x2 LCD Display: The LCD display provides real-time feedback on pollution levels and system status.

- MQ 125 Sensor: This sensor is employed to measure air quality and detect various pollutants.

- Jumper Wires: Essential for connecting components on the breadboard and ensuring a reliable electrical connection.

- Breadboard: Used for prototyping and organizing the electronic components.

## Data Collection

Data is collected over two days, including both weekdays and weekends, to capture diverse pollution trends. The collected data serves as the input for training the LSTM machine learning model.

## Machine Learning Model

An LSTM machine learning model is trained using the collected data. This model is designed to recognize patterns and trends in pollution data, enabling it to make predictions based on the latest 50 parameters recorded by the IoT device.
Integration with ThingSpeak

The IoT device is connected to the ThingSpeak cloud service. This allows seamless communication between the device and the cloud, enabling data storage, retrieval, and analysis.
Flutter-Based Mobile Application

A mobile application built with Flutter is used to visualize and interact with the pollution data. The app fetches data from ThingSpeak, displays real-time information, and provides insights based on the predictions made by the machine learning model.

## Getting Started

1. Hardware Setup: Connect the NodeMCU, potentiometer, 16x2 LCD display, and MQ 125 sensor on the breadboard using jumper wires. Circuit-diagram is already provived.

2. IoT Device Code: Upload the provided NodeMCU code to the microcontroller. Make sure to configure the Wi-Fi settings and ThingSpeak API keys.

3. Machine Learning: Train the LSTM model using the collected data. The code for training the model is provided in the 'ml_model' directory.

3. Mobile Application: Install the Flutter-based mobile application on your device. Configure the app to connect to the ThingSpeak cloud service.

5. Run the System: Power up the IoT device and launch the mobile application. Monitor real-time pollution data and predictions on the mobile app.

## Additional Notes

- Calibration of the potentiometer may be necessary based on environmental conditions.
- Regularly update the machine learning model to improve prediction accuracy.

### License
This project is licensed under the [MIT License](https://www.mit.edu/~amini/LICENSE.md).