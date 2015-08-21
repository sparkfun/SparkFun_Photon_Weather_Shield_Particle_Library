# SparkFun_Photon_Weather_Shield_Library
Use this one library to talk to all the built-in I2C devices on your SparkFun Photon Weather Shield

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
    Serial.begin(9600);   // open serial over USB at 9600 baud

    // Make sure your Serial Terminal app is closed before powering your device
    // Now open your Serial Terminal, and hit any key to continue!
    Serial.println("Press any key to begin");
    //This line pauses the Serial port until a key is pressed
    while(!Serial.available()) Spark.process();

    //Initialize the I2C sensors and ping them
    sensor.begin();

    /*You can only receive acurate barrometric readings or acurate altitiude
    readings at a given time, not both at the same time. The following two lines
    tell the sensor what mode to use. You could easily write a function that
    takes a reading in one made and then switches to the other mode to grab that
    reading, resulting in data that contains both acurate altitude and barrometric
    readings. For this example, we will only be using the barometer mode. Be sure
    to only uncomment one line at a time. */
    sensor.setModeBarometer();//Set to Barometer Mode
    //baro.setModeAltimeter();//Set to altimeter Mode

    //These are additional MPL3115A2 functions the MUST be called for the sensor to work.
    sensor.setOversampleRate(7); // Set Oversample rate
    //Call with a rate from 0 to 7. See page 33 for table of ratios.
    //Sets the over sample rate. Datasheet calls for 128 but you can set it
    //from 1 to 128 samples. The higher the oversample rate the greater
    //the time between data samples.


    sensor.enableEventFlags(); //Necessary register calls to enble temp, baro ansd alt
	}

Then you can read various data like this:

	// Measure Relative Humidity from the HTU21D or Si7021
	humidity = sensor.getRH();
	
	// Measure Temperature from the HTU21D or Si7021
	tempf = sensor.getTempF();
	
	//Measure the Barometer temperature in F from the MPL3115A2
	baroTemp = sensor.readBaroTempF();
	
	//Measure Pressure from the MPL3115A2
	pascals = sensor.readPressure();
	
	//If in altitude mode, you can get a reading in feet with this line:
    altf = sensor.readAltitudeFt();
	
Check out the example files in the [examples directory](https://github.com/sparkfun/SparkFun_Photon_Weather_Shield_Particle_Library/tree/master/firmware/examples) for more guidance.

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
