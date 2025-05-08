# Defining a function that takes an argument (name is the PARAMETER, the actual name passed into the function is the ARGUMENT)
def greet_user(name): # name is the parameter of the function
    """This function says "Hello" the user"""
    print("Hello, " + name.title() + "!")

user = input("What's your name? ")
greet_user(user) # user is the argument passed into the function

# Passing POSITIONAL ARGUMENTS
# These need to be written in the same order as the parameters are written
def describe_pet(pet_type, pet_name = "XXXX", pet_age = ''): # In this case, there's a defaut value defined for pet_name (XXXX). Pet age is optional because is between ''
    """This function states the type of pet and the name based on the passed arguments"""
    print("My " + pet_type + "'s name is " + pet_name.title())
describe_pet("dog", "bob")

# Passing KEYWORD ARGUMENTS
# A keyword argument is a name-value pair you pass into a function
# Example: 
describe_pet(pet_name='stweart', pet_type='bird') # Arguments are passed in a different order to how parameters have been defined, but doesn't matter
describe_pet(pet_type='cat')

# Return values
def name_formatted(name, surname):
    """This function returns the formatted name of a person to capital first letter of the name and surname, small the rest"""
    full_name = name + ' ' + surname
    return full_name.title()

print(name_formatted('paco', 'perez'))

