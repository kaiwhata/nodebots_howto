#How to troubleshoot the electronics of your sumobot now that it's assembled.

First and foremost we need to establish where the problem is. 
##If your sumobot starts to emit smoke or smell at any point immediately disconnect the batteries in anyway you can!

If your bot isn't working there are four potential issues:
1. There's something wrong with your battery pack.
2. There's something wrong with your servos.
3. There's something wrong with your wiring.
4. There's something wrong with your photon/arduino.

##Batteries
The battery pack issue seems to be the most common. Your battery pack should contain 4xAA batteries. Check they're all in the right way.
Each provide 1.5V so your battery pack should be providing 6V to your breadboard. Use a multimeter to test the voltage of your battery pack - if it's less than 5.5V then change your batteries.

##Servos
An uncommon issue is servos burning out. If, when you connect the battery pack directly to the red and black leads from the servos (leavng the white control lead disconnected), the servo moves then it's likely broken. You can attempt a repair by using a screwdriver to rotate the potentioeter in the servo (it looks like a plastic screw inside the servo housing) but it's more likely you will need to buy a new servo.

##Wiring
Another massively common issue is incorrct wiring. Check your wiring diagrams again those shown here:
Photon: https://bocoup.com/weblog/controlling-the-robotsconf-sumobot-with-spark-core-johnny-five
Redboard/Arduino: https://bocoup.com/weblog/controlling-the-robotsconf-sumobot-with-arduino-uno-johnny-five

##Photon/Arduino
Check the light on your board. Our [Photon guide](https://github.com/kaiwhata/nodebots_howto/blob/master/photon_install.md) suggests how to fix a Photon issue.
For arduino if the power light isn't on, then the board isn't recieveing enough power, either from batteries or from USB. 
