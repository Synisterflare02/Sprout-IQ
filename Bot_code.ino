#include "BluetoothSerial.h" 
#include <DHT.h>
#include <ESP32Servo.h>

BluetoothSerial ESP_BT; // Object for Bluetooth

// Motor pins
#define RF 14
#define LB 27
#define LF 26
#define RB 12

// Sensor pins
#define DHTPIN 4      // DHT11 data pin
#define DHTTYPE DHT11 // DHT sensor type
#define SOIL_PIN 34   // Soil moisture analog pin

// Servo motor
#define SERVO_PIN 18  // Servo control pin
Servo myServo;

DHT dht(DHTPIN, DHTTYPE);
int incoming;

void setup() {
  Serial.begin(9600); // Start Serial monitor in 9600
  ESP_BT.begin("Car1");
  
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode(RF, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);
  digitalWrite(RF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  
  // Sensor and servo setup
  dht.begin(); // Initialize DHT11
  myServo.attach(SERVO_PIN); // Attach servo
  myServo.write(0); // Initial position

  delay(1000); // Wait for DHT11 to stabilize
}

void loop() {
  // Bluetooth car control code
  if (ESP_BT.available()) {
    incoming = ESP_BT.read(); 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 83) { // Stop
      digitalWrite(RF, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(LF, LOW);
      digitalWrite(RB, LOW);
    } else if (incoming == 66) { // Move forward
      digitalWrite(RF, HIGH);
      digitalWrite(LB, LOW);
      digitalWrite(LF, HIGH);
      digitalWrite(RB, LOW);
    } else if (incoming == 70) { // Move backward
      digitalWrite(RF, LOW);
      digitalWrite(LB, HIGH);
      digitalWrite(LF, LOW);
      digitalWrite(RB, HIGH);
    } else if (incoming == 76) { // Turn left
      digitalWrite(RF, HIGH);
      digitalWrite(LB, HIGH);
      digitalWrite(LF, LOW);
      digitalWrite(RB, LOW);
    } else if (incoming == 82) { // Turn right
      digitalWrite(RF, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(LF, HIGH);
      digitalWrite(RB, HIGH);
    }
  }

  // Read and display temperature, humidity, and soil moisture every 2 seconds
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int soilMoisture = analogRead(SOIL_PIN);
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Soil Moisture: ");
  Serial.println(soilMoisture);

  // Move servo to insert soil moisture sensor
  myServo.write(90); // Move servo down
  delay(1000); // Delay for sensor reading
  myServo.write(0); // Move servo up
  delay(2000); // Wait before next reading

  delay(2000); // Overall delay to avoid sensor spamming
}
