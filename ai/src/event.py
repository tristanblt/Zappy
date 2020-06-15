##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## event
##

import sys

import ai.src.glob

def eventHandler(response):
    # broadcast
    # eject
    if (response == "dead\n"):
        ai.src.glob.AIRunning = False
        return True
    return False