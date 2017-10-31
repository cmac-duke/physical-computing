// Code for https://cmac-duke.github.io/physical-computing/tutorials/photon-RESTapi/

//pin declarations
int led = D7; // onboard LED
int potentiometer = A0; // pin to read pot value (pot middle terminal)
int power = A5; // will provide constant 3.3v to potentiometer + terminal

// variable to store potentiometer value
int analogvalue;

void setup() {
    // pin IO declarations
    pinMode(led, OUTPUT);
    pinMode(potentiometer, INPUT);
    pinMode(power, OUTPUT);

    // provide power to the potentiometer
    digitalWrite(power,HIGH);


    // Exposes the value of a variable on the Photon to an http GET method
    // syntax:  Particle.variable("PublicName", &local_varName, DATATYPE);
    // where datatypes can be INT, DOUBLE, or STRING
    Particle.variable("potValue", &analogvalue, INT);

    // Exposes a function on the Photon to an http POST method
    // syntax: Particle.function("PublicName", functionName);
    Particle.function("led",ledToggle);
    // ^^ This is saying that when we ask the cloud for the function "led",
    // it will employ the function ledToggle() from this app.
}

void loop() {

    // check to see what the value of the potentiometer is
    // and store it in the int variable analogvalue
    analogvalue = analogRead(potentiometer);

}

// create a function that will take a string "on" or "off"
// and toggle D7 LED based
// ledToggle("on"); turns on the D7 LED
// ledToggle("off"); turns off the D7 LED
int ledToggle(String command) {

    if (command=="on") {
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led,LOW);
        return 0;
    }
    else {
        return -1;
    }

}
