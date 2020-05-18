##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## main
##

import sys
import json
import getopt
import socket

def main():
    params = {
        'port' : 0,
        'name' : "",
        'machine' : "localhost"
        }

    try:
        opts, args = getopt.getopt(sys.argv[1:], 'p:n:h:', ["help"])
        print(opts)
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
    except Exception as e:
        print(sys.argv[0] + ": " + str(e))
        print("\ntry running '"+sys.argv[0]+" -help' to get information on the usage")
        sys.exit(84)
    print(json.dumps(params, indent=4))
    try:
        mainsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        mainsock.connect((params['machine'], params['port']))
    except Exception as e:
        print(sys.argv[0] + ": " + str(e))
        sys.exit(84)
    print("connection gud")

    msg_a_envoyer = "msz\n"
    msg_a_envoyer = msg_a_envoyer.encode()
    mainsock.send(msg_a_envoyer)
    msg_recu = mainsock.recv(1024)
    print(msg_recu.decode())

    msg_a_envoyer = "msz\n"
    msg_a_envoyer = msg_a_envoyer.encode()
    mainsock.send(msg_a_envoyer)
    msg_recu = mainsock.recv(1024)
    print(msg_recu.decode())

    mainsock.close();

def usage():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")

