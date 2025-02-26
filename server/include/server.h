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
char *int_to_char(int nb);
c_data_t *init_client_data(int f);
bool init_server_data(s_data_t *data, param_t params);
void free_server_data(s_data_t *data);
void level_up(zappy_data_t *z, position_t pos, bool result);

/* RESSOURCES TOOLS */
void init_ressources(ressources_t *res);
void init_map_ressources(ressources_t *res);
int get_ressource_number(char *ressource);
void add_ressource(ressources_t *res, int type);
bool is_player_free(position_t pos, server_t *server);

/* TEAM TOOLS */
team_t *get_team_by_name(team_t *teams, int nb, char *name);
void init_team(team_t *team, char *name);
bool has_won(char *name, server_t *server);

/* REQUEST TOOLS */
void add_to_requests(char *buff, client_t *client, int size);
void rm_from_request(client_t *client);
void init_requests(request_manager_t *r);

/* CLIENT TOOLS */
client_t *get_graphical_client(server_t *server);
client_t *add_client(server_t *server, void *data);
bool rm_client(server_t *server, client_t *client);
bool init_client(server_t *s, client_t *client);

/* CONNEXION_TOOLS */
int check_client_connexion(zappy_data_t *z, client_t *client, char *command);
bool new_client_welcome(server_t *server, void *data);

/* FLUX TOOLS */
bool read_flux(server_t *server, client_t *client);
bool write_flux(client_t *client);
void add_data(flux_t *flux, int n, ...);
void remove_data(flux_t *flux, int size);
void add_raw_data(flux_t *flux, char *str);

/* TIME TOOLS */
void handle_time(server_t *server);
void init_time(time_manager_t *t, int time_ratio);
void update_timeout(server_t *server, float cd_init);


/* LIFE TOOLS */
bool handle_life(zappy_data_t *z, client_t *client);

/* MAP TOOLS */
map_node_t *create_map(position_t size);
void free_map(map_node_t *map, position_t size);
map_node_t *on_tile(map_node_t *start, int x, int y);
int graph_value(int size, int value);
int count_players(server_t *server, int x, int y);
extracted_content_t get_tile_content(s_data_t *data, server_t *s, int x, int y);
void delete_line_tile(map_node_t *line);
void delete_map_tile(map_node_t *map);
void update_map(zappy_data_t *z);
map_node_t *get_tile(map_node_t *map, int x, int y, s_data_t server);

/* VECTOR TOOLS */
int compute_direction(position_t sender, position_t reciever, position_t map,
int dir);
void move_in_dir(client_t *client, int dir, position_t map);

/* REQUEST TOOLS */
void add_to_requests(char *buff, client_t *client, int size);
void rm_from_request(client_t *client);

/* SERVER TOOLS */
server_t *init_server(char *port, int time_ratio);
void end_server(server_t *server);
void update_fds(server_t *server);
bool handle_fds(server_t *server);
bool server_iteration(server_t *server, float timeout_init);
bool every_end_messages_sent(zappy_data_t *z);
char *determine_winner(zappy_data_t *z);
int nb_graphical(server_t *server);
bool end_handle_fds(server_t *server, bool is_ok);

/* ZAPPY TOOLS */
zappy_data_t *init_zappy(param_t param);
void end_zappy(zappy_data_t *z, param_t *param);

/* COMMANDS TOOLS */
bool handle_commands(zappy_data_t *z);

/* EGG TOOLS */
void update_egg_status(zappy_data_t *z);
bool init_client_context(zappy_data_t *z, client_t *client, char *name);
void assign_egg_to_client(zappy_data_t *z, client_t *client, egg_t *egg);
egg_t *get_egg_by_team(zappy_data_t *z, char *team);
bool add_egg(zappy_data_t *z, client_t *client, position_t pos);

/* SIGNAL TOOLS */
void handle_sigint(int i);

/* ERROR HANDLING */
bool check(int ac, char **av);

/* COMMANDS FCT */
bool start_move_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_move_cmd(zappy_data_t *z, client_t *client, char *command);

/* LOOK COMMAND */
bool start_look(zappy_data_t *z, client_t *client, char *command);
bool end_look(zappy_data_t *z, client_t *client, char *arg);
void look_bottom_top(client_t *cli, zappy_data_t *z, int signe_y);
void look_right_left(client_t *cli, zappy_data_t *z, int signe_x);

/* INCANTATION COMMAND*/
bool start_incantation(zappy_data_t *z, client_t *client, char *arg);
bool end_incantation(zappy_data_t *z, client_t *client, char *arg);

/* TAKE COMMAND */
bool start_take_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_take_cmd(zappy_data_t *z, client_t *c, char *arg);

/* SET COMMAND */
bool start_set_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_set_cmd(zappy_data_t *z, client_t *c, char *arg);


/* MAIN FCT */
int zappy_server(int ac, char **av);

/* PARAM TOOLS */
int game_param(int ac, char **av, param_t *param);
int check_param_n(int ac, char **av, param_t *param);
int check_param(int ac, char **av, param_t *param);
int check_team_name(param_t *param);
void init_param(param_t *param);
void reinit_param(int c, param_t *param);
int init_param_n(int ac, char **av, param_t *param, int i);
void free_param(param_t param);
bool check_team_compare(param_t *param, int i);

/* USAGES FCT */
void display_usage_s(void);
//void display_usage_c(void);

/* SPLIT */
char **split_command(char *command);
int split_nb_argument(char **array);

/* EGG_TOOLS */
bool init_client_context(zappy_data_t *z, client_t *client, char *name);
float get_lowest_egg_cd(zappy_data_t *z);

/* PROTOCOLE */
bool msz(zappy_data_t *z, client_t *client, char *arg);
bool sbp(zappy_data_t *z);
bool seg(zappy_data_t *z, char *team_name);
bool smg(zappy_data_t *z, char *arg);
bool suc(client_t *client);
void pbc(server_t *server, client_t *client, char *message);
void pdi(server_t *server, client_t *client);
void pfk(server_t *server, client_t *client);
void enw(server_t *server, client_t *client, egg_t *egg);
void eht(server_t *server, egg_t *egg);

bool pex(zappy_data_t *z, char *arg);
bool pnw(zappy_data_t *z, client_t *client);

bool start_msz(zappy_data_t *z, client_t *client, char *arg);
bool end_msz(zappy_data_t *z, client_t *client, char *arg);
bool ebo(zappy_data_t *z, egg_t *egg);
bool edi(zappy_data_t *z, egg_t *egg);

void pic(server_t *server, client_t *client);
void pie(server_t *server, client_t *client, bool result);
void pdr(server_t *server, client_t *client, char *ressource);
void pgt(server_t *server, client_t *client, char *ressource);


bool start_bct(zappy_data_t *z, client_t *client, char *arg);
bool end_bct(zappy_data_t *z, client_t *client, char *arg);

bool start_msz(zappy_data_t *z, client_t *client, char *arg);
bool end_msz(zappy_data_t *z, client_t *client, char *arg);

bool start_mct(zappy_data_t *z, client_t *client, char *arg);
bool end_mct(zappy_data_t *z, client_t *client, char *arg);

bool start_tna(zappy_data_t *z, client_t *client, char *arg);
bool end_tna(zappy_data_t *z, client_t *client, char *arg);

bool start_ppo(zappy_data_t *z, client_t *client, char *arg);
bool end_ppo(zappy_data_t *z, client_t *client, char *arg);

bool start_plv(zappy_data_t *z, client_t *client, char *arg);
bool end_plv(zappy_data_t *z, client_t *client, char *arg);

bool start_pin(zappy_data_t *z, client_t *client, char *arg);
bool end_pin(zappy_data_t *z, client_t *client, char *arg);

bool start_sst(zappy_data_t *z, client_t *client, char *arg);
bool end_sst(zappy_data_t *z, client_t *client, char *arg);

bool start_eject_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_eject_cmd(zappy_data_t *z, client_t *cli, char *command);

bool start_fork_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_fork_cmd(zappy_data_t *z, client_t *client, char *command);

bool start_co_nbr_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_co_nbr_cmd(zappy_data_t *z, client_t *client, char *command);

bool start_broadcast_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_broadcast_cmd(zappy_data_t *z, client_t *client, char *command);

bool start_inventory_cmd(zappy_data_t *z, client_t *client, char *command);
bool end_inventory_cmd(zappy_data_t *z, client_t *client, char *command);

bool start_rotate_cmd(zappy_data_t *z, client_t *client, char *command);
bool rotate_right_cmd(zappy_data_t *z, client_t *client, char *command);
bool rotate_left_cmd(zappy_data_t *z, client_t *client, char *command);


bool start_sgt(zappy_data_t *z, client_t *client, char *arg);
bool end_sgt(zappy_data_t *z, client_t *client, char *arg);

bool start_lei(zappy_data_t *z, client_t *client, char *arg);
bool end_lei(zappy_data_t *z, client_t *client, char *command);

bool start_lpi(zappy_data_t *z, client_t *client, char *command);
bool end_lpi(zappy_data_t *z, client_t *client, char *arg);
#endif /* !SERVER_H_ */
