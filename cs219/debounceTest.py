import RPi.GPIO as GPIO
import time
from gpiozero import Button

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(25, GPIO.IN)

button = Button(25)

def checkButton():
    for x in range(1,4):
        time.sleep(0.25)
        if(button.is_pressed):
            button.wait_for_release(10)
            return True
        return False

def blink():
    buttonP = False;
    while(buttonP == False):
        GPIO.output(18, True)
        buttonP = checkButton()
        GPIO.output(18, False)
        if(buttonP):
            time.sleep(1)
        else:
            buttonP = checkButton()

while True:
    button.wait_for_press()
    button.wait_for_release(10)
    blink()
    button.wait_for_press()
    button.wait_for_release(10)
    GPIO.output(18,False)
