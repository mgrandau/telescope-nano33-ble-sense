/*
  Arduino LSM9DS1 - Combined Accelerometer and Magnetometer

  This example reads the acceleration values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>

void setup_accelerometer() {
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");
}

void loop_accelerometer() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.print(z);
    Serial.print('\t');
  }
}

void setup_magnetometer() {
  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" uT");
  Serial.println();
}

void loop_magnetometer() {
  float x, y, z;

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.print(z);
    Serial.print('\t');
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  setup_accelerometer();
  setup_magnetometer();

  Serial.println("Acceleration in G's\t\tMagnetic Field in uT");
  Serial.println("aX\taY\taZ\tmX\tmY\tmZ");
}

void loop() {
  loop_accelerometer();
  loop_magnetometer();
  Serial.println();
}