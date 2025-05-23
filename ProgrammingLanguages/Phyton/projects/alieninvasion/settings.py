class Settings():
    """A class to store the settings for Alien Invasion"""
    
    def __init__(self):
        """Initialize the game settings"""
        # Screen settings
        self.screen_width = 1200
        self.screen_height = 700
        self.bg_colour = (230, 230, 230)

        # Ship settings
        self.ship_speed_factor = 1.5

        # Bullet settings
        self.bullet_speed_factor = 0.25
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = 60, 60, 60