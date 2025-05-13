import pygame

class Ship():
    def __init__(self, screen): # Screen parameter is the screen where the ship will be loaded/draw
        """Initialize the ship and set it's starting position"""
        self.screen = screen

        # Load the ship image and get its rect.
        self.image = pygame.image.load('C:\\EmbeddedDevelopment\\cs_learning\\98_Coding Languages\\Phyton\\projects\\project01_alieninvasion\\icons\\ship.bmp')
        self.rect = self.image.get_rect() # This is used to access the surface (screen) rect attribute

        self.screen_rect = screen.get_rect()
        
        # Start each new ship at the bottom center of the screen.
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

    def blitme(self):
        """Draw the ship at its current location."""
        self.screen.blit(self.image, self.rect)