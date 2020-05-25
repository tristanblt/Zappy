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

def usage():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")
