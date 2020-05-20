##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## socket
##

import socket
import sys

from ai.src.requests import sendRequest
from ai.src.error import *

def initSocket(params):
    try:
        mainsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("sdcsd")
        mainsock.connect((params['machine'], params['port']))
        sendRequest(mainsock, "")
        mainsock.recv(1024)
        return mainsock
        
    except Exception as e:
        exceptionError(e)
    