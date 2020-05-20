##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requests
##

import ai.src.glob
from ai.src.event import eventHandler

# SEND COMMANDS

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
    sendRequest(mainsock, "Fork")
    ai.src.glob.currentCommand = forkResponse

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
    sendRequest(mainsock, "Incantation")
    ai.src.glob.currentCommand = incantationResponse

# RECEIVE COMMANDS

def initGameResponse(response):
    if (response == "ko\n"):
        return None
    lineSplit = response.split("\n")
    spaceSplit = lineSplit[1].split(" ")    
    try:
        ai.src.glob.gameState["clientNum"] = int(lineSplit[0])
        ai.src.glob.gameState["mapSize"]["x"] = int(spaceSplit[0])
        ai.src.glob.gameState["mapSize"]["y"] = int(spaceSplit[1])
        return True
    except:
        return False

def forwardResponse(response):
    print(response)
    return True

def rightResponse(response):
    print(response)
    return True

def leftResponse(response):
    print(response)
    return True

def lookResponse(response):
    print(response)
    return True

def inventoryResponse(response):
    print(response)
    return True

def broadcastResponse(response):
    print(response)
    return True

def connectNbrResponse(response):
    print(response)
    return True

def forkResponse(response):
    print(response)
    return True

def ejectResponse(response):
    print(response)
    return True

def takeObjectResponse(response):
    print(response)
    return True

def setObjectResponse(response):
    print(response)
    return True

def incantationResponse(response):
    print(response)
    return True
