##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## main
##

import sys
import socket
import json

from ai.src.arguments import parseArgs
from ai.src.socket import initSocket
from ai.src.game import startGame


def main():
    params = parseArgs()
    mainsock = initSocket(params)

    startGame(params, mainsock)

    mainsock.close()

def usage():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")

