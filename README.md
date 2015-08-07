# SparkFun_Photon_Weather_Shield_Library
Use this one library to talk to all the I2C devices on your SparkFun Photon Weather Shield

About
-------------------

This is a firmware library for [SparkFun's Photon Weather Shield](https://www.sparkfun.com/products/13630).

[![Photon Battery Shield](https://cdn.sparkfun.com//assets/parts/1/1/0/1/7/13630-01a.jpg)](https://www.sparkfun.com/products/13630).

Repository Contents
-------------------

* **/doc** - Additional documentation for the user. These files are ignored by the IDE. 
* **/firmware** - Source files for the library (.cpp, .h).
* **/firmware/examples** - Example sketches for the library (.cpp). Run these from the Particle IDE. 
* **spark.json** - General library properties for the Particel library manager. 

Example Usage
-------------------

Include the library:

	#include "SparkFunMPL3115A2.h" // Include the SparkFun MPL3115A2 library
	
Then use the `Weather` object to interact with it. Begin by initializing the IC:

	Weather sensor;//Create Instance of Weather Class

The Setup

  void setup()
  {
    Serial.begin(9600);

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

Then you can read various data like this:

  rh = sensor.getRH();
  t = sensor.getTempF();
  pascals = sensor.readPressure();
  altf = sensor.readAltitudeFt();
  baroTemp = sensor.readBaroTempF();
	
Check out the example files in the [examples directory]() for more guidance.

Recommended Components
-------------------

* [Particle Photon](https://www.sparkfun.com/products/13345)
* [SparkFun Photon Weather Shield](https://www.sparkfun.com/products/13630)

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.
