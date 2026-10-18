print ("Welcome to circle calculator. Type '0' if irrelevent")

pi = 3.14

a = int(input("Angle of the section: "))

r = int(input("Radius of the section: "))

rc = int(input("Radius of circle: "))

ans = (a/360*2*pi*r)
int(ans)

print (" ")
print ("The length of the arc is:")
print (ans)
print (" ")
print ("The area of the section is:")
print (a/360*pi*r**2)
print (" ")
print ("The circumrence of the circle is:")
print (2*pi*rc)
print (" ")
print ("The area of your circle is:")
print (pi*rc**2)


print (input("Press the enter key to exit"))




