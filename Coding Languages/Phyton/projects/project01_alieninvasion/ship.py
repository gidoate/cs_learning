import pygame

class Ship():
    def __init__(self, ai_settings, screen): # Screen parameter is the screen where the ship will be loaded/draw
        """Initialize the ship and set it's starting position"""
        self.screen = screen
        self.ai_settings = ai_settings

        # Load the ship image and get its rect.
        self.image = pygame.image.load('C:\\EmbeddedDevelopment\\cs_learning\\Coding Languages\\Phyton\\projects\\project01_alieninvasion\\icons\\ship.bmp')
        self.rect = self.image.get_rect() # This is used to access the surface (screen) rect attribute

        self.screen_rect = screen.get_rect()
        
        # Start each new ship at the bottom center of the screen.
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # Store decimal value for the ship's center (because we are calculating by fractions of a pixel)
        self.center = float(self.rect.centerx)

        # Movement flags
        # Flag moving to right
        self.moving_right = False
        # Flag moving to left
        self.moving_left = False
    
    def update(self):
        """Update the ship's position pased on the movement flag"""
        # Update the ship's center value, not the rect
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.center += self.ai_settings.ship_speed_factor

        if self.moving_left and self.rect.left > 0:
            self.center -= self.ai_settings.ship_speed_factor

        # Update the rect object from self.center
        self.rect.centerx = self.center 

    def blitme(self):
        """Draw the ship at its current location."""
        self.screen.blit(self.image, self.rect)

    