##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## requests
##

def sendRequest(mainsock, request):
    mainsock.send((request + "\n").encode())
    return mainsock.recv(1024).decode()

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
