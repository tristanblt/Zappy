##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## main
##

import sys
import socket
import time

from ai.src.arguments import parseArgs
from ai.src.socket import initSocket
from ai.src.game import startGame
from ai.src.learning import createModel, saveModel

def main():
    params = parseArgs()
    model = createModel()

    # play N games
    mainsock = initSocket(params)
    startGame(params, mainsock, model)
    mainsock.close()

    saveModel(model)

