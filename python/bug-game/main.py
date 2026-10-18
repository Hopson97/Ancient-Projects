import pygame, sys
from Classes import *
from Process import process


pygame.init()
WIDTH,HEIGHT = 640, 360
screen = pygame.display.set_mode((WIDTH, HEIGHT),0,32)

clock = pygame.time.Clock()
FPS = 24
fivesecondinterval = FPS*5
totalframes = 0



bug = Bug(0, 200, 31, 42, "bugright.png")
img_bug = pygame.image.load("bugright.png")


while True:
    process(bug)
    #Logic
    bug.motion()

    totalframes += 1

    #Logic
    #Draw
    BaseClass.allsprites.draw(screen)
    pygame.display.flip()
    #Draw

    clock.tick(FPS)
