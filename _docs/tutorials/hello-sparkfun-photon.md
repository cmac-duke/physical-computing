---
title: Getting Started w/ Sparkfun Photon
category: Tutorials
order: 3

---

<img src="{{ "/images/hello_photon/sparkfunphoton.jpg" | prepend: site.baseurl }}{{ img }}" alt="">

Part I: Setup your Photon

Step 1: Install Particle CLI:

If you are a Windows user:

You need to download Particle Windows Installer. This installer can install everything you need automatically.

If you are a Mac/Linux user:

First, you need to download Node.js from here['https://nodejs.org/en/download/']. 

<img src="{{ "/images/hello_photon/node.png" | prepend: site.baseurl }}{{ img }}" alt=""> 

Install Node.js

<img src="{{ "/images/hello_photon/node-install.png" | prepend: site.baseurl }}{{ img }}" alt="">

Open your terminal, and type 

`$ npm install -g particle-cli` 

This command will install Particle CLI to your computer. You may see some errors along the way, but if everything works, you should see an output similar to this:

<img src="{{ "/images/hello_photon/photoncli.png" | prepend: site.baseurl }}{{ img }}" alt=""> 

Step 2: Set up Your Particle Account.

If you haven't created a Particle account, click here to create a new account.

<img src="{{ "/images/hello_photon/particleweb.png" | prepend: site.baseurl }}{{ img }}" alt=""> 

After you have an account, open your terminal/command line and type `$ particle login`, then follow the instructions to log in to your Particle account.

Step 3: Connect your photon using the USB

Connect your particle device to your computer.

Step 4: Get the Mac Address of Your Photon

In your terminal, run `particle serial mac` to get the photon’s mac address (must be in green listening mode)

Step 5: Register Your Device to Duke Open

Register your photon at https://dukereg.duke.edu/. (You will need to login with your NetId).

Step 6: Claim and Set up Your Photon

In your terminal, run `particle setup` and then CAREFULLY follow the instructions on the screen. You may need to press the SETUP botton of your Photon at the beginning so your computer can recognize it. When selecting Wi-Fi options, be sure to use DukeOpen and choose none for suriecty settings. You should be good to go after it finishes that. You’ll know it’s connected when it is breathing blue.

Part II: Deploy your Code to Photon

Step 1: Log in to your Photon Account.

Type `particle login` in your terminal/command line window and then follow the instruction to login to your account.

Step 2: Deploy your Code

If you have only one file to deploy, just type `particle flash DeviceName FileName.ino`. Note this command is only useful when your file is in your working directory. If the file is not in your working directory, you can either use $ cd to go to the working directory or replace the name of your file with absolute file path. If your code is contained in serveral files, create a new folder and then put all the files (Include .h and .cpp library files) to that same folder, and then use $ particle flash DeviceName path/folder to deploy your code. The path/folder argument should be your folder's absolute file path.

Tips:

If you need to transfer your photon to other users, be sure to go to Particle Console and deregister it. Otherwise, other users will not be able to claim this device. If you have any other questions, please refer to Particle CLI Docs for help.