##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requests
##

import ai.src.glob
from ai.src.timeHandling import addTime
from ai.src.responses import *

takeResponses = {
    "food": takeFoodResponse,
    "linemate": takeLinemateResponse,
    "deraumere": takeDeraumereResponse,
    "sibur": takeSiburResponse,
    "mendiane": takeMendianeResponse,
    "phiras": takePhirasResponse,
    "thystame": takeThystameResponse
}

setResponses = {
    "food": setFoodResponse,
    "linemate": setLinemateResponse,
    "deraumere": setDeraumereResponse,
    "sibur": setSiburResponse,
    "mendiane": setMendianeResponse,
    "phiras": setPhirasResponse,
    "thystame": setThystameResponse
}

def sendRequest(request):
    if ai.src.glob.debug:
        print("\t\t\t\t\t\t\tAction: " + request)
    ai.src.glob.writeBuffer += request + ai.src.glob.socketSeparator

def initGameRequest(teamName):
    sendRequest(teamName)
    ai.src.glob.currentCommand = initGameResponseClientNum

def forwardRequest():
    addTime(7)
    sendRequest("Forward")
    ai.src.glob.currentCommand = forwardResponse

def rightRequest():
    addTime(7)
    sendRequest("Right")
    ai.src.glob.currentCommand = rightResponse
    
def leftRequest():
    addTime(7)
    sendRequest("Left")
    ai.src.glob.currentCommand = leftResponse

def lookRequest():
    addTime(7)
    sendRequest("Look")
    ai.src.glob.currentCommand = lookResponse

def inventoryRequest():
    addTime(1)
    sendRequest("Inventory")
    ai.src.glob.currentCommand = inventoryResponse

def broadcastRequest(text):
    addTime(7)
    sendRequest("Broadcast " + text)
    ai.src.glob.currentCommand = broadcastResponse

def connectNbrRequest():
    sendRequest("Connect_nbr")
    ai.src.glob.currentCommand = connectNbrResponse

def forkRequest():
    addTime(42)
    sendRequest("Fork")
    ai.src.glob.currentCommand = forkResponse

def ejectRequest():
    addTime(7)
    sendRequest("Eject")
    ai.src.glob.currentCommand = ejectResponse

def takeObjectRequest(object):
    addTime(7)
    sendRequest("Take "+object)
    ai.src.glob.currentCommand = takeResponses[object]

def setObjectRequest(object):
    addTime(7)
    sendRequest("Set "+object)
    ai.src.glob.currentCommand = setResponses[object]

def incantationRequest():
    addTime(300)
    sendRequest("Incantation")
    ai.src.glob.currentCommand = incantationResponse
