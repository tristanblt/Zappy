##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## game
##

from src.requests import *
from src.error import *

def startGame(params, mainsock):
    gameConfig = initGameRequest(mainsock, params["name"])
    if gameConfig == None:
        exceptionError("Wrong response from server")
    print(gameConfig["clientNum"])
