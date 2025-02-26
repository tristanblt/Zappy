##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## main
##

import os
import time

from ai.src.arguments import parseArgs
from ai.src.socket import initSocket
from ai.src.game import startGame

def main():
    params = parseArgs()
    count = 0

    while True:
        count += 1
        pid = os.fork()
        if pid == 0:
            mainsock = initSocket(params)
            if mainsock is None:
                break
            startGame(params, mainsock, count)
            mainsock.close()
        else:
            time.sleep(5)
