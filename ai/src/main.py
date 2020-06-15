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
    for i in range(10):
        mainsock = initSocket(params)
        startGame(params, mainsock, model)
        mainsock.close()
        time.sleep(0.5)

    saveModel(model)

