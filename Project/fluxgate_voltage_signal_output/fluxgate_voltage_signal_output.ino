/* Semester project for course DPMS AS - 2206: Sensors
 * Measuring output peak-to-peak voltage of a fluxgate sensor
 * Authors:
 *        Georgios Kassavetakis
 *        Georgios Krommydas
 *        Lampis Papakostas 
 */


int sensorPin = A0;
const float Vcc = 5000.0;                             //mV
int minV, maxV;

void setup() {

  Serial.begin(9600);
  maxV = 0;                                           // Minimum value to change to maximum signal point
  minV = Vcc;                                         // Maximum value to change to minimum signal point

}

unsigned long currentTime, periodStart, prevTime;
unsigned long TimePeriod = 200;

float voltage;
int sensorValue;

void loop() {

  currentTime = millis(); 
  while(currentTime - periodStart <= TimePeriod){     // Measure maximum and minimum values in a period

    sensorValue = analogRead(sensorPin);
    voltage = ((float) sensorValue/1024.0)*Vcc;       //to mV
    maxV = max(maxV,voltage);
    minV = min(minV,voltage);   
    currentTime = millis();

  }

  periodStart = currentTime;
  
  printVpp(minV,maxV);                                // Print Vpp
  
  prevTime = currentTime;
  minV = 5000;
  maxV = 0;

}

void printVpp(int min, int max){

  int offset = 0;//245
  Serial.print("The Sensor measured the Peak-to-Peak Voltage:" );
  Serial.print( max - min + offset);
  Serial.println("mV\n");

}