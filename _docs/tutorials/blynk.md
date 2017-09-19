---
title: Blynk
category: Tutorials
order: 4

---

## Extending the Environment Monitor with Blynk

<img src="{{ "/images/blynk/environment-monitor-fritzing_bb.png" | prepend: site.baseurl }}{{ img }}" alt="Environment Monitor Wiring Diagram" width="80%">


This tutorial builds off of [Experiment 6: Environment Monitor](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-6-environment-monitor) of the [Sparkfun Inventor's Kit for Photon Experiment Guide](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide).  As you will recall, your homework for today's class was to complete [Experiment 6](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-6-environment-monitor) up to "Part II:  Posting Environmental Data to data.sparkfun.com."   Because [data.sparkfun.com](https://data.sparkfun.com/) and its associated data logging engine [Phant](https://github.com/sparkfun/phant) are currently not allowing the creation of new data streams, we have to look to other IoT cloud platforms.

We've already made some use of Particle's console (and its Publish/Subscribe i/o schema).  Let's explore another one!  There are many options to choose from, each with its own unique feature-set and pros/cons, including:
* [ThingSpeak](https://thingspeak.com/)
* [freeboard](https://freeboard.io/)
* [dweet.io](https://dweet.io)
* [thinger.io](https://thinger.io/)
* [Cayenne](https://mydevices.com/cayenne/features/)
* [Samsung Artik Cloud](https://artik.cloud/)

In this tutorial, we will use [Blynk](http://www.blynk.cc/).

<img src="{{ "/images/blynk/blynk.png" | prepend: site.baseurl }}{{ img }}" alt="Blynk Logo">

## What is Blynk?

Blynk is an IoT platform with iOS and Android apps that enables users to control Photons, Arduino, Raspberry Pi and similar devices over the Internet.

It is comprised of three components:
1.  **Blynk App** - mobile applications that allow you to interface with your IoT devices.   

2.  **Blynk Server** - an open source cloud-based server that brokers communication between the smartphone running the Blynk App and the IoT device(s).  

3.  **Blynk Libraries** - that run on the IoT device, sending data from the device to the Blynk Server and receiving commands from the Blynk App, relayed through the Blynk Server.


## Part I - The Blynk App

1. If you haven't already, you will need to download and install the Blynk App:
<a href="https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&amp;mt=8"><img src="http://linkmaker.itunes.apple.com/images/badges/en-us/badge_appstore-lrg.svg" alt="Drawing" style=" width: 170px; height:60px"></a> <a href="https://play.google.com/store/apps/details?id=cc.blynk"><img src="https://play.google.com/intl/en_us/badges/images/apps/en-play-badge.png" alt="Drawing" style=" width: 158px; height:42px"></a>   

2. Launch the Blynk App and Create a Blynk Account   
After you download the Blynk App and open it, you’ll need to create a New Blynk account. (Note: This account is separate from the accounts used for the Blynk Forums, in case you already have one.)   
<img src="{{ "/images/blynk/create_account.png" | prepend: site.baseurl }}{{ img }}" alt="Blynk Home Screen" >   

   Blynk recommends using a real email address "because it will simplify things later" -- in particular, you will be able to reset your password as well as receive application auth tokens by email that you can cut-and-paste into the Particle online IDE.

3. After you create your account, you will be able to create a **+ New Project**:   
<img src="{{ "/images/blynk/new_project.png" | prepend: site.baseurl }}{{ img }}" alt="+ New Project" >   

4.  Give your project a name (e.g. "Enviro-Monitor").   

5.  Under "Choose Device", scroll until you find "Sparkfun Photon Redboard":   
<img src="{{ "/images/blynk/choose_device.png" | prepend: site.baseurl }}{{ img }}" alt="Choose Device" >   
and then press "Continue."

6.  Leave the Connection Type as "WIFI" (but note that you use several other protocols depending on your device's capabilities).

7.  Press the "Create" button.  This will cause the Blynk App to send you an email with your Auth Token.  Check your email to verify that it has been sent.   

   An Auth Token is a unique identifier which is needed to connect your hardware to your smartphone. Every new project you create will have its own Auth Token. You’ll get an Auth Token automatically on your email after project creation. You can also copy it manually.



## Part II:  Add Widgets to your Blynk App Project

The Blynk App contains an impressive range of pre-built widgets that you can use to represent data sent from your IoT device and/or control your IoT device.  For example, you may want to add a button to the graphical user interface that turns on an LED or trips a relay switch.   
<img src="{{ "/images/blynk/widgets.png" | prepend: site.baseurl }}{{ img }}" alt="Widgets" >  
 Note that you have a "Energy Balance" of 2,000 credits, and that each widget "costs" a finite amount of credits.  You can purchase additional credits by purchasing energy packs by pressing the "Add" button.  As we prototype, however, we can make do with our base allocation and "recycle" credits back to our Energy Balance when we're done with this project.

In this tutorial, we want to create a display for the temperature (in degrees Fahrenheit), the % humidity, and a gauge for the light levels, as illustrated below:
<img src="{{ "/images/blynk/example_app.png" | prepend: site.baseurl }}{{ img }}" alt="Example App" >  

### Let's build our interface!

At the completion of Part I, you should be looking at a blank Blynk App canvas:
<img src="{{ "/images/blynk/blank_canvas.png" | prepend: site.baseurl }}{{ img }}" alt="A Blank Blynk App Canvas" >  

1.  Let's begin by adding a widget to the canvas.  Click on the &#8853; icon at the top of the canvas to pull up the widget list.   
<img src="{{ "/images/blynk/widgets.png" | prepend: site.baseurl }}{{ img }}" alt="Widgets" >  

2.  Scroll down until you see the "Labeled Value" widget and tap it to add it to the interface.   
<img src="{{ "/images/blynk/label_added.png" | prepend: site.baseurl }}{{ img }}" alt="Label Value Added to Interface" >  

3. Tap on the newly added "Labeled" field on the canvas to access its settings screen:   
<img src="{{ "/images/blynk/labeled_value.png" | prepend: site.baseurl }}{{ img }}" alt="Labeled Value Settings Page" >  

    * Where it says "Labeled", change the text to "Temp".
    * You can change the text color by clicking on the red teardrop.
    * Under Input, we're going to send our data from the Photon to a "Virtual Pin" so click on the "PIN" button and choose Virtual V0 and then click "Continue."
    * We then need to set the range of expected data.  Since we can reasonably assume that ambient air temperature will range from -20 to 130 degrees, you can enter these values for MIN and MAX.
    * Under Label, you will use the following syntax: `Temp: /pin.#/ °F` to specify the degrees with a resolution of .1 degree (e.g. `Temp: 45.3 °F`).  See [Labeled Value Formatting Options](http://docs.blynk.cc/#widgets-displays-labeled-value) for more information.
    * Finally, for Reading Rate, choose "PUSH" (e.g. we want the data to update whenever the Photon "pushes" the data to the cloud.)  

   The results should look like this:   
<img src="{{ "/images/blynk/labeled_value_temp.png" | prepend: site.baseurl }}{{ img }}" alt="Temp Widget Settings" >  

4. Press the back arrow to return to your canvas.  Your canvas should now have a single element, a Temp field as illustrated below.   
<img src="{{ "/images/blynk/canvas_temp_only.png" | prepend: site.baseurl }}{{ img }}" alt="Canvas with Temp Value widget" >  

5.  Click on the &#8853; icon again at the top of the canvas to create a second widget.  Note that your Energy Balance has been reduced by 400 credits, the "cost" of a Labeled Value widget.

6.  Add a second "Labeled Value" widget for the % Humidity to your interface.  Assign it to Virtual Pin 1 (V1) with a display syntax of `Humidity: /pin./ %`.  It can also be set to use PUSH for a Reading Rate.   
<img src="{{ "/images/blynk/labeled_value_humidity.png" | prepend: site.baseurl }}{{ img }}" alt="Humidity Widget Settings" >  

6.  Finally, add a Gauge widget to the application canvas.   
<img src="{{ "/images/blynk/light_level.png" | prepend: site.baseurl }}{{ img }}" alt="Light Level Gauge Settings" >


You can adjust the position and size of your widgets by pressing and holding on them.  Drag to reposition and use the handles to resize.   
<img src="{{ "/images/blynk/example_app_before_data.png" | prepend: site.baseurl }}{{ img }}" alt="Resized and Repositioned" >

You are now ready to make the modifications to your Photon's Arduino code to connect to the Blynk App and Server.



## Part III:  Modify your Code

Recall that the code from [Experiment 6](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-6-environment-monitor) took temperature and humidity readings from the RTH03 sensor and light readings from the photocell every 1.5 seconds.  The onboard LED (attached to pin D7) would blink every time a reading was taken from the sensors.   And the data from these sensor readings was sent over USB serial to your attached computer.   The whole point of the IoT, however, is that devices can operate wirelessly and remotely.

In this exercise, we will modify the Experiment 6 code so that instead of simply writing the data to serial, the Photon will send the data to the Blynk Server enabling its display on the Blynk App dashboard we created in Part II above.

1.  Go into the [Particle online IDE](https://build.particle.io) and find the Particle app that you created when you completed Part I of Exercise 6.   

2.  Select all of the code in that app and copy it.  Next, create a new app called "EnvironmentalLoggerBlynk", pasting the code into the new app.   

3.  Note that the libraries associated with a particular project *DO NOT*  get copied over when you cut-and-paste code between projects in the Particle online IDE.  As a consequence, you will need to re-include the RHT03 library:   
   * Delete the top two lines of the code you've copied over:
   ```c++
   // This #include statement was automatically added by the Particle IDE.
   #include <SparkFunRHT03.h>
   ```
   * Go to the Libraries section of the online IDE and search for "RHT03".
   * Click on "SparkFunRHT03" to select that library and then click on the blue "Include in Project" button.
   * Under "Which App?", select the project that you just created and click "Confirm".   

4.  Also add the "blynk" library, which will enable functions for communication between your Photon and the Blynk ecosystem.

5.  Your code should now have both of the following libraries included in the code
```c++
#include <SparkFunRHT03.h>
#include <blynk.h>
```   
and listed under the Particle app's "Included Libraries" list in the Code panel.

6.  Now we can add in the code necessary to interact with the basic functionalities of the Blynk library.  For more information on these functions, visit the [Blynk Firmware Documentation](http://docs.blynk.cc/#blynk-firmware).   
Find your Auth Token from Part I, &#35;7 and add it to the declarations above the `void setup()` function:   
```c++
char auth[] = "YourAuthToken";
```

7.  Inside the `void setup()` function, on the last line before the closing }, add:
```c++
Blynk.begin(auth); // initiate Blynk library
```
More info on [Blynk.begin()](http://docs.blynk.cc/#blynk-firmware-configuration-blynkbegin)  
This function initiates the Blynk library and establishes a connection to the Blynk server.

8.  At the top of the `void loop()` function, add:
```c++
Blynk.run();
```
More info on [Blynk.run()](http://docs.blynk.cc/#blynk-firmware-connection-management-blynkrun)  
This function will enable Blynk's access (read and/or write) to the digital and analog pins of your Photon if you have configured them in the Blynk App.  

9.  Finally, in the section of the `void loop()` after the calculation of `humidity` and `tempF` and before the section of `Serial.print()` section, add the following lines:

    ```c++
    Blynk.virtualWrite(V0, tempF); //virtual pin 0 will be the temperature

    Blynk.virtualWrite(V1, humidity); //virtual pin 1 will be humidity
    ```   
    These functions will "write" the values of the tempF and humidity variables to the Blynk server and relay them to the corresponding widgets on the Blynk App canvas.  More info on [Blynk.virtualWrite()](http://docs.blynk.cc/#blynk-firmware-virtual-pins-control-blynkvirtualwritevpin-value)

10.  Verify and then flash the code to your Photon Redboard.

11.  Finally, in the Blynk App, click the "play" icon in the upper-right of the Blynk mobile app to switch from EDIT to PLAY mode.   
<img src="{{ "/images/blynk/play.png" | prepend: site.baseurl }}{{ img }}" alt="PLAY mode button" >   
You should see data appear in the App, updating regularly.
