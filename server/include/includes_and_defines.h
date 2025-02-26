/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** includes_and_defines
*/

#ifndef INCLUDES_AND_DEFINES_H_
#define INCLUDES_AND_DEFINES_H_

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/queue.h>
#include <stdarg.h>
#include <math.h>

#define BUFF_SIZE 65536

#define ERROR false
#define SUCCESS true
#define OK true

#define EPI_EXIT_SUCCESS 0
#define EPI_EXIT_ERROR 84

#define SUPP_IN_SWITCH 2
#define SUPP_IN_LIFE 0

#define START false
#define END true

#define N 1
#define E 2
#define S 3
#define W 4

#define HATCHED 0

enum type_e {
    AI,
    GRAPHICAL,
    NOTHING
};

enum state_e {
    RUNNING,
    FINAL,
    ENDED
};

#endif /* !INCLUDES_AND_DEFINES_H_ */
