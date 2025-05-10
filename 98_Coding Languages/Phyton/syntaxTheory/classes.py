class Dog():
    """Simple attempt to model a dog."""
    def __init__(self, name, age): # Age and name are the attributes of the class
        """Initialize the name and age attributes"""
        self.name = name
        self.age = age

    def sit(self): # This is a behaviour of the class
        """Simulate the dog is sitting in response to a command"""
        print(self.name.title() + " is now sitting")
    
    def roll(self): # This is another beavhiour of the class
        """Simulate the dog rolloed over in response to a command"""
        print(self.name.title() + " rolled over!")

my_dog = Dog("paco", 5)
print("My dog's name is " + my_dog.name.title())
print("My dog's age is " + str(my_dog.age))

my_dog.sit()
my_dog.roll()