##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requests
##

import ai.src.glob
# from ai.src.glob import writeQueue, ai.src.glob.currentCommand, gameState, reward
from ai.src.responses import *

def sendRequest(mainsock, request):
    ai.src.glob.writeQueue.put(request + "\n")

def initGameRequest(mainsock, teamName):
    sendRequest(mainsock, teamName)
    ai.src.glob.currentCommand = initGameResponse

def forwardRequest(mainsock):
    sendRequest(mainsock, "Forward")
    ai.src.glob.currentCommand = forwardResponse

def rightRequest(mainsock):
    sendRequest(mainsock, "Right")
    ai.src.glob.currentCommand = rightResponse
    
def leftRequest(mainsock):
    sendRequest(mainsock, "Left")
    ai.src.glob.currentCommand = leftResponse

def lookRequest(mainsock):
    sendRequest(mainsock, "Look")
    ai.src.glob.currentCommand = lookResponse

def inventoryRequest(mainsock):
    sendRequest(mainsock, "Inventory")
    ai.src.glob.currentCommand = inventoryResponse

def broadcastRequest(mainsock, text):
    sendRequest(mainsock, text)
    ai.src.glob.currentCommand = broadcastResponse

def connectNbrRequest(mainsock):
    sendRequest(mainsock, "Connect_nbr")
    ai.src.glob.currentCommand = connectNbrResponse

def forkRequest(mainsock):
    if (ai.src.glob.gameState["canFork"]):
        ai.src.glob.reward += 0
        sendRequest(mainsock, "Fork")
        ai.src.glob.currentCommand = forkResponse
    else:
        ai.src.glob.reward -= 3
    print("fork")

def ejectRequest(mainsock):
    sendRequest(mainsock, "Eject")
    ai.src.glob.currentCommand = ejectResponse

def takeFoodRequest(mainsock):
    sendRequest(mainsock, "Take food")
    ai.src.glob.currentCommand = takeFoodResponse

def takeLinemateRequest(mainsock):
    sendRequest(mainsock, "Take linemate")
    ai.src.glob.currentCommand = takeLinemateResponse

def takeDeraumereRequest(mainsock):
    sendRequest(mainsock, "Take deraumere")
    ai.src.glob.currentCommand = takeDeraumereResponse

def takeSiburRequest(mainsock):
    sendRequest(mainsock, "Take sibur")
    ai.src.glob.currentCommand = takeSiburResponse

def takeMendianeRequest(mainsock):
    sendRequest(mainsock, "Take mendiane")
    ai.src.glob.currentCommand = takeMendianeResponse

def takePhirasRequest(mainsock):
    sendRequest(mainsock, "Take phiras")
    ai.src.glob.currentCommand = takePhirasResponse

def takeThystameRequest(mainsock):
    sendRequest(mainsock, "Take thystame")
    ai.src.glob.currentCommand = takeThystameResponse

def setFoodRequest(mainsock):
    sendRequest(mainsock, "Set food")
    ai.src.glob.currentCommand = setFoodResponse

def setLinemateRequest(mainsock):
    sendRequest(mainsock, "Set linemate")
    ai.src.glob.currentCommand = setLinemateResponse

def setDeraumereRequest(mainsock):
    sendRequest(mainsock, "Set deraumere")
    ai.src.glob.currentCommand = setDeraumereResponse

def setSiburRequest(mainsock):
    sendRequest(mainsock, "Set sibur")
    ai.src.glob.currentCommand = setSiburResponse

def setMendianeRequest(mainsock):
    sendRequest(mainsock, "Set mendiane")
    ai.src.glob.currentCommand = setMendianeResponse

def setPhirasRequest(mainsock):
    sendRequest(mainsock, "Set phiras")
    ai.src.glob.currentCommand = setPhirasResponse

def setThystameRequest(mainsock):
    sendRequest(mainsock, "Set thystame")
    ai.src.glob.currentCommand = setThystameResponse

def incantationRequest(mainsock):
    if (ai.src.glob.gameState["canIncant"]):
        print("INCANTTION")
        ai.src.glob.reward += 200
        sendRequest(mainsock, "Incantation")
        ai.src.glob.currentCommand = incantationResponse
    else:
        ai.src.glob.reward -= 400
        ai.src.glob.currentCommand = None
