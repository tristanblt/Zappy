/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "includes_and_defines.h"

/* SOCKET MANAGEMENT */
typedef struct flux_s flux_t;
typedef struct socket_s socket_t;
typedef struct fd_lists_s fd_lists_t;

struct flux_s {
    char *buff;
    int nb;
};

struct socket_s {
    int fd;
    struct sockaddr_in add;
};

struct fd_lists_s {
    fd_set read;
    fd_set write;
    fd_set error;
};



/* TEAMS MANAGEMENT */
typedef struct team_s team_t;

struct team_s {
    char *name;
    int nb;
};



/* DATA AND CONTEXT STRUCTURES */
typedef struct position_s position_t;
typedef struct ressources_s ressources_t;
typedef struct server_data_s server_data_t;
typedef struct client_data_s client_data_t;

struct position_s {
    int x;
    int y;
};

struct ressources_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

struct server_data_s {
    int f;
    int nb_mates;
    int map_width;
    int map_height;
    team_t *teams;
};

struct client_data_s {
    char *team;
    int level;
    int cool_down;
    int dir;
    position_t pos;
    ressources_t inventory;
};



/* MAP MANAGEMENT */
typedef struct map_node_s map_node_t;

struct map_node_s {
    SLIST_ENTRY(map_node_t) v_nodes;
    SLIST_ENTRY(map_node_t) h_nodes;
    position_t coordinates;
    ressources_t ressources;
};



/* SERVER MANAGEMENT */
typedef struct client_s client_t;
typedef struct clients_s clients_t;
typedef struct server_s server_t;

struct client_s {
    client_data_t data;
    socket_t sck;
    flux_t in;
    flux_t out;
    SLIST_ENTRY(client_t) next;
};

struct clients_s {
    client_t *c;
    int nb;
};

struct server_s {
    server_data_t data;
    socket_t sck;
    fd_lists_t fds;
    clients_t clients;
    bool running;
};



/* COMMAND MANAGEMENT */
typedef struct command_s command_t;

struct command_s {
    char *token;
    bool (*fct)(server_t *server, int client_idx, char *command);
};

#endif /* !STRUCTURES_H_ */