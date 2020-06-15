##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## error
##

import sys

def exceptionError(error):
    print(sys.argv[0] + ": " + str(error), file=sys.stderr)
    print("\nTry running '"+sys.argv[0]+" -help' to get information on the usage", file=sys.stderr)
    exit(84)