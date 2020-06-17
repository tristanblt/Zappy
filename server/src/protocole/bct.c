/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** bct - content of a tile
*/

#include "server.h"

void write_ressources(client_t *client, extracted_content_t content)
{
    char buffer[6] = {0};

    sprintf(buffer, "%.0f", content.ressources->food);
    add_raw_data(&client->out, buffer);
    sprintf(buffer, "%d", content.ressources->linemate);
    add_raw_data(&client->out, buffer);
    sprintf(buffer, "%d", content.ressources->deraumere);
    add_raw_data(&client->out, buffer);
    sprintf(buffer, "%d", content.ressources->sibur);
    add_raw_data(&client->out, buffer);
    sprintf(buffer, "%d", content.ressources->mendiane);
    add_raw_data(&client->out, buffer);
    sprintf(buffer, "%d", content.ressources->phiras);
    add_raw_data(&client->out, buffer);
    sprintf(buffer, "%d", content.ressources->thystame);
    add_raw_data(&client->out, buffer);
}

bool start_bct(zappy_data_t *z, client_t *client, char *arg)
{
    char **array_arg = split_command(arg);
    int x;
    int y;
    extracted_content_t content;

    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    if (split_nb_argument(array_arg) < 2)
        return (-1);
    x = graph_value(z->data.map_sz.x, atoi(array_arg[0]));
    y = graph_value(z->data.map_sz.y, atoi(array_arg[1]));
    content = get_tile_content(&z->data, z->server, x, y);
    add_raw_data(&client->out, "bct ");
    add_raw_data(&client->out, int_to_char(x));
    add_raw_data(&client->out, " ");
    add_raw_data(&client->out, int_to_char(y));
    add_raw_data(&client->out, " ");
    write_ressources(client, content);
    add_raw_data(&client->out, "\r\n");
    return (SUCCESS);
}

bool end_bct(zappy_data_t *z, client_t *client, char *arg)
{
    (void)*z;
    (void)*client;
    (void)arg;
    return (SUCCESS);
}