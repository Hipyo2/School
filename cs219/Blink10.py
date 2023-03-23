import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

for x in range(0,3):
    GPIO.output(18, True)
    time.sleep(.5)
    GPIO.output(18, False)
    time.sleep(.5)
GPIO.cleanup()
