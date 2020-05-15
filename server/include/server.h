/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "struct.h"

bool sigint_catch;

/* CLIENT TOOLS */
bool add_client(server_t *server);
bool rm_client(server_t *server, client_t *client);
bool init_client(server_t *s, client_t *client);

/* FLUX TOOLS */
bool read_flux(server_t *server, client_t *client);
bool write_flux(server_t *server, client_t *client);
void add_data(flux_t *flux, int n, ...);
void remove_data(flux_t *flux, int size);
void add_raw_data(flux_t *flux, char *str);

/* TIME TOOLS */
void handle_time(server_t *server);

/* SERVER TOOLS */
server_t *init_server(char *port);
void end_server(server_t *server);
void update_fds(server_t *server);
bool handle_fds(server_t *server);
bool server_iteration(server_t *server);

/* COMMANDS TOOLS */
bool handle_commands(server_t *server);

/* SIGNAL TOOLS */
void handle_sigint();

/* ERROR HANDLING */
bool check(int ac, char **av);

/* COMMANDS FCT */

/* MAIN FCT */
int zappy_server(int ac, char **av);

#endif /* !SERVER_H_ */
