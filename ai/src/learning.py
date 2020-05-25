##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## learning
##

import numpy as np
import json
import tensorflow
import keras
import tf_agents

from keras.models import model_from_json
from tf_agents.agents.dqn import dqn_agent
from keras.models import Sequential
from keras.layers.core import Dense, Activation, Dropout
from keras.optimizers import SGD
from keras.callbacks import Callback

def createModel():
    # get model from json
    json_file = open('model.json', 'r')
    loaded_json_model = json_file.read()
    model = model_from_json(loaded_json_model)
    model.load_weights('model.h5')

    # init model
    #model = Sequential()
    #model.add(Dense(16, input_shape=(16,), activation="relu"))
    #model.add(Dense(512, activation="relu"))
    #model.add(Dense(512, activation="relu"))
    #model.add(Dense(256, activation="relu"))
    #model.add(Dense(1, activation="linear"))
    #model.summary()
    #model.compile(loss="mean_squared_error", optimizer="adam", metrics=["accuracy"])

    return model

def saveModel(model):
    model.save_weights('model.h5')
    model_json = model.to_json()
    with open('model.json', 'w') as json_file:
        json_file.write(model_json)