# A dictionary in Python is a collection of KEY-VALUE pairs
# To define a dictionary, { } shall be used
# Include the KEY and the VALUE
alien_0 = {'colour': 'blue', 'points':5}
print(alien_0['colour'])
print(alien_0['points'])

# Adding a new Key-Value pair
print(alien_0)
alien_0['x_position'] = 25
print(alien_0)

# Modifying values
alien_0['colour'] = 'yellow'
print(alien_0)  

# Removing a Key-Value pair
del alien_0['x_position']
print(alien_0)

# Dictionary of similar objects
favourite_languages = {
    'german': 'c',
    'nicole': 'python',
    'astrid': 'swift'
    }
print("Astrid's favourite languages is " + favourite_languages['astrid'].title() + ", and has been using it for years!")
print("Astrid's favourite languages is " + favourite_languages['astrid'].upper() + ", and has been using it for years!")

# Looping through a dictionary
for key,value in favourite_languages.items():
    print("\nKey: " + key)
    print("Value: " + value)

for k,v in favourite_languages.items():
    print("\nKey: " + k)
    print("Value: " + v)

for name,language in favourite_languages.items():
    print("\nKey: " + name)
    print("Value: " + language)

# Nesting - making a list of dictionaries (and having lists within dictionaries)
alien_0 = {'name' : 'slowy', 'colour' : 'blue', 'speed' : 1, 'vehicle' : ['big', 'rounded', '5-arms']}
alien_1 = {'name' : 'mediowy', 'colour' : 'green', 'speed' : 2, 'vehicle' : ['big', 'rounded', '5-arms']}
alien_2 = {'name' : 'speedy', 'colour' : 'yellow', 'speed' : 3, 'vehicle' : ['big', 'rounded', '5-arms']}

aliens = [alien_0, alien_1, alien_2]

for alien in aliens:
    print(alien)

print('The name of alien 3 is ' + str(alien_2['name'].title()) + " and it's speed is " + str(alien_2['speed']))