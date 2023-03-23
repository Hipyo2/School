import RPi.GPIO as GPIO
import time
from gpiozero import Button

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(25, GPIO.IN)

button = Button(25)

try:
    while True:
        button.wait_for_press()
        button.wait_for_release()
        time.sleep(.25)

        while(button.is_pressed == False):
            GPIO.output(18, True)
            time.sleep(.25)
            GPIO.output(18, False)
            time.sleep(.25)

        button.wait_for_press()
        button.wait_for_release()
        time.sleep(.25)
        GPIO.output(18, False)

except KeyboardInterrupt:
    GPIO.cleanup()
