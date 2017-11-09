---
title: Node Red Raspberry Pi
category: Tutorials
order: 11

---

## Node Red
Node-RED is a programming tool for wiring together hardware devices, APIs and online services in new and interesting ways.

It provides a browser-based editor that makes it easy to wire together flows using the wide range of nodes in the palette that can be deployed to its runtime in a single-click.

<img src="{{ "/images/node_red/site.png" | prepend: site.baseurl }}{{ img }}" alt="">
The easiest way to get node-red is via npm. Type in the command lines:

```
sudo npm install -g --unsafe-perm node-red
```

To start Node Red run:

```
 node-red
```

You should now have Node Red running on port 1880

```
Welcome to Node-RED
===================

25 Jun 22:51:09 - [info] Node-RED version: v0.17.4
25 Jun 22:51:09 - [info] Node.js  version: v6.11.1
25 Jun 22:51:09 - [info] Loading palette nodes
25 Jun 22:51:10 - [warn] ------------------------------------------
25 Jun 22:51:10 - [warn] [rpi-gpio] Info : Ignoring Raspberry Pi specific node
25 Jun 22:51:10 - [warn] ------------------------------------------
25 Jun 22:51:10 - [info] Settings file  : /home/nol/.node-red/settings.js
25 Jun 22:51:10 - [info] User Directory : /home/nol/.node-red
25 Jun 22:51:10 - [info] Server now running at http://127.0.0.1:1880/
25 Jun 22:51:10 - [info] Creating new flows file : flows_noltop.json
25 Jun 22:51:10 - [info] Starting flows
25 Jun 22:51:10 - [info] Started flows
```

open up chrome, and navigate to http://127.0.0.1:1880/

<img src="{{ "/images/node_red/interface.png" | prepend: site.baseurl }}{{ img }}" alt="">

You should see the interface for node red. On the left panel, you'll find "nodes", which are predefined function that we can connect together for our program. The center panel is where you'll develop you program, and the right panel is various options and debuggers.



