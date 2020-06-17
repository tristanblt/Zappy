/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "includes_and_defines.h"

/*PARAM MANAGEMENT*/

typedef struct param_s param_t;

struct param_s
{
    char *port;
    int width;
    int height;
    char **name;
    int clientNB;
    int freq;
};

/* SOCKET MANAGEMENT */
typedef struct flux_s flux_t;
typedef struct socket_s socket_t;
typedef struct fd_lists_s fd_lists_t;

struct flux_s {
    char buff[BUFF_SIZE];
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
typedef struct map_node_s map_node_t;
typedef struct time_manager_s time_manager_t;
typedef struct position_s position_t;
typedef struct ressources_s ressources_t;
typedef struct egg_s egg_t;
typedef struct s_data_s s_data_t;
typedef struct c_data_s c_data_t;

struct time_manager_s {
    bool is_needed;
    struct timeval timeout;
    struct timeval last_time;
    float delta_time;
    int ratio;
};

struct position_s {
    int x;
    int y;
};

struct ressources_s {
    float food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

struct egg_s {
    float status;
    position_t pos;
    char *team;
    SLIST_ENTRY(egg_s) next;
};

struct s_data_s {
    int f;
    int nb_mates;
    int nb_teams;
    float spawn_cd;
    position_t map_sz;
    SLIST_HEAD(, egg_s) eggs;
    map_node_t *map;
    team_t *teams;
};

struct c_data_s {
    bool is_alive;
    bool req_cntx;
    int idx;
    char *team;
    int level;
    float cool_down;
    int dir;
    position_t pos;
    ressources_t inventory;
};



/* MAP MANAGEMENT */
typedef struct extracted_content_s extracted_content_t;

struct map_node_s {
    struct map_node_s *top;
    struct map_node_s *bottom;
    struct map_node_s *right;
    struct map_node_s *left;
    position_t coordinates;
    ressources_t ressources;
};
struct extracted_content_s {
    ressources_t *ressources;
    int nb_player;
};



/* SERVER MANAGEMENT */
typedef struct request_manager_s request_manager_t;
typedef struct client_s client_t;
typedef struct server_s server_t;
typedef struct zappy_data_s zappy_data_t;
typedef enum type_e type_e;

enum type_e {
    AI,
    GRAPHIQUE,
    NOTHING
};

struct request_manager_s {
    char bodies[10][BUFF_SIZE];
    int pos;
    int nb;
};

struct client_s {
    request_manager_t requests;
    void *data;
    socket_t sck;
    flux_t in;
    flux_t out;
    type_e type;
    SLIST_ENTRY(client_s) next;
};

struct server_s {
    time_manager_t t;
    socket_t sck;
    fd_lists_t fds;
    SLIST_HEAD(, client_s) clients;
    bool running;
};

struct zappy_data_s {
    server_t *server;
    s_data_t data;
};



/* COMMAND MANAGEMENT */
typedef struct command_s command_t;
typedef struct recipe_s recipe_t;

struct command_s {
    char *token;
    int token_len;
    bool (*start)(zappy_data_t *z, client_t *client, char *command);
    bool (*end)(zappy_data_t *z, client_t *client, char *command);
};

struct recipe_s {
    int nb_player;
    ressources_t needed;
};

#endif /* !STRUCTURES_H_ */