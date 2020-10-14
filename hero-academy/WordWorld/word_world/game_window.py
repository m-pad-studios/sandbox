import pygame
import time
import text_input
from string_manipulator import WordSmith

class GameWindow():
    def __init__(self, screen, background_color, width = 1200, height = 1200):
        
        
        self.background_color = (0,0,0)
        self.width = width
        self.height = height
        self.screen = screen
    
    def smith(self, x, y):
        smith_img = pygame.image.load('C:\\Users\mpark\Documents\GitHub\WordWorld\word_world\smith.jpg')
        self.screen.blit(smith_img, (x, y))

    def do_rectangle_demo(self, screen):
         _width_input = 500.00
         _height_input = 500.00
         _x_input = _width_input * 0.40
         _y_input =  _height_input * 1.0
         
         color = (40, 210, 250)
         rect = (_x_input, _y_input, 700, 500)
         width = 1
         # draw a rectangle
         pygame.draw.rect(screen, color, rect, width)

    def text_objects(self, text, font):
        text_color = (100,252,0)
        textSurface = font.render(text, True, text_color)
        return textSurface, textSurface.get_rect()
        
    def message_display(self,text):
        largeText = pygame.font.Font('freesansbold.ttf', 5)
        TextSurf, TextRect = self.text_objects(text, largeText)
        TextRect.center = ((self.width/2), (self.height/2))
        self.screen.blit(TextSurf, TextRect)

        pygame.display.update()

    def forge(self, text):
        self.message_display(text)

    def settings(self):
        smith_width = 500.00
        smith_height = 500.00
        x = smith_width * 0.45
        y = smith_height * 0.001

        _width_input = 500.00
        _height_input = 500.00
        _x_input = _width_input * 0.45
        _y_input =  _height_input * 1

        textinput = text_input.TextInput()
        self.screen = pygame.display.set_mode((self.width, self.height))
        clock = pygame.time.Clock()
        pygame.display.set_caption("Word Wuurld")
        
        self.do_rectangle_demo(self.screen)
        self.smith(x, y)
        pygame.display.flip()
       
        running = True
        flash = True
        while running:
            self.do_rectangle_demo(self.screen)
            self.smith(x, y)
            self.screen.blit(textinput.get_surface(), (_x_input, _y_input))
            pygame.display.flip()
            self.screen.fill(self.background_color)
            events = pygame.event.get()
            
            for event in events:
                if event.type == pygame.QUIT:
                    running = False
                    flash = False

            if textinput.update(events):
                ws = WordSmith([],0)
                ws.auto_forge()
                ws.smith_words()
                forged = ws.forge_details()
                self.do_rectangle_demo(self.screen)
                self.smith(x, y)
                pygame.display.flip()
                self.forge(forged)
                time.sleep(5)
                print(textinput.get_text())
                textinput.clear_text()
                pygame.display.flip()

            
            
            

g = GameWindow("",0)
g.settings()