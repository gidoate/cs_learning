import pygame
from pygame.sprite import Group

from settings import Settings
from ship import Ship
import game_functions as gf

def run_game():
    # Initiliaze the game define the game settings and create the screen object.
    pygame.init()
    ai_settings =  Settings() # Screen settings initialization
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height)) # Tuple to define the dimensions of the screen
    pygame.display.set_caption("Alien Invasion")

    # Create a ship object
    ship = Ship(ai_settings, screen)
    # Make a group to store bullets
    bullets = Group()

    # Start the main loop for the game.
    while True:
        gf.check_events(ai_settings, screen, ship, bullets) # Checks events to relocate the ship
        ship.update() # Updates the ship position based on events and new location calculation
        bullets.update()
        gf.update_screen(ai_settings, screen, ship, bullets) # Updates the screen to display the lates status to user

run_game() # To start the game
