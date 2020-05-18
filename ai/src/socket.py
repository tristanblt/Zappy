##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## socket
##

import socket
import sys

from src.requests import sendRequest
from src.error import *

def initSocket(params):
    try:
        mainsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        mainsock.connect((params['machine'], params['port']))
        sendRequest(mainsock, "")
        return mainsock
        
    except Exception as e:
        exceptionError(e)
    