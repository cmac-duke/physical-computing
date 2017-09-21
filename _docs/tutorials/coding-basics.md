---
title: Coding Basics
category: Tutorials
order: 9

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

Functions are simply a way to organize your code into tasks. A function is named section of a program that performs a specific task. 

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







