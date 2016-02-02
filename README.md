# Nodebots 101
So you've heard about Nodebots and have decided you want to run your own event (or you have had an event thrust upon you), but you don't have the faintest idea where to start. Fear not - Nodebots Wgtn is here to help. This repo contains a series of non-technical resources for helping you plan, check and run a Nodebots event without worrying that you've forgotten something.
As we progress we will also try and build this into some form of curriculum too (but baby steps!).

Comments, edits and criticisms are all welcome.

##Technical links
* Getting the [FTDI drivers for Sparkfun Redboard installed](https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/all) on many operating systems (required for the Arduino IDE to work).
* Getting [Sparkfun Photons up and running](https://github.com/kaiwhata/nodebots_howto/blob/master/photon_install.md).
* [Sumobot electronics troubleshooting](https://github.com/kaiwhata/nodebots_howto/blob/master/electronics_troublshooting.md) 

##Pre-event Preparation

* Get your event listed on [Nodebots.io](http://nodebots.io/).
* Get RSVPs for your event using [Google forms](https://www.google.com/forms/about/) or [Eventbrite](https://www.eventbrite.com).
* Decide your audience (age range) and then your content.
* Figure out what kit you need.
* Sort out a venue and a team to help out for the day (an open office, hall or school classrooms is ideal. you need enough floor space for an arena).
* Decide if you are going to provide computers if if attendees are expected to bring their own. (N.B. whilst the former is more work for you it allows you to test everything prior to the day. If you choose the latter be prepared to spend at least a couple of hours troubleshooting the installation of Node.js, Johnny 5 and possibly the Arduino IDE on people's computers. You can make this easier in yourself by only offering support for a single type of operating system and having all necessary install files on a flash drive.)
* Have an idea when your next event (or another local robotics or programming event) will run. You will get asked what attendees can do next. 

###Venue Checklist
- [ ] Powerpoints, extension cords, multiboards to power computers.
- [ ] On-site computers or attendee laptops? - one per kit is ideal.
- [ ] Is wireless network activity required? - if so have you tested the router with a large number of simultanoues connections? How will you communicate the passcode?
- [ ] Is wireless internet connectivity required? - Do you have sufficient login details for everyone? If they're sharing logins have you tested logging in simultanouesly from multiple devices?
- [ ] How will you lay out/mark out your arena? Ducktape is a cheap easy solution.
- [ ] Do you need a projector or speaker and microphone?

###Technology Prerequisites
- [ ] Node.js installed from [here](https://nodejs.org/en/)
- [ ] Johnny-Five installed from [here](https://github.com/rwaldron/johnny-five) or using `npm install johnny-five`
- [ ] Do your arduinos have StandardFirmata running on them? (Arduino -> File -> Examples -> Firmata -> StandardFirmata + Upload)
- [ ] Do your attendees know how to access a terminal or command line? (WindowsKey+R, 'run' and Enter)
- [ ] Do your attendees know how to create a script?  `nano <script_name>.js`
- [ ] Do your attendees know how to run a script from the command line? `node <script_name>.js`
- [ ] Do you have a hardcopy of the examples in case your internet dies on the day (yes it happens)? Available [here](https://github.com/rwaldron/johnny-five)

###Helper Checklist
- [ ] Have you got a list of all your helpers, plus their email addresses and cellphone numbers and have your shared it with all of them?
- [ ] Are your helpers aware of what to do in an emergency situation; fire, earthquake, evacuation etc.
- [ ] If your helpers are going help with technical support, have they got previous experience with Nodebots or will you run a training session for them?
- [ ] Have you give your helpers a runsheet for the day so they know times, dates and what's they're expected to do?

###Equipment List
- [ ] Plentiful supply of AA batteries (at least 4 per kit).
- [ ] Ensure you have at least one working Nodebot model to show off. It helps keen people's attention and interest if they get stuck.
- [ ] Soldering iron (for on-site repairs) and solder.
- [ ] Multimeter (Troubleshooting).
- [ ] 1x phillips head screwdriver per kit.
- [ ] Scissors/Knife (for cutting cable ties).
- [ ] Hot glue gun (attaching tread and components).
- [ ] Additional female to male adapters (for servo leads).
- [ ] Bolt cutters (form trimmming screw thread after attachment).
- [ ] Pens and stickers for nametags (and post-it notes for feedback).
- [ ] Kits.

###Sumo Bot Kit 
- [ ] 2x laser-cut wheels screwed onto servo horn. 
- [ ] 2x 360 degree continuous rotation servos.
- [ ] 1x Breadboard with adhesive base.
- [ ] 1x 4x AA Battery holder.
- [ ] 1x Controller (Arduino etc) + USB cable.
- [ ] 1x 3D printed ball bearing mount.
- [ ] 1x Ball bearing.
- [ ] Cable ties (assorted) - suggest at leadt 5 per kit.
- [ ] 14x frame attachment screws (3.5mm). 
- [ ] 2x servo horn attachment screws (3.5mm but longer then the others)

##On-day preparation
We recommend send out a reminder email to attendees the night before (Eventbrite does this automatically) including:
* Time.
* Date.
* Location.
* Cost.
* Parking suggestions.
* A contact phone number if there are issues.
* What they need to bring or have installed on their device.
* Event hastag and website.

###Health and Safety
Health and safety shouldn't be strenuous, but be repared for something to go wrong. It will always come in handy to:
* Have all helpers know a safe spot to evacuate to.
* Have a supply of plasters, a dustpan and brush and a blanket.
* Have know where the nearest fire extinguisher is.
* Let attendees know that it's unikely but batteries can rupture and electronics can start to smoke and occasionally catch fire. Ruptured or swollen batteries should be discarded using the dustan and brush. Smoking electronics should be disconnected from their power source and/or smothered with a blanket (or CO2 fre extinguisher). It's very hard to hurt yourself seriously with the contents of Nodebots kits.

###Runsheet
Have several hard copies of this available (or an easy-to-find soft copy).

| Time  | Activity  | People Required | 
| :------------ |:---------------:| ------: |
| 8:00am      | Team setup begins | All team |
| 9:30am     | Attendees begin to arrive / registration desk opens | Rego team |
| 10:00am | Event starts with 20 min introduction (Our slides [here]()) | Event leader |
| 10:30am | Split into groups and short icebreaker exercise  | 
| 12:00pm | Groups report back (problems and solutions) and show off  |
| 12:30pm | Lunch break (show youtube videos of other Nodebot groups during this time)|
| 1:00pm | Construction resumes |
| 2:30pm | Final demos/competition | Event leader |
| 3:00pm | Event close/Packdown begins |
| 3:30pm | Final attendee asked (politely) to leave | Event leader |
| 4:00pm | Packdown finishes and team celebrates | All team |

For an evening event (consider running evening events as adult only because of tight timelines):

| Time  | Activity  | People Required | 
| :------------ |:---------------:| ------: |
| 4:00pm      | Team setup begins | All team |
| 5:00pm     | Attendees begin to arrive / registration desk opens | Rego team |
| 5:30pm | Event starts with 10 min introduction (Our slides [here]()) | Event leader |
| 5:40pm | Split into groups and short icebreaker exercise | 
| 5:45pm | Construction begins | 
| 6:30pm | Groups report back (problems and solutions) and show off  |
| 7:00pm | Dinner break (show youtube videos of other Nodebot groups during this time) |
| 7:30pm | Construction resumes |
| 8:30pm | Final demos/competition | Event leader |
| 9:00pm | Event close/Packdown begins |
| 9:30pm | Final attendee asked (politely) to leave | Event leader |
| 10:00pm | Packdown finishes and team celebrates | All team |

####Helpful hints
Here's a few suggested things to have to make your day go smoothly and ensure a positive reception.
 - [ ] Have snacks (museli bars/fruit/chocolate etc) for your helpers. They'll need their energy.
 - [ ] Have some spot prizes for quick construction, innovation, creativity, technical expertise (or whatever you want).
 - [ ] Have a list of some additional resources for people to investigate in their own time, like [these]().
 - [ ] Have post-it and pens notes available to people to write comments, criticisms, feedback and ideas on and a board or wall to attach them to. Photograph them afterwards and keep a copy (event better post it to all of us!). This gives you valueable feedback (and you'll also get nice comments that make you feel warm and fuzzy inside, if you're not a robot). It also gives you some data to feed back to your sponsors!

####Comments about learning
Yes everyone learns in their own style at their own unique pace. That said there are a few things you can do to encourage learning and enthusiasm.
* Set achieveable goals. If your event is 4 hours of build time, pick a bot that can be safely assembled and tested in 3 hours. People learn more and retain the information for longer if they suceed in a challenge compared to if they run out of time to complete a task.
* Have extension challenges that are hard. While having a main challenge that's easily achieveable, also have a few extension challenges for people to aspire too. You can let people choose their own but having a couple of good examples will help people come up with their own projects. A nice extension for the sumo bot can be teaching your bot to navigate like a roomba (which requires collision detection and randomised turning).
* Try not to make people feel stupid. People are going to ask you and your team stupid questions, try not to take it personally. Be as patient as you can, but be aware that there are people who will simply expect you to do everything for them. So don't be afraid to tell people to figure it out for themselves or Google it if you run out of patience.
