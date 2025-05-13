import pygame

from settings import Settings
from ship import Ship
import game_functions as gf

def run_game():
    # Initiliaze the game and create the screen object.
    pygame.init()
    ai_settings =  Settings() # Screen settings initialization
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height)) # Tuple to define the dimensions of the screen
    pygame.display.set_caption("Alien Invasion")

    # Create a ship
    ship = Ship(screen)

    # Start the main loop for the game.
    while True:
        gf.check_events()
        gf.update_screen(ai_settings, screen, ship)      

run_game() # To start the game
