#Installing Node and associated libraires for Photons

##OSX (Tested on 10.9.5 and 10.11)

###Install Node
We highly recommend installing node using Homebrew (http://brew.sh/).
Then install the most up to date Node using:

```brew install node```

If you already have node installed using Homebrew then upgrade it to the latest version using:
```brew upgrade node```

To uninstall node using the same syntax use:
```brew uninstall node```

#####DO NOT SKIP THE UPGRADE. Node 0.10.29 has significant improvements over previous versions.

###Install the necessary packages to connect to a Photon (https://www.sparkfun.com/products/13774)

Open a terminal [Finder -> Go -> Utilities -> Terminal] and navigate (using ```cd```) to the directory in which you wish to create and execute your javascript/node code.

Run the following commands to bring your node up to date with all libraries required for communicatoin with the photon:
```npm install johnny-five```
```npm install -g particle-cli```
```npm install particle-io```    
```npm install keypress```
```npm install sumobot```

This downloads the node modules to this folder. To execute node commands subsequently you will need to be in this folder only (or node will throw and error where it cannot find the directories).

###Connect to your photon.
Before running any particle commands, your Photon must be in USB mode. Hold the 'setup' button for 3 seconds (until the light starts flashing blue) to activate it.

Plug the USB cable from the photon into one of the USB ports on your computer. Run the following command to find the device ID of your photon:
```particle identify```

###Setup your particle to connect to local wireless
Run ```particle setup wifi``` and follow the prompts to select SSID and WPA key.

###Update your code with your device ID and access token.
Copy the code from this page (https://bocoup.com/weblog/controlling-the-robotsconf-sumobot-with-spark-core-johnny-five) to a file called sumo.js .
Update the line ```var Spark = require("spark-io");``` to ```var Spark = require("particle-io");```

Now set the acess token by changing ```token: process.env.SPARK_TOKEN,``` to ```token: "<your access token here>",```

Finally set the device ID by changing ```deviceId: process.env.SPARK_DEVICE_2``` to ```deviceId: "<your device ID here>",```

Access tokens available here: https://gist.github.com/PrototypeAlex/8f9957beb9f77c8c8e56

###Execute your javascript/node code
Execute your code with the command:
```node sumo.js```

##Windows (tested on Windows 10) 

Download the node installer from https://nodejs.org/en/download/stable/.

Open the command line (Run -> cmd) and type ```node -v``` to check that node was sucessfully installed.
Follow the OSX commands above for getting the npm libraries from the command line.
Make sure you're downloading them to the appropriate directory where you want to execute them from later.

##Ubuntu Linux

Follow the OSX guide but begin with
```sudo apt-get install node``` or ```sudo apt-get install node --upgrade```. 

Follow the npm install instructions from OSX guide.


##Troubleshooting

###When I run ```node sumo.js``` I get an error message saying the photon can't be found.
- Check your photon is connected to the same wireless network as your laptop. Check your acess token and deivce ID are set correctly (they should both be a long strong of numbers in quotation marks). If th light on your photon is flashing green it means it hasn't sucessfully connected to the local wireless network and you need to run ```particle setup wifi``` again.

###I've followed the commands above but after running ```node sumo.js``` my console prints a line ending in particle-io without an error message and then exits.
- Your photon is probably busted. You could try reflashing its firmware or using a different photon. 
- 
###Re-flashing the firmware - get the nodebots event organiser to perform this for you.
Connect particle via USB, then run `particle setup`. You will need a particle build account for this to work. Sign in with your particle account details and bind the photon to your particle account. Once complete you will need to flash the particle with the `voodoosparck.cpp` following the instructions (here)[https://github.com/voodootikigod/voodoospark]. Make sure to flash the photon using either the command line (hard way) or the particle build website (easy way) here: https://build.particle.io/build/. Depending on your node setup following the sumobot junior build instructions for the arduino base (git clone the repo and npm modules then run npm i) may also help. 

350047000947343432313031


###The light on my photon is X colour. What does it mean?
- Flashing Green - attempting to connect to  wireless network.
- Breathing Blue - sucessfully connected to local wireless.
- Flashing Blue - awaiting commands via USB.
- Red - low power. Replace your batteries.
- Blue and White and Orange - Photon is booting.
- LED off - Photon is not getting any power.

