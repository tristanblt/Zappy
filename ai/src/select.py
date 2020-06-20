##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## select
##

import select

import ai.src.glob

def selectHandler(mainsock):
    writeFd = []
    if len(ai.src.glob.writeBuffer):
        writeFd = [mainsock]
    readable, writable, exceptional = select.select([mainsock], writeFd, [mainsock])
    for s in readable:
        data = s.recv(4096)
        if data:
            ai.src.glob.readBuffer += data.decode()
        else:
            mainsock.close()
            exit(84)
        nbCmds = ai.src.glob.readBuffer.count(ai.src.glob.socketSeparator)
        cmds = ai.src.glob.readBuffer.split(ai.src.glob.socketSeparator)
        for i in range(nbCmds):
            if len(cmds[i]) == 0:
                continue
            ai.src.glob.readQueue.put(cmds[i])
            ai.src.glob.readBuffer = ai.src.glob.readBuffer[(len(cmds[i]) + len(ai.src.glob.socketSeparator)):]
    for s in writable:
        sent = s.send(ai.src.glob.writeBuffer.encode())
        ai.src.glob.writeBuffer = ai.src.glob.writeBuffer[sent:]
    for s in exceptional:
        mainsock.close()
        exit(84)