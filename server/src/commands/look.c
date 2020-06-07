/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** look
*/

#include "server.h"

void print_type_content_tile(bool *first, client_t *client, int quantity,
char *what)
{
    for (int i = quantity; i > 0; i++) {
        if (*first == true) {
            add_raw_data(&client->out, what);
            *first == false;
        } else {
            add_raw_data(&client->out, " ");
            add_raw_data(&client->out, what);
        }
    }
}

void print_content_tile(client_t *client, extracted_content_t content)
{
    int first = true;

    print_type_content_tile(&first, client, content.nb_player, "player");
    print_type_content_tile(&first, client, content.ressources->food, "food");
    print_type_content_tile(&first, client, content.ressources->linemate,
    "linemate");
    print_type_content_tile(&first, client, content.ressources->deraumere,
    "deraumere");
    print_type_content_tile(&first, client, content.ressources->sibur, "sibur");
    print_type_content_tile(&first, client, content.ressources->mendiane,
    "mendiane");
    print_type_content_tile(&first, client, content.ressources->phiras,
    "phiras");
    print_type_content_tile(&first, client, content.ressources->thystame,
    "thystame");
}

int look_right_left(client_t *cli, server_t *server, int signe_x)
{
    extracted_content_t content;
    int x = ((c_data_t *)cli->data)->pos.x;
    int y = ((c_data_t *)cli->data)->pos.y;

    add_raw_data(&cli->out, "[");
    for (int cpt_x = 0; cpt_x <= ((c_data_t *)cli->data)->level; cpt_x++) {
        for (int cpt_y = 0; cpt_y < 1 + cpt_x * 2; cpt_y++) {
            content = get_tile_content(((c_data_t *)cli->data), server, x, y);
            if (x != ((c_data_t *)cli->data)->pos.x && y !=
            ((c_data_t *)cli->data)->pos.y)
                add_raw_data(&cli->out, ",");
            print_content_tile(cli, content);
            y++;
        }
        x += signe_x;
        for (int g = 0; g <= 1 + cpt_x * 2; g++)
            y--;
    }
    add_raw_data(&cli->out, "]\n");
    return (0);
}

int look_bottom_top(client_t *cli, server_t *server, int signe_y)
{
    extracted_content_t content;
    int y = ((c_data_t *)cli->data)->pos.y;
    int x = ((c_data_t *)cli->data)->pos.x;

    add_raw_data(&cli->out, "[");
    for (int cpt_y = 0; cpt_y <= ((c_data_t *)cli->data)->level; cpt_y++) {
        for (int cpt_x = 0; cpt_x < 1 + cpt_y * 2; cpt_x++) {
            content = get_tile_content(((c_data_t *)cli->data), server, x,
            y);
            if (x != ((c_data_t *)cli->data)->pos.x && y !=
            ((c_data_t *)cli->data)->pos.y)
                add_raw_data(&cli->out, ",");
            print_content_tile(cli, content);
            x++;
        }
        y += signe_y;
        for (int g = 0; g <= 1 + cpt_y * 2; g++)
            x--;
    }
    add_raw_data(&cli->out, "]\n");
    return (0);
}

int look(server_t *server, client_t *client, char *arg)
{
    switch (((c_data_t *)client->data)->dir) {
        case 0:
            look_bottom_top(client, server, -1);
            break;
        case 1:
            look_right_left(client, server, 1);
            break;
        case 2:
            look_bottom_top(client, server, 1);
            break;
        case 3:
            look_right_left(client, server, -1);
            break;
    }
}