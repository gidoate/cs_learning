cars = ["bmw", "audi", "mercedes", "seat"]
addition = 0
for car in cars:
    if car == "bmw":
        print("Your car number " + str(cars.index(car)+1) + " is a BWM")
    elif car == "audi":
        print("Your car number " + str(cars.index(car)+1) + " is an Audi")
    elif car == "mercedes":
        print("Your car number " + str(cars.index(car)+1) + " is an Mercedes")

for car in cars:
    if car == "seat":
        print("You have had a Seat")
    elif car != "seat":
        addition += 1
    
    if addition == len(cars):
        print("There's no Seat in your list, you never had one!")
    
    