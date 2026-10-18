
import pygame, sys

def process(bug):

    
    #PROCESSES Start
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()





        keys = pygame.key.get_pressed()

        if keys[pygame.K_d]:
            bug.image = pygame.image.load("bugright.png")
            bug.velx = 5
        elif keys[pygame.K_a]:
            bug.image = pygame.image.load("bugleft.png")
            bug.velx = -5
        else:
            bug.image = pygame.image.load("bugfwd.png")
            bug.velx = 0

    #Processes End
