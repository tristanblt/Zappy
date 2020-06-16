##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## glob
##

import queue

global AIRunning
AIRunning = True

global readQueue
readQueue = queue.Queue()

global readBuffer
readBuffer = ""

global writeBuffer
writeBuffer = ""

global currentCommand
currentCommand = None

global gameState
gameState = {}

global gameMap
gameMap = []

global lookAt
lookAt = 0