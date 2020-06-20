/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** inventory
*/

#include "server.h"

bool start_inventory_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 1.0 / z->data.f;
    return (SUCCESS);
}

void inventory_cmd_next(client_t *client)
{
    add_raw_data(&client->out, ", sibur ");
    add_raw_data(&client->out,
    int_to_char(((c_data_t *)client->data)->inventory.sibur));
    add_raw_data(&client->out, ", mendiane ");
    add_raw_data(&client->out,
    int_to_char(((c_data_t *)client->data)->inventory.mendiane));
    add_raw_data(&client->out, ", phiras ");
    add_raw_data(&client->out,
    int_to_char(((c_data_t *)client->data)->inventory.phiras));
    add_raw_data(&client->out, ", thystame ");
    add_raw_data(&client->out,
    int_to_char(((c_data_t *)client->data)->inventory.linemate));
    add_raw_data(&client->out, " ]\r\n");
}

bool end_inventory_cmd(zappy_data_t *z, client_t *client, char *command)
{
    int food = ((int)((c_data_t *)client->data)->inventory.food + 1) * z->data.f / 126;
    (void)command;
    (void)z;
    add_raw_data(&client->out, "[ food ");
    add_raw_data(&client->out,
    int_to_char(food));
    add_raw_data(&client->out, ", linemate ");
    add_raw_data(&client->out,
    int_to_char(((c_data_t *)client->data)->inventory.linemate));
    add_raw_data(&client->out, ", deraumere ");
    add_raw_data(&client->out,
    int_to_char(((c_data_t *)client->data)->inventory.deraumere));
    inventory_cmd_next(client);
    return (SUCCESS);
}