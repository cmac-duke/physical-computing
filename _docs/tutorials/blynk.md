---
title: Blynk
category: Tutorials
order: 3

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

<img src="{{ "/images/blynk/blynk.jpg" | prepend: site.baseurl }}{{ img }}" alt="Blynk Logo">

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

3. 
