##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## responses
##

import ai.src.glob

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
    #print(response)
    return True

def rightResponse(response):
    #print(response)
    return True

def leftResponse(response):
    #print(response)
    return True

def lookResponse(response):
    #print(response)
    return True

def inventoryResponse(response):
    #print(response)
    return True

def broadcastResponse(response):
    #print(response)
    return True

def connectNbrResponse(response):
    #print(response)
    ai.src.glob.gameState["clientNum"] = int(response)
    return True

def forkResponse(response):
    #print(response)
    if ai.src.glob.gameState["canFork"]:
        ai.src.glob.reward += 10
    else:
        ai.src.glob.reward -= 20
    return True

def ejectResponse(response):
    #print(response)
    return True

def takeObjectResponse(response):
    #print(response)
    return True

def setObjectResponse(response):
    #print(response)
    return True

def incantationResponse(response):
    #print(response)
    return True
