from random import *

state = int(1)


while (state == 1):
    print ("Determining Character Attributes")
    print ("By Matthew Hopson")
    print ("-----")
    print ("")
    state = 2
Option = 1
while (state == 2):
    print ("Please choose option one or two")
    print ("1. Create a NEW character")
    print ("2. Load an old character")

    Option = int(input("Please select one or two: "))
    state = 3

if (Option == 1):
    
    Die12Sided = randint(1,12)
    Die4Sided = randint(1,4)
    StrengthModifier = (Die12Sided/Die4Sided)
    Strength = int(10 + StrengthModifier)

    Die12Sided = randint(1,12)
    Die4Sided = randint(1,4)
    SkillModifier = (Die12Sided/Die4Sided)
    Skill = int(10 + SkillModifier)
    print ("")
    print ("The strength of character one is: ")
    print (Strength)

    print ("The skill of character one is: ")
    print (Skill)
    print ("")

    print ("Character has been created! Would you like to: ")
    print ("1. Go to the main menu?")
    print ("2. Save this character?")

    Option2 = int(input("Please select one or two: "))

    if (Option2 == 1):
        state = 2

    





    
        
       
