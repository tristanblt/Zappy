##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## timeHandling
##

import ai.src.glob

def addTime(value):
    ai.src.glob.gameState["starveCheckTime"] += value
    ai.src.glob.gameState["broadcastIncantationCheckTime"] += value
    ai.src.glob.gameState["connectNbrCheckTime"] += value
