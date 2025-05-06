# Defining lists of different types of vehicles
bycicles = ["BMX" , "Mountain Bike", "Road Bike", "Hybrid Bike"]
cars = ["Sedan", "SUV", "Truck", "Coupe"]
motorcycles = ["Cruiser", "Sport Bike", "Touring Bike", "Dirt Bike"]
trucks = ["Pickup Truck", "Box Truck", "Flatbed Truck", "Dump Truck"]

# Printing BMX Coupe Touring Bike Box Truck
print(bycicles[0].title()+ " is a type of bycicle, \n" + 
      cars[3].title() + " is a type of car, \n" + 
      motorcycles[2].title() + ", \n" +
      trucks[0].title()) 

# Changing an element in a list
bycicles[0] = "BMX Bike"
print(bycicles[0].title())

# Adding an element to a list
# Append method adds an element to the end of the list
bycicles.append("Electric Bike")
print(bycicles)

# Append method can be used to create the list
buses = [] # Empty list
buses.append("School Bus")
buses.append("City Bus")
buses.append("Tour Bus")
print(buses)

# Deleting an element from a list
# del statement deletes an element from the list
del buses[0] # Deletes the first element of the list
print(buses) # ["City Bus", "Tour Bus"]

# .pop() method removes the LAST element from the list and returns it
popped_buses = buses.pop()
print("The last bus I owned was a " + popped_buses.upper() + ".")

# .pop(#) method removes the element at the specified index and returns it
popped_buses = buses.pop(0) # Removes the first element of the list     
print("The first bus I owned was a " + popped_buses.upper() + ".")

# .sort() method sorts the list in alphabetical order
cars.sort() # Sorts the list in alphabetical order
print(cars) # ["Coupe", "Sedan", "SUV", "Truck"]

# len() function returns the length of the list
print("The number of cars I own is " + str(len(cars)) + ".") # Converts the length to a string and prints it

