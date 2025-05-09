import sys # Used to exit the game when the player quits
import pygame

def run_game():
    # Initiliaze the game and create the screen object.
    pygame.init()
    screen = pygame.display.set_mode((1200, 600)) # Tuple to define the dimensions of the screen
    pygame.display.set_caption("Alien Invasion")

    # Start the main loop for the game.
    while True:
        # Watch for keyboard and mouse events.
        # This allows the game to respond to the inputs of the user
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
        
        # Make the most recently drawn screen visible
        pygame.display.flip()

run_game() # To start the game
