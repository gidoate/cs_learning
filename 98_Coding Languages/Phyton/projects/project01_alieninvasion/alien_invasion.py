import sys # Used to exit the game when the player quits
import pygame

from settings import Settings
from ship import Ship

def run_game():
    # Initiliaze the game and create the screen object.
    pygame.init()
    ai_settings =  Settings()
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height)) # Tuple to define the dimensions of the screen
    pygame.display.set_caption("Alien Invasion")

    # Create a ship
    ship = Ship(screen)

    # Start the main loop for the game.
    while True:
        # Watch for keyboard and mouse events.
        # This allows the game to respond to the inputs of the user
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        # Redraw the screen every pass through the loop
        screen.fill(ai_settings.bg_colour)
        ship.blitme()
        
        # Make the most recently drawn screen visible
        pygame.display.flip()

run_game() # To start the game
