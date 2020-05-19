##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requests
##

from ai.src.event import eventHandler

def sendRequest(mainsock, request):
    mainsock.send((request + "\n").encode())
    while True:
        response = mainsock.recv(1024).decode()
        if not eventHandler(response):
            break
    return response

def initGameRequest(mainsock, teamName):
    response = sendRequest(mainsock, teamName)
    if (response == "ko"):
        return None
    lineSplit = response.split("\n")
    spaceSplit = lineSplit[1].split(" ")

    try:
        return {
            "clientNum": int(lineSplit[0]),
            "mapSize": {
                "x": int(spaceSplit[0]),
                "y": int(spaceSplit[1])
            }
        }
    except:
        return None

def forwardRequest(mainsock):
    sendRequest(mainsock, "Forward")

def rightRequest(mainsock):
    sendRequest(mainsock, "Right")

def leftRequest(mainsock):
    sendRequest(mainsock, "Left")

def lookRequest(mainsock):
    print(sendRequest(mainsock, "Look"))

def inventoryRequest(mainsock):
    print(sendRequest(mainsock, "Inventory"))

def broadcastRequest(mainsock, text):
    print(sendRequest(mainsock, text))

def connectNbrRequest(mainsock):
    print(sendRequest(mainsock, "Connect_nbr"))

def forkRequest(mainsock):
    print(sendRequest(mainsock, "Fork"))

def ejectRequest(mainsock):
    print(sendRequest(mainsock, "Eject"))

def takeObjectRequest(mainsock, object):
    print(sendRequest(mainsock, "Take " + object))

def setObjectRequest(mainsock, object):
    print(sendRequest(mainsock, "Set " + object))

def incantationRequest(mainsock, object):
    print(sendRequest(mainsock, "Incantation"))