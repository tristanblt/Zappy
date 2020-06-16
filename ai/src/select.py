##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## select
##

import select

import ai.src.glob

def selectHandler(mainsock):
    readable, writable, exceptional = select.select([mainsock], [mainsock], [mainsock])
    for s in readable:
        data = s.recv(4096)
        if data:
            ai.src.glob.readBuffer += data.decode()
        else:
            mainsock.close()
            exit(84)
        nbCmds = ai.src.glob.readBuffer.count("\n")
        cmds = ai.src.glob.readBuffer.split("\n")
        for i in range(nbCmds):
            ai.src.glob.readQueue.put(cmds[i])
            ai.src.glob.readBuffer = ai.src.glob.readBuffer[(len(cmds[i]) + 1):]
    for s in writable:
        sent = s.send(ai.src.glob.writeBuffer.encode())
        ai.src.glob.writeBuffer = ai.src.glob.writeBuffer[sent:]
    for s in exceptional:
        mainsock.close()
        exit(84)