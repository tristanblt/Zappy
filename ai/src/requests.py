##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requests
##

import ai.src.glob
from ai.src.responses import *

def sendRequest(request):
    ai.src.glob.writeBuffer += request + "\n"

def initGameRequest(teamName):
    sendRequest(teamName)
    ai.src.glob.currentCommand = initGameResponseClientNum

def forwardRequest():
    sendRequest("Forward")
    ai.src.glob.currentCommand = forwardResponse

def rightRequest():
    sendRequest("Right")
    ai.src.glob.currentCommand = rightResponse
    
def leftRequest():
    sendRequest("Left")
    ai.src.glob.currentCommand = leftResponse

def lookRequest():
    sendRequest("Look")
    ai.src.glob.currentCommand = lookResponse

def inventoryRequest():
    sendRequest("Inventory")
    ai.src.glob.currentCommand = inventoryResponse

def broadcastRequest(text):
    sendRequest(text)
    ai.src.glob.currentCommand = broadcastResponse

def connectNbrRequest():
    sendRequest("Connect_nbr")
    ai.src.glob.currentCommand = connectNbrResponse

def forkRequest():
    sendRequest("Fork")
    ai.src.glob.currentCommand = forkResponse

def ejectRequest():
    sendRequest("Eject")
    ai.src.glob.currentCommand = ejectResponse

def takeFoodRequest():
    sendRequest("Take food")
    ai.src.glob.currentCommand = takeFoodResponse

def takeLinemateRequest():
    sendRequest("Take linemate")
    ai.src.glob.currentCommand = takeLinemateResponse

def takeDeraumereRequest():
    sendRequest("Take deraumere")
    ai.src.glob.currentCommand = takeDeraumereResponse

def takeSiburRequest():
    sendRequest("Take sibur")
    ai.src.glob.currentCommand = takeSiburResponse

def takeMendianeRequest():
    sendRequest("Take mendiane")
    ai.src.glob.currentCommand = takeMendianeResponse

def takePhirasRequest():
    sendRequest("Take phiras")
    ai.src.glob.currentCommand = takePhirasResponse

def takeThystameRequest():
    sendRequest("Take thystame")
    ai.src.glob.currentCommand = takeThystameResponse

def setFoodRequest():
    sendRequest("Set food")
    ai.src.glob.currentCommand = setFoodResponse

def setLinemateRequest():
    sendRequest("Set linemate")
    ai.src.glob.currentCommand = setLinemateResponse

def setDeraumereRequest():
    sendRequest("Set deraumere")
    ai.src.glob.currentCommand = setDeraumereResponse

def setSiburRequest():
    sendRequest("Set sibur")
    ai.src.glob.currentCommand = setSiburResponse

def setMendianeRequest():
    sendRequest("Set mendiane")
    ai.src.glob.currentCommand = setMendianeResponse

def setPhirasRequest():
    sendRequest("Set phiras")
    ai.src.glob.currentCommand = setPhirasResponse

def setThystameRequest():
    sendRequest("Set thystame")
    ai.src.glob.currentCommand = setThystameResponse

def incantationRequest():
    sendRequest("Incantation")
    ai.src.glob.currentCommand = incantationResponse
