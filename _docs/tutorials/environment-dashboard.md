---
title: Extending the Environment Monitor - Cayenne Dashboard
category: Tutorials
order: 3

---

<img src="{{ "/images/cayenne/environment-monitor-fritzing_bb.png" | prepend: site.baseurl }}{{ img }}" alt="Environment Monitor Wiring Diagram">


This tutorial builds off of [Experiment 6: Environment Monitor](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-6-environment-monitor) of the [Sparkfun Inventor's Kit for Photon Experiment Guide](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide).  As you will recall, your homework for today's class was to complete [Experiment 6](https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-6-environment-monitor) up to "Part II:  Posting Environmental Data to data.sparkfun.com."   Because [data.sparkfun.com](https://data.sparkfun.com/) and its associated data logging engine [Phant](https://github.com/sparkfun/phant) are currently not allowing the creation of new data streams, we have to look to other IoT cloud platforms.

We've already made some use of Particle's console (and its Publish/Subscribe i/o schema).  Let's explore another one!  There are many options to choose from, each with its own unique feature-set and pros/cons, including:
* [ThingSpeak](https://thingspeak.com/)
* [freeboard](https://freeboard.io/)
* [dweet.io](https://dweet.io)
* [thinger.io](https://thinger.io/)
* [Blynk](http://www.blynk.cc)
* [Samsung Artik Cloud](https://artik.cloud/)

In this tutorial, we will use [myDevice's Cayenne IoT Project Builder](https://mydevices.com/cayenne/features/).

<img src="{{ "/images/cayenne/cayenne.jpg" | prepend: site.baseurl }}{{ img }}" alt="Cayenne Logo">
