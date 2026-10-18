
Calc = int


print ("Human years to dog years calculator.")
print ("----")

print("")
HumanYears = int(input("Please enter your dogs age in \"Human Years\" "))

if (HumanYears < 3):
    DogYears = (HumanYears*10.5)

    print ("Calculating age of dog...")
    print ("Calculation complete.")
    print ("")

    print ("Your dogs age is:")
    print (DogYears)
    Exit = input("Press enter to exit. ")

if (HumanYears > 2):
    Calc = HumanYears - 2
    DogYears = (21+(Calc*4))

    print ("Calculating age of dog...")
    print ("Calculation complete.")
    print ("")

    print ("Your dogs age is:")
    print (DogYears)
    Exit = input("Press enter to exit. ")
