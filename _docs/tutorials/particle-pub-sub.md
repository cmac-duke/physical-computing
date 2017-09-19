---
title: Photon Pub/Sub
category: Tutorials
order: 3

---

In this tutorial, we will cover the some basics of the Sparkfun Photon Redboard and explore the Particle platform's [publish / subscribe messaging pattern](https://en.wikipedia.org/wiki/Publish%E2%80%93subscribe_pattern).  This architecture allows a Photon to communicate information about itself (publish) as well as receive information about the status of other IoT devices (subscribe).   All communication takes place though a "broker," the [Particle cloud console](https://console.particle.io/).

## Project 1 - Internet Button

The goal of this project is to create an internet-connected button that, when pressed, sends an email.

### Key Concepts

* **void setup()**: all Arduino code must have a setup function defined. This gets run once when the system boots up.
* **void loop()**: all Arduino code must also have a loop function defined. After setup is run, this function runs in an infinite loop.
* **pinMode()**: tells the device that we'll be using a pin to either gather `INPUT` or provide `OUTPUT`.
* **digitalRead()**: takes a digital (binary) reading from the specified pin. This will return `HIGH` or `LOW` depending on the state of the pin.
* **Particle.publish()**: This function publishes an event to the Particle console. This is what we'll use with [IFTTT](https://ifttt.com) to make the magic happen.
* **delay()**: This function pauses the program for the specified number of milliseconds, useful here so the button press is only registered once instead of many times.  The latter phenomenon is known as ["switch bouncing"](https://www.allaboutcircuits.com/technical-articles/switch-bounce-how-to-deal-with-it/) and can cause all sorts of irregular behavior in a circuit.  A delay is one way of addressing the problem but it can also be solved with hardware (e.g. a capacitor) or using software (e.g. edge detection).

### Hardware Configuration

IMPORTANT:  Make sure that your Photon Redboard is *unplugged* before wiring up the circuit below:   
<img src="{{ "/images/particle_pub_sub/internet_button_wiring.png" | prepend: site.baseurl }}{{ img }}" alt="Internet Button Wiring">

### Particle IDE
The online Particle IDE allows you to write code and than "flash" that code to your Photon Redboard over wifi.   

1.  Visit [https://build.particle.io/build/new](https://build.particle.io/build/new)

2.  Give your app a name in the "Title" field and press RETURN to save the file.

3.  Note that the IDE pre-populates your code with the essential functions of any Arduino-based sketch:  `void setup()` and `void loop()`.

4.  Let's begin by declaring a variable to hold the pin number that our pushbutton is attached to.  If your wiring scheme matches the image above, that's digital pin 0 (D0).  Add the following to your code, *above `void setup(){`*:   
    ```c++
    int buttonPin = D0;
    ```

5.  Next, let's use the `pinMode()` function to set buttonPin to function as an input (e.g. we want to read the state of D0).  This should be placed *inside* the `void setup()` function, so that it reads:   
    ```c++
    void setup() {
        pinMode(buttonPin, INPUT);
    }
    ```
6.  On the first line of the `void loop()` function, type:
    ```c++
    int buttonState = digitalRead(buttonPin);
    ```   
    This will read the state of pin D0 at the start of every iteration of the `void loop()` function and store that state in a variable called `buttonState`.  The value of `buttonState` will be `HIGH` (or `1`) when the button is pressed, and `LOW` (or `0`) when it is released.

7.  Beneath that line, and still within the `void loop()` function, type the following:   
    ```c++
    if (buttonState == HIGH) {
        Particle.publish("buttonPressed");
        delay(2000);
    }
    ```
    This `if` statement will, if the button is pressed, use the special Photon-specific `Particle.publish()` function to send a message Event to the Particle Console.  And then the program will delay for 2 seconds to avoid switch bouncing.

8.  Click on the Folder icon to save the additions to your code.

9.  Click on the Verify &#x2714; icon to check your code for errors.  Address any errors that the IDE may identify.

10.  Finally, click on the Flash &#x26A1; icon to "flash" your code to your Photon Redboard.

### Test Your Button

If the wiring and the code correspond and follow the correct syntax, pressing the pushbutton should publish an Event `buttonPressed` to the Particle Console.   

1.  Visit [https://console.particle.io/events](https://console.particle.io/events)

2.  Watch for incoming Events to your Console.   
<img src="{{ "/images/particle_pub_sub/incoming_console_events.png" | prepend: site.baseurl }}{{ img }}" alt="Incoming Console Events">

### Use IFTTT to Trigger an Email Upon Particle.publish()

IFTTT (If This Then That) is a powerful platform for connecting up services between different applications.  In this section we'll create an "Applet" that connects up the Particle Console to email.

1.  Visit [https://ifttt.com/create](https://ifttt.com/create)

2. Click on the `+this` link.

3. In the search bar, search for "Particle"

4.  Click on the Particle service to select it.

5.  Click on the "Connect" button and enter your Particle username and password.

6.  You will be prompted to grant access to Particle from IFTTT:  "IFTTT has requested access to control, reprogram, and read data from your devices."  Click the "OK" button.

7.  Next, you will be asked to choose a Trigger.  Particle offers several; choose "New Event Published"

    * In the "If (Event Name)" field, type `buttonPressed`
    * Leave the "is (Event Contents)" field blank since the message published by our Photon Redboard does not contain any data.
    * If available, make sure that the "Device Name or ID" dropdown matches the name of your Photon Redboard.
    * Click the "Create Trigger" button to save these settings.

8.  Click on the "+that" link to choose an action service.

9.  "Email" should appear near the top of the grid of options, but you can do a search for "Email" as well.  Click on it.

10.  There is only one action associated with email:  "Send me an email".  Click on it.

11.  You can use the defaults for constructing a message or modify the output.   
   <img src="{{ "/images/particle_pub_sub/ifttt_email_settings.png" | prepend: site.baseurl }}{{ img }}" alt="IFTTT Email Settings">   
   Click the "Create Action" button.

 12.  Review your Applet and click "Finish" to enable it.

 13.  Press the push button switch attached to Pin D0 of your Photon Redboard.  

 14.  You should receive an email each time the button is pressed!!  Spam spam spam!!


 ## Project 2 - Internet Controlled LED

 https://gitlab.oit.duke.edu/colabroots/intro-connected-devices/blob/master/project-2/project-2.ino 
