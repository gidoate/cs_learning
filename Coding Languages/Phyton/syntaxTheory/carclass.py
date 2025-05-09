# Definition of a class to model a car
class Car():
    """An attempt to model a car"""
    def __init__(self, make, model, year):
        """Init the attributes of the car"""
        self.make = make
        self.model = model
        self.year = year
    
    def get_description(self):
        """Return the formatted name"""
        long_name = str(self.year) + ' ' + self.make + ' ' + self.model
        return long_name.title()

my_new_car = Car ('audi', 'a3', '2000')
print(my_new_car.get_description())

# Definition of a new class, for electric cars, INHERITING the attributes and methods from the class Car
class ElectricCar(Car):
    """Includes the aspects of the car that are not included in the standard car class"""
    def __init__(self, make, model, year):
        """Initialize the attributes of the parent class"""
        super().__init__(make, model, year)
        self.battery_size = 20

    def describe_battery(self):
        """Print a statement describing the battery size."""
        print("This car has a " + str(self.battery_size) + "-kWh battery.")

my_tesla = ElectricCar('tesla', 'model s', 2016)
print(my_tesla.get_description())
my_tesla.describe_battery()