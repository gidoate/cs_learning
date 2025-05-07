magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(magician.title() + ", that was a great trick!")

print("Thank you, everyone. That was a great magic show!") # This is the end of the for loop.

for number in range(1, 5): # The range function generates a sequence of numbers from 1 to 4 (inclusive).
    print(number) # This will print the numbers 1 to 4, one on each line.

nunbers = list(range(1, 6)) # The range function generates a sequence of numbers from 1 to 5 (inclusive).
print(nunbers) # This will print the list [1, 2, 3, 4, 5].

even_numbers = list(range(2, 11, 2)) # The range function generates a sequence of even numbers from 2 to 10 (inclusive).
print(even_numbers) # This will print the list [2, 4, 6, 8, 10].

squares = [] # This creates an empty list to store the squares of numbers.
for value in range(1, 11): # The range function generates a sequence of numbers from 1 to 10 (inclusive).
    square = value ** 2 # This calculates the square of each number.
    squares.append(square) # This appends the square to the list of squares.
print(squares) # This will print the list of squares from 1 to 10.

# The above code can be simplified as follows (the calculation of the square is done directly in the append method):
for value in range(1, 11): # The range function generates a sequence of numbers from 1 to 10 (inclusive).
    squares.append(value ** 2) # This appends the square of each number to the list of squares.
print(squares) # This will print the list of squares from 1 to 10.

statistics = []
statistics.append(min(squares)) # This finds the minimum value in the list of squares.
statistics.append(max(squares)) # This finds the maximum value in the list of squares.
statistics.append(sum(squares)) # This calculates the sum of all the squares in the list.
print(statistics)

# Slicing a list
people = ["Paco", "Manolo", "Ramona", "Julian", "Jacinta"]
print(people[0:3])

# Copying a list
# The [:] it's needed to copy the values into a new address, if not added, what people_copy would get is a pointer to the first address of the list people
# So, if a change is done in the list "people_copy", it will be also present in the list "people", which we do not normally want (we want to modify the copy, not both)
people_copy = people[:] 
people_copy.append("Wenceslao")
people_copy.sort()
print(people)
print(people_copy)