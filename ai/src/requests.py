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
        ai.src.glob.reward += 10
        #sendRequest(mainsock, "Fork")
        #ai.src.glob.currentCommand = forkResponse
    else:
        ai.src.glob.reward -= 20
    print("fork")

def ejectRequest(mainsock):
    sendRequest(mainsock, "Eject")
    ai.src.glob.currentCommand = ejectResponse

def takeObjectRequest(mainsock, object):
    sendRequest(mainsock, "Take " + object)
    ai.src.glob.currentCommand = takeObjectResponse

def setObjectRequest(mainsock, object):
    sendRequest(mainsock, "Set " + object)
    ai.src.glob.currentCommand = setObjectResponse

def incantationRequest(mainsock):
    if (ai.src.glob.gameState["canIncant"]):
        ai.src.glob.reward += 200
        sendRequest(mainsock, "Incantation")
        ai.src.glob.currentCommand = incantationResponse
    else:
        ai.src.glob.reward -= 400
        ai.src.glob.currentCommand = None
