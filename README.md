
# **Sprout-IQ**

**Sprout-IQ** is an intelligent agricultural bot designed to optimize crop growth and provide tailored recommendations using advanced sensors and machine learning. It automates soil testing, enabling precise monitoring of environmental conditions like temperature, humidity, and moisture. This data is then used to recommend the best crops for each field, improving crop yield and efficiency.

## **Overview**

Sprout-IQ automates traditional soil testing processes, which are often inaccurate and time-consuming. It integrates sensors (such as temperature, humidity, and moisture sensors) to monitor soil conditions in real-time. Using machine learning, it processes this data to recommend the best crops suited for each field's unique conditions.

### **Key Features:**
- **Real-Time Soil Monitoring**: Monitors temperature, humidity, and soil moisture levels in real-time.
- **Tailored Crop Recommendations**: Recommends crops based on sensor data processed by machine learning algorithms.
- **Portable Design**: Designed to be easily portable and capable of navigating rough terrains, making it suitable for small and large farms.
- **Data-Driven Insights**: Provides actionable insights that improve crop yield, efficiency, and profitability.

## **Bot Design**

![Sprout-IQ Bot](https://github.com/Synisterflare02/Sprout-IQ/blob/main/Bot.jpg)

## **Remote Control**
![RC Control](https://github.com/Synisterflare02/Sprout-IQ/blob/main/Bot_control.jpg)

## **Software Requirements**

To run the **Sprout-IQ** bot, you'll need to install the following software:

1. **Arduino IDE** for programming the ESP32 and controlling the hardware.
2. **ESP32 Board Package** to program the ESP32 using the Arduino IDE.
3. **BluetoothSerial Library** to enable Bluetooth functionality for communication with the bot.
4. **DHT Library** to interface with the DHT11 temperature and humidity sensor.
5. **ESP32Servo Library** to control the servo motor used to move the soil moisture sensor.

### **Installation Steps:**

1. **Install Arduino IDE:**
   - Download and install the latest version of the Arduino IDE from the official website: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
   
2. **Install ESP32 Board Package:**
   - Open the Arduino IDE.
   - Go to **File > Preferences**.
   - In the **Additional Boards Manager URLs** field, add the following URL:  
     `https://dl.espressif.com/dl/package_esp32_index.json`
   - Go to **Tools > Board > Boards Manager**, search for `ESP32`, and install the package.

3. **Install Libraries:**
   Open the Arduino IDE and install the following libraries:

   - **BluetoothSerial Library**:  
     ```bash
     Arduino IDE > Sketch > Include Library > Manage Libraries
     Search for `BluetoothSerial` and install it.
     ```

   - **DHT Library**:  
     ```bash
     Arduino IDE > Sketch > Include Library > Manage Libraries
     Search for `DHT` and install it.
     ```

   - **ESP32Servo Library**:  
     ```bash
     Arduino IDE > Sketch > Include Library > Manage Libraries
     Search for `ESP32Servo` and install it.
     ```

4. **Upload the Code to ESP32:**
   - Connect the ESP32 to your computer.
   - Select the appropriate board and port under **Tools > Board** and **Tools > Port**.
   - Open the **Sprout-IQ** code in the Arduino IDE and click **Upload**.

## **How It Works**

The **Sprout-IQ** bot receives commands through Bluetooth for controlling the motors (moving forward, backward, turning, or stopping). It also monitors soil conditions with temperature, humidity, and moisture sensors, and displays the readings on the Serial Monitor. The servo motor is used to insert the soil moisture sensor into the soil, collect readings, and retract after a delay.

### **Motor Control**
- **Stop**: Sends the 'S' command.
- **Move Forward**: Sends the 'B' command.
- **Move Backward**: Sends the 'F' command.
- **Turn Left**: Sends the 'L' command.
- **Turn Right**: Sends the 'R' command.

### **Sensors**
- **Temperature & Humidity**: The bot reads values from the DHT11 sensor.
- **Soil Moisture**: The bot reads analog soil moisture values from the sensor.

## **Cloning the Repository**

To get started with **Sprout-IQ**, clone the repository using the following command:

```bash
git clone https://github.com/Synisterflare02/Sprout-IQ.git
```

Once cloned, you can open the repository in your Arduino IDE to start working with the bot's code.
