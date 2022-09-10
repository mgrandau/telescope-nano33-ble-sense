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

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  /* Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");

  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" uT");

  Serial.println("Acceleration in G's\t\tMagnetic Field in uT");
  Serial.println("aX\taY\taZ\tmX\tmY\tmZ"); */
}

void loop() {
  float x, y, z;
  float mx, my, mz;

  if (IMU.accelerationAvailable() && IMU.magneticFieldAvailable()) {
    IMU.readAcceleration(x, y, z);
    IMU.readMagneticField(mx, my, mz);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.print(z);
    Serial.print('\t');

    Serial.print(mx);
    Serial.print('\t');
    Serial.print(my);
    Serial.print('\t');
    Serial.print(mz);
    Serial.println('\t');
  }
}