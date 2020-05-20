##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## main
##

import sys
import socket
import json
import tensorflow
import keras
import tf_agents
import time
from tf_agents.agents.dqn import dqn_agent
from keras.models import Sequential
from keras.layers.core import Dense, Activation, Dropout
from keras.optimizers import SGD
from keras.callbacks import Callback
import numpy as np

from ai.src.arguments import parseArgs
from ai.src.socket import initSocket
from ai.src.game import startGame

def neural_net(hiddenLayerDims, LoadWeights=''):
    neuralNet = Sequential()
    neuralNet.add(Dense(hiddenLayerDims[0], input_shape=(4,)))
    neuralNet.add(Activation('sigmoid'))
    neuralNet.add(Dense(hiddenLayerDims[1]))
    neuralNet.add(Activation('sigmoid'))
    neuralNet.add(Dense(4))
    neuralNet.add(Activation('softmax'))
    if LoadWeights:
        neuralNet.load_weights(LoadWeights)
    sgd = SGD(lr=0.01, decay=0.0, momentum=0.0, nesterov=False)
    neuralNet.compile(loss='mse', optimizer=sgd)
    return neuralNet

def main():
    params = parseArgs()

    model = neural_net([15, 16])

    while True:
        mainsock = initSocket(params)
        startGame(params, mainsock)
        mainsock.close()
        time.sleep(1)

    mainsock.close()

def usage():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")
