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

global writeQueue
writeQueue = queue.Queue()

global currentCommand
currentCommand = None

global currentCommandIdx
currentCommandIdx = 0

global currentCommandPred
currentCommandPred = None

global gameState
gameState = {}

global reward
reward = 0

global gameMap
gameMap = []

global lookAt
lookAt = 0