---
title: Coding Basics
category: Tutorials
order: 5

---

# Reference

https://www.arduino.cc/en/Reference/HomePage


This is a quick overview and refresher for the Arduino programming language that we'll be working with throughout this semester. Arduino is based on C++ and carries similar synax and conventions.

---

# VARIABLES

### Common Data Types
```c++
float a = 1.117;

int b = 2;

boolean c = false;

char d = 'A';
```


### Common Constants
```c++
HIGH / LOW

INPUT / OUTPUT
```

---

# STRUCTURE

### If Statement

If statements state that "if something (is equal, less-than, greater-than, true etc.)", exectue the code inside the statement. For instance, in the statement below, if the variable "someVariable" is greater than 50, print "hello world"

```c++
if (someVariable > 50){
    println('hello world')
}
```

### If-Else Statement

If-else statements state that "if something (is equal, less-than, greater-than, true etc.)", exectue the code inside the "if" statement brackets, otherwise, execute the code "else" statement brackets. For instance, in the statement below, if the variable "someVariable" is less than than 50, print "hello world", otherwise, print "goodbye world".

```c++
if (someVariable < 50){
  println('hello world')
}else{
  println('goodbye world')
}
```

### For-Loop

For statements are a bit more obtuse, but if you follow the initial logic, everything should fall into place. For-loops work by "looping" over a variable, until that variable reaches a certain value. As you can see a for loop is comprised of three inital smaller statements: `int i=0; i < 255; i++`

Lets break down these statments so that we understand them individually.

 We'll start by defining a variable. Traditionally, this variable is "i", but ultimately it can be anything you want.  Here, we'll set an integer variable "i" equal to 0.
`int i=0`

The next two statements act much like an "if" statment. Here if "i" is less than 255, then "i++". What is `i++`? `i++` is a shortened syntax for "add 1 to the value" or i+1. So we're saying, "if i is less than 255, add 1 to i"
`i < 255; i++`

If we consider the for-loop below, we are starting with the variable "i" equalling zero, and the code inside of the for-loop will be executed every time until "i" is equal to or greater than 255.

So this for-loop will print "hello world" 255 times.

```c++
for (int i=0; i < 255; i++){
      println('hello world')
}
```

---

# Functions

Functions are simply a way to organize your code into tasks. A function is named section of a program that performs a specific task. Functions help you reuse code without having to rewrite the code.

To execute or "call", a function you can simply type the name of the function with parenthases


Each program will start with the two functions that are pre-defined: `void setup()` and `void loop()`

### Void Setup

```c++
void setup(){

}
```

void setup is a function where you "set up" your program. Typically, this mean where you will 'set up' you pins to thier respective modes, and set your Serial baud rate.

The`void setup()` is called once, when the sketch starts after each powerup or reset of the Arduino board.

### Void Loop


```c++
void loop(){

}
```

void loop is a function that "loops" over the code continuously. This is where the majority of your code will live, including all of the actions your board will take.  

The`void loop()` is continuously, allowing your program to change and respond to incoming data.

### Common Pre-defined Variables

```c++
pinMode()
digitalWrite()
digitalRead()

analogReference()
analogRead()
analogWrite()
```


### Defining your own function

We just saw that there are many pre-defined functions that Arduino gives to us out of the box. But what if we want to write our own? Writing your own functions are pretty straightforward.

```c++
void blinkLED(){
  digitalWrite(ledPin, HIGH);
  delay(1000);                  
  digitalWrite(ledPin, LOW);    
  delay(1000);                  
}
```

We can also give the function variables. Much like you we used `tone` in the last assignment, where `tone(pin, frequency, duration)` we can also say `blinkLED(delayTime)` where "delayTime" is whatever variable we want it to be.

```c++
void blinkLED(int delayTime){
  digitalWrite(ledPin, HIGH);
  delay(delayTime);                  
  digitalWrite(ledPin, LOW);    
  delay(delayTime);                  
}

```

Then we can call that function

```c++
int ledPin = 9;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
 blinkLED(100);//call the function here with a "delayTime"
}


void blinkLED(int delayTime){
  digitalWrite(ledPin, HIGH);
  delay(delayTime);                  
  digitalWrite(ledPin, LOW);    
  delay(delayTime);                  
}
```

So what if we have a function that makes a calculation. How to we get, or "return" that value?

Functions that return a value are defined by the value return type at the outset. For instance, if the return value is a `float` the function will start with
```
float myFunction(float theFloat)
```

Lets make a simple function that calculates the amout of money that we have

```c++

int calculateMoney(int Wallet, int Bank){
    int Total;

    Total = Wallet + Bank;

    return Total;
}  
```

We can then call our function in the main body of our code

```c++
void setup(){
  Serial.begin(9600);
}

void loop(){
 int allmyMoney = calculateMoney(200, 400);//call the function here with a
 Serial.println(allmyMoney);
}


int calculateMoney(int Wallet, int Bank){
    int Total;

    Total = Wallet + Bank;

    return Total;
}
```
