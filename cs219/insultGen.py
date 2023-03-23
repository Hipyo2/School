from random import choice

def printInsult():
    username = raw_input("What is your name? ")
    age = raw_input("What is your age? ")
    ageValue = int(age)
    adjectives = ["wet", "big", "large", "small", "tired", "sad", "frozen", "blue", "green", "angry", "mean"]
    nouns = ["dog","rat", "mouse", "ant", "snake", "rabbit", "cat", "turnip", "radish", "potato"]
    if (ageValue < 16):
        ageAdjective = "a young"
    else:
        ageAdjective = "an old"
    userInput = ""
    while(userInput != "no"):
        print("")
        for count in range(0,3):
            print(username + ", you are " + ageAdjective + " " + choice(adjectives) + " " + choice(nouns) + ".")
        print("")
        userInput = raw_input("Do you want more insults? ")
