from bottle import route, run, template, static_file, request
import serial, os
from time import sleep
import RPi.GPIO as GPIO
import picamera

#Hi ENGR101. Please dont judge me for this terrible code
#it was late and I was tired and maybe a little hungover
#wgtnandroidhackathon

#@route('/')
#def hello():
#    return template("index")

@route('/',method='POST')
def index():
   # print request.json
    return "DONE"

@route('/image')
def takepicture():
    camera.capture('image.jpg')
    return static_file('image.jpg', root="/home/pi/Roverserver")

@route('/drive/<time>/<leftmotordir>/<leftPWM>/<rightmotordir>/<rightPWM>')
def drive(time, leftmotordir, leftPWM, rightmotordir, rightPWM):
    #this drives both motors with a direction and PWM value for a certain time
    print "Motor On\n"
    GPIO.output(16, (rightmotordir=='True')) #right direction
    #GPIO.output(19, False) #right PWM
    GPIO.output(20, (leftmotordir=='True')) #left direction
    #GPIO.output(21, True) #leftpwm pin

    frequency = 50
    left = GPIO.PWM(19, frequency)
    right = GPIO.PWM(21, frequency)
    left.start(1.0)
    right.start(1.0)

    left.ChangeDutyCycle(float(leftPWM))
    right.ChangeDutyCycle(float(rightPWM))
    sleep(float(time))

    left.ChangeDutyCycle(1.0)
    right.ChangeDutyCycle(1.0)

    left.stop()
    right.stop()

    print "Motor Off\n"
    GPIO.output(16, False) #inA
    GPIO.output(19, False)
    GPIO.output(20, False) #inB
    GPIO.output(21, False)
    return "Motor Data"
    

@route('/PWM/<pin>/<value>')
def PWM_motor1(pin, value):
    #this attmpts to PWM a specific pin and duty cycle on the pi using a RESTFUL API
    channel = int(pin)
    frequency = 50
    dutycycle = float(value)
    p = GPIO.PWM(channel, frequency)
    p.start(1.0)

    print "PWM on "+pin+" at "+value+"\n"
    GPIO.output(16, False)
    GPIO.output(20, True)
    p.ChangeDutyCycle(dutycycle)
    sleep(5)

    print "PWM on "+str(pin)+" off\n"
    p.ChangeDutyCycle(1.0)

    p.stop()

    return "PWM'd"

#initialises Rpi camera and defines resolution
camera = picamera.PiCamera()
camera.resolution = (320, 240)

#usually goes at end of program. I have put it at start because server will usually be interrupted.
#this will undo any existing PWM on the GPIO ports
GPIO.cleanup()

#sets board numbering
GPIO.setmode(GPIO.BCM)
GPIO.setup(16, GPIO.OUT)
GPIO.setup(20, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)
GPIO.setup(19, GPIO.OUT)

#sets pins for output
GPIO.output(16, False)
GPIO.output(19, False)
GPIO.output(20, False)
GPIO.output(21, False)

run(host='10.140.126.90', port=8080, debug=True)

