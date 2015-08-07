
#include "SparkFun_Photon_Weather_Shield_Library.h"

float pascals = 0;
float altf = 0;
float baroTemp = 0;
float t, rh =0;

Weather sensor;//Create Instance of Weather Class

void setup(){
  Serial.begin(9600);

  // Make sure your Serial Terminal app is closed before powering your device
  // Now open your Serial Terminal, and hit any key to continue!
  Serial.println("Press any key to begin");
  //This line pauses the Serial port until a key is pressed
  while(!Serial.available()) Spark.process();

  //Initialize the I2C sensors and ping them
  checkDevices();

  //MPL3115A2 Settings
  //baro.setModeBarometer();//Set to Barometer Mode
  sensor.setModeAltimeter();//Set to altimeter Mode

  sensor.setOversampleRate(7); // Set Oversample to the recommended 128
  sensor.enableEventFlags(); //Necessary register calls to enble temp, baro ansd alt

  // To change resolution of the Temp/Humidity sensor, use
  // sensor.changeResolution(int i) where i=[0-3],
  //sensor.changeResolution(0);
}

void loop()
{
  //Pull all sensors for data
  getWeather();

  //Print that data to the Serial Port
  printInfo();

  delay(1000);

  // To play switch on/off onboard heater use heaterOn() and heaterOff()
  // heaterOn();
  // delay(5000);
  // heaterOff();
}
//---------------------------------------------------------------
void getWeather()
{
  // Measure RH
  rh = sensor.getRH();

  // Measure Temperature
  t = sensor.getTempF();

  // Temperature is measured every time RH is requested.
  // It is faster, therefore, to read it from previous RH
  // measurement instead with readTemp()
  // float t = sensor.readTemp();

  //Measure Pressure
  pascals = sensor.readPressure();

  //Measure Altitude in ft.
  altf = sensor.readAltitudeFt();

  //Measure the Barometer temperature in F
  baroTemp = sensor.readBaroTempF();
}
//---------------------------------------------------------------
void printInfo()
{
//This function prints the weather data out to the default Serial Port

  Serial.print("Temp:");
  Serial.print(t);
  Serial.print("F, ");

  Serial.print("Humidity:");
  Serial.print(rh);
  Serial.print("%, ");

  Serial.print("Baro Temp: ");
  Serial.print(baroTemp);
  Serial.print("F, ");

  Serial.print("Pressure:");
  Serial.print(pascals);
  Serial.print("Pa, ");

  Serial.print("Altitude:");
  Serial.print(altf);
  Serial.println("ft.");

}
//---------------------------------------------------------------
void checkDevices()
{
  int init = sensor.begin();
  if(init == 1)
  {
    Serial.println("MPL3115A2 Found");
    Serial.println("Si7021 Found");
  }
  else if(init == 2)
  {
    Serial.println("MPL3115A2 Found");
    Serial.println("HTU21D Found");
  }
  else if(init == 3)
  {
    Serial.println("MPL3115A2 NOT Found");
    Serial.println("Si7021 Found");
  }
  else if(init == 4)
  {
    Serial.println("MPL3115A2 NOT Found");
    Serial.println("HTU21D Found");
  }
  else if(init == 5)
  {
    Serial.println("MPL3115A2 Found");
    Serial.println("No Temp/Humidity Device Detected");
  }
  else
    Serial.println("No Devices Detected");
}
