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

/* DATA TOOLS */
void init_client_data(client_data_t *data, char *team, position_t pos);
bool init_server_data(server_data_t *data, param_t params);
void free_server_data(server_data_t *data);

/* REQUEST TOOLS */
void add_to_requests(char *buff, client_t *client, int size);
void rm_from_request(client_t *client);
void init_requests(request_manager_t *r);

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
void init_time(time_manager_t *t);

/* REQUEST TOOLS */
void add_to_requests(char *buff, client_t *client, int size);
void rm_from_request(client_t *client);

/* SERVER TOOLS */
server_t *init_server(char *port);
void end_server(server_t *server);
void update_fds(server_t *server);
bool handle_fds(server_t *server);
bool server_iteration(server_t *server);

/* COMMANDS TOOLS */
bool handle_commands(server_t *server);

/* SIGNAL TOOLS */
void handle_sigint(int i);

/* ERROR HANDLING */
bool check(int ac, char **av);

/* COMMANDS FCT */

/* MAIN FCT */
int zappy_server(int ac, char **av);

/* PARAM TOOLS */
void init_param(int ac, char **av, param_t *param);
void check_param_n(int ac, char **av, param_t *param);
void init_param_n(int ac, char **av, param_t *param, int i);
void check_param(int ac, char **av, param_t *param);

/* USAGES FCT */
void display_usage_s(void);
//void display_usage_c(void);

#endif /* !SERVER_H_ */
