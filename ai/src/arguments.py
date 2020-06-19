##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## arguments
##

import json
import getopt
import sys

from ai.src.error import exceptionError

def usage():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")

def parseArgs():
    params = {
        'port' : 4242,
        'name' : "",
        'machine' : "localhost",
        'debug' : False,
    }

    try:
        opts, args = getopt.getopt(sys.argv[1:], 'p:n:h:d', ["help"])
        for o, a in opts:
            if o == "--help" or (o == "-h" and a == "elp"):
                usage()
                sys.exit(0)
            if o == "-p":
                params['port'] = int(a)
            if o == "-n":
                params['name'] = a
            if o == "-h":
                params['machine'] = a
            if o == "-d":
                params['debug'] = True
    except Exception as e:
        exceptionError(e)
    
    if (params["name"] == ""):
        exceptionError("Error: You must give a team name")

    return params