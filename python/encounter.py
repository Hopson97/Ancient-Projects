from random import *

print ("Determining the outcome of an encounter")
print ("By Matthew Hopson")
print (" ")
print ("-------------------")
print ("This program will allow you to witness the encounter of two characters. You have two options for the program: ")
print ("1. Input character levels yourself.")
print ("2. Allow for random levels to be generated. Please consider the values of this will be relitivly small (Between 1 and 30).")
Option = int(input("1 or 2? "))
Encounter = bool(False)

print ("-------------------")

if (Option == 1):
    print ("You chose option one.")
    Character1Strength = int(input("What is the strenth level of character one? "))
    Character1Skill = int(input("What is the skill level of character one?"))
    
    print ("")
    
    Character2Strength = int(input("What is the strenth level of character two? "))
    Character2Skill = int(input("What is the skill level of character two?"))

    print ("")

    print ("The encounter is about to begin.")

    input("Press enter to continue to the encounter!")

    

    StrengthMod = int(abs((Character1Strength-Character2Strength)/5))
    SkillMod = int(abs((Character1Skill-Character2Skill)/5))

    if StrengthMod == 0:
        StrengthMod = 1

    if SkillMod == 0:
        SkillMod = 1

    
    Encounter = bool(True)
    print ("-------------------")


if (Option == 2):
    print ("You chose option two.")
    print ("Calculating strength of character one...") 
    Character1Strength = int(randrange(1,30))
    print ("The strength of character one is: ")
    print (Character1Strength)
    print ("")
    print ("Calculating skill of character one...") 
    Character1Skill = int(randrange(1,30))
    print ("The skill of character one is: ")
    print (Character1Skill)
    print("")
    
    print ("Calculating strength of character two...") 
    Character2Strength =  int(randrange(1,30))
    print ("The strength of character two is: ")
    print (Character2Strength)
    print ("")
    print ("Calculating skill of character two...") 
    Character2Skill = int(randrange(1,30))
    print ("The skill of character two is: ")
    print (Character2Skill)

    print ("The encounter is about to begin.")

    StrengthMod = int(abs((Character1Strength-Character2Strength)/5))
    SkillMod = int(abs((Character1Skill-Character2Skill)/5))

    if StrengthMod == 0:
        StrengthMod = 1

    if SkillMod == 0:
        SkillMod = 1

    print (StrengthMod)
    print (SkillMod)

    input("Press enter to continue to the encounter!")
    
    Encounter = bool(True)
    print ("-------------------")

    print (" ")

Round=int(0)

#Encounter Time....

while (Encounter == True):

   
    Round = Round + 1

    print ("Round number:")
    print(Round)
    
    Character2Die = int(randrange(1,6))
    Character1Die = int(randrange(1,6))
  
    
    if (Character1Die == Character2Die):
        print ("Both characters avoided damage!")
        print ("")
        print ("")
        print ("")
               

                  
    elif (Character1Die < Character2Die):                    
        print ("Character Two had a successful attack!")
        Character2Strength = Character2Strength + StrengthMod
        Character2Skill = Character2Skill + SkillMod
        Character1Strength = Character1Strength - StrengthMod
        Character1Skill = Character1Skill - SkillMod

        if (Character1Skill < 0 ):
            Character1Skill = 0
        

        elif (Character2Skill < 0 ):
            Character2Skill = 0

        print ("Character one's skill is now: ")
        print (Character1Skill)
        print ("Character one's strength is now: ")
        print (Character1Strength)
        print ("Character two's skill is now: ")
        print (Character2Skill)
        print ("Character two's strength is now: ")
        print (Character2Strength)
        print ("")
        print ("-----")
        print ("")

    elif (Character1Die > Character2Die):
        print ("Character one had a successful attack!")                
        Character1Strength = Character1Strength + StrengthMod
        Character1Skill = Character1Skill + SkillMod
        Character2Strength = Character2Strength - StrengthMod
        Character2Skill = Character2Skill - SkillMod

        if (Character1Skill < 0 ):
            Character1Skill = 0
        

        elif (Character2Skill < 0 ):
            Character2Skill = 0
        print ("Character one's skill is now: ")
        print (Character1Skill)
        print ("Character one's strength is now: ")
        print (Character1Strength)
        print ("Character two's skill is now: ")
        print (Character2Skill)
        print ("Character two's strength is now: ")
        print (Character2Strength)
        print ("")
        print ("-----")
        print ("")


    if (Character1Strength <= 0 ):
        print ("The battle has ended, and character two won!")
        Encounter = (False)
        Input = input("Press any key to exit.")
      

    if (Character2Strength <= 0 ):
        print ("The battle has ended, and character one won!")
        Encounter = (False)
        Input = input("Press enter to exit.")
     
        
        
    
    
    
    

                             
             

            
