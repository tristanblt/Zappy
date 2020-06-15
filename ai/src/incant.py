##
## EPITECH PROJECT, 2020
## PSU_zappy_2019
## File description:
## incant
##

import ai.src.glob

def getNbItemOnPlayerTile(itemName):
    nbItem = 0
    for item in ai.src.glob.gameMap:
        if (item['type'] == itemName
        and item['pos']['x'] == 0
        and item['pos']['y'] == 0):
            nbItem += 1
    return nbItem

def checkIncant():
    level = ai.src.glob.gameState['level']
    nbPlayers = getNbItemOnPlayerTile("player")
    nbLinemate = getNbItemOnPlayerTile("linemate")
    nbDeraumere = getNbItemOnPlayerTile("deraumere")
    nbSibur = getNbItemOnPlayerTile("sibur")
    nbMendiane = getNbItemOnPlayerTile("mendiane")
    nbPhiras = getNbItemOnPlayerTile("phiras")
    nbThystame = getNbItemOnPlayerTile("thystame")

    if (ai.src.glob.gameState['nbFood'] < 3):
        return False
    if (level == 1
    and nbLinemate == 1):
        return True
    if (level == 2
    and nbPlayers == 2
    and nbLinemate == 1
    and nbDeraumere == 1
    and nbSibur == 1):
        return True
    if (level == 3
    and nbPlayers == 2
    and nbLinemate == 2
    and nbSibur == 1
    and nbPhiras == 2):
        return True
    if (level == 4
    and nbPlayers == 4
    and nbLinemate == 1
    and nbDeraumere == 1
    and nbSibur == 2
    and nbPhiras == 1):
        return True
    if (level == 5
    and nbPlayers == 4
    and nbLinemate == 1
    and nbDeraumere == 2
    and nbSibur == 1
    and nbMendiane == 3):
        return True
    if (level == 6
    and nbPlayers == 6
    and nbLinemate == 1
    and nbDeraumere == 2
    and nbSibur == 3
    and nbPhiras == 1):
        return True
    if (level == 7
    and nbPlayers == 6
    and nbLinemate == 2
    and nbDeraumere == 2
    and nbSibur == 2
    and nbMendiane == 2
    and nbPhiras == 2
    and nbThystame == 1):
        return True
    return False
    
