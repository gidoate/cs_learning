# To ask for an input from the user, use input() function
# This function assumes that what's going to be introduced is a STRING
message = input("What's your name? ")
print("Hi, " + message)

# Entering a numerical input 
# Using int()
age = input("What's your age? ")
age = int(age)
if age > 17:
    print("You can vote")
else:
    print("You cannot vote")


