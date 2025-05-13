import sys # Used to exit the game when the player quits
import pygame

def check_events():
    """Respond to key presses and mouse movements."""
    # Watch for keyboard and mouse events.
    # This allows the game to respond to the inputs of the user
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

def update_screen(ai_settings, screen, ship):
    """Update images in the screen and flip to the new screen"""
    # Redraw the screen every pass through the loop
    screen.fill(ai_settings.bg_colour)
    ship.blitme()
    # Make the most recently drawn screen visible
    pygame.display.flip()
