import sys # Used to exit the game when the player quits
import pygame
from bullet import Bullet

def check_keydown_events(event, ai_settings, screen, ship, bullets):
    """Respond to key presses"""
    if event.key == pygame.K_RIGHT:
        # Move the shipt to the right
        ship.moving_right = True
    elif event.key == pygame.K_LEFT:
        # Move the shipt to the left
        ship.moving_left = True
    elif event.key == pygame.K_SPACE:
        # Create a new bullet and add it to the bullets group.
        new_bullet = Bullet(ai_settings, screen, ship)
        bullets.add(new_bullet)

def check_keyup_events(event, ship):
    """Respond to key releases"""
    if event.key == pygame.K_RIGHT:
        # Stop moving to the right if the key is up
        ship.moving_right = False        
    elif event.key == pygame.K_LEFT:
        # Stop moving to the left if the key is up
        ship.moving_left = False 

def check_events(ai_settings, screen, ship, bullets):
    """Respond to key presses and mouse movements."""
    # Watch for keyboard and mouse events.
    # This allows the game to respond to the inputs of the user
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            check_keydown_events(event, ai_settings, screen, ship, bullets)
        elif event.type == pygame.KEYUP:
            check_keyup_events(event, ship)

def update_screen(ai_settings, screen, ship, bullets):
    """Update images in the screen and flip to the new screen"""
    # Redraw the screen every pass through the loop
    screen.fill(ai_settings.bg_colour)
    # Redraw all bullets behind ship and aliens.
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    ship.blitme()
    # Make the most recently drawn screen visible
    pygame.display.flip()
