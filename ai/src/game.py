##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## game
##

import time
import tensorflow
import random
import select
import queue
import random
import numpy as np

import ai.src.glob
from ai.src.requests import *
from ai.src.event import eventHandler
from ai.src.error import exceptionError

functions = [
    ai.src.requests.forwardRequest,
    ai.src.requests.rightRequest,
    ai.src.requests.leftRequest,
    ai.src.requests.lookRequest,
    ai.src.requests.connectNbrRequest,
    ai.src.requests.inventoryRequest,
    ai.src.requests.forkRequest,
    ai.src.requests.incantationRequest,
    ai.src.requests.takeFoodRequest,
    ai.src.requests.takeLinemateRequest,
    ai.src.requests.takeDeraumereRequest,
    ai.src.requests.takeSiburRequest,
    ai.src.requests.takeMendianeRequest,
    ai.src.requests.takePhirasRequest,
    ai.src.requests.takeThystameRequest,
    ai.src.requests.setFoodRequest,
    ai.src.requests.setLinemateRequest,
    ai.src.requests.setDeraumereRequest,
    ai.src.requests.setSiburRequest,
    ai.src.requests.setMendianeRequest,
    ai.src.requests.setPhirasRequest,
    ai.src.requests.setThystameRequest,
    #ai.src.requests.ejectRequest,
    #ai.src.requests.broadcastRequest,
]

def resetGame():
    ai.src.glob.AIRunning = True
    ai.src.glob.readQueue = queue.Queue()
    ai.src.glob.writeQueue = queue.Queue()
    ai.src.glob.currentCommand = None
    ai.src.glob.reward = 0
    ai.src.glob.gameState = {}
    ai.src.glob.gameState["clientNum"] = 0
    ai.src.glob.gameState["mapSize"] = {}
    ai.src.glob.gameState["mapSize"]["x"] = 0
    ai.src.glob.gameState["mapSize"]["y"] = 0
    ai.src.glob.gameState["level"] = 1
    ai.src.glob.gameState["directionFood"] = -1
    ai.src.glob.gameState["directionLinemate"] = -1
    ai.src.glob.gameState["directionDeraumere"] = -1
    ai.src.glob.gameState["directionSibur"] = -1
    ai.src.glob.gameState["directionMendiane"] = -1
    ai.src.glob.gameState["directionPhiras"] = -1
    ai.src.glob.gameState["directionThystame"] = -1
    ai.src.glob.gameState["nbFood"] = 0
    ai.src.glob.gameState["nbLinemate"] = 0
    ai.src.glob.gameState["nbDeraumere"] = 0
    ai.src.glob.gameState["nbSibur"] = 0
    ai.src.glob.gameState["nbMendiane"] = 0
    ai.src.glob.gameState["nbPhiras"] = 0
    ai.src.glob.gameState["nbThystame"] = 0
    ai.src.glob.gameState["canFork"] = True
    ai.src.glob.gameState["canIncant"] = False

def startGame(params, mainsock, model):
    recordStates = []
    iteration = 0
    batchSize = 10

    resetGame()
    ai.src.requests.initGameRequest(mainsock, params["name"])
    while ai.src.glob.AIRunning:
        readable, writable, exceptional = select.select([mainsock], [mainsock], [mainsock])
        for s in readable:
            data = s.recv(1024)
            if data:
                ai.src.glob.readQueue.put(data.decode())
            else:
                mainsock.close()
                exit(84)
        for s in writable:
            try:
                next_cmd = ai.src.glob.writeQueue.get_nowait()
            except queue.Empty:
                pass
            else:
                s.send(next_cmd.encode())
        for s in exceptional:
            mainsock.close()
            exit(84)
        while True:
            try:
                response = ai.src.glob.readQueue.get_nowait()
                iteration += 1
                if not eventHandler(response):
                    if not ai.src.glob.currentCommand(response):
                        mainsock.close()
                        exit(84)
                    ai.src.glob.currentCommand = None
                    if ai.src.glob.currentCommandPred:
                        ai.src.glob.currentCommandPred[ai.src.glob.currentCommandIdx] = ai.src.glob.reward
                        recordStates.append([ai.src.glob.gameState, ai.src.glob.currentCommandPred])
                        ai.src.glob.reward = 0
            except queue.Empty:
                break
        if ai.src.glob.currentCommand is None:
            requestSelection(mainsock, model)
        if iteration == batchSize:
            iteration = 0
            if len(recordStates) > 0:
                Xtrain = []
                Ytrain = []
                for gs in recordStates:
                    Xtrain.append([
                        gs[0]["level"],
                        gs[0]["directionFood"],
                        gs[0]["directionLinemate"],
                        gs[0]["directionDeraumere"],
                        gs[0]["directionSibur"],
                        gs[0]["directionMendiane"],
                        gs[0]["directionPhiras"],
                        gs[0]["directionThystame"],
                        gs[0]["nbFood"],
                        gs[0]["nbLinemate"],
                        gs[0]["nbDeraumere"],
                        gs[0]["nbSibur"],
                        gs[0]["nbMendiane"],
                        gs[0]["nbPhiras"],
                        gs[0]["nbThystame"],
                        gs[0]["canFork"],
                        gs[0]["canIncant"]
                    ])
                    Ytrain.append(gs[1])
                model.fit(np.array(Xtrain), np.array(Ytrain), batch_size=batchSize)
                recordStates.clear()
    return False

def requestSelection(ms, model):
    prediction = model.predict(np.array([[
        ai.src.glob.gameState["level"],
        ai.src.glob.gameState["directionFood"],
        ai.src.glob.gameState["directionLinemate"],
        ai.src.glob.gameState["directionDeraumere"],
        ai.src.glob.gameState["directionSibur"],
        ai.src.glob.gameState["directionMendiane"],
        ai.src.glob.gameState["directionPhiras"],
        ai.src.glob.gameState["directionThystame"],
        ai.src.glob.gameState["nbFood"],
        ai.src.glob.gameState["nbLinemate"],
        ai.src.glob.gameState["nbDeraumere"],
        ai.src.glob.gameState["nbSibur"],
        ai.src.glob.gameState["nbMendiane"],
        ai.src.glob.gameState["nbPhiras"],
        ai.src.glob.gameState["nbThystame"],
        ai.src.glob.gameState["canFork"],
        ai.src.glob.gameState["canIncant"]
    ]])).flatten().tolist()

    print([
        ai.src.glob.gameState["level"],
        ai.src.glob.gameState["directionFood"],
        ai.src.glob.gameState["directionLinemate"],
        ai.src.glob.gameState["directionDeraumere"],
        ai.src.glob.gameState["directionSibur"],
        ai.src.glob.gameState["directionMendiane"],
        ai.src.glob.gameState["directionPhiras"],
        ai.src.glob.gameState["directionThystame"],
        ai.src.glob.gameState["nbFood"],
        ai.src.glob.gameState["nbLinemate"],
        ai.src.glob.gameState["nbDeraumere"],
        ai.src.glob.gameState["nbSibur"],
        ai.src.glob.gameState["nbMendiane"],
        ai.src.glob.gameState["nbPhiras"],
        ai.src.glob.gameState["nbThystame"],
        ai.src.glob.gameState["canFork"],
        ai.src.glob.gameState["canIncant"]
    ])

    if random.randrange(1, 3) == 1:
        print("rand: ", end='')
        cmdIdx = random.randrange(0, len(functions))
        requestWithIdx(ms, cmdIdx)
    else:
        print("pred: ", end='')
        cmdIdx = prediction.index(max(prediction))
        requestWithIdx(ms, cmdIdx)
    
    ai.src.glob.currentCommandPred = prediction
    ai.src.glob.currentCommandIdx = cmdIdx

def requestWithIdx(ms, idx):
    print(idx)
    functions[idx](ms)
