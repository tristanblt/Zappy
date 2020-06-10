/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** split
*/

#include "server.h"

bool split_out_quote(char *quoteset, char ***ret, int *cursor)
{
    char *tok = strtok(quoteset, " ");

    for (int j = 0; tok != NULL; j++) {
        *ret = realloc(*ret, (*cursor + 2) * sizeof(char *));
        if (!*ret)
            return (false);
        ret[0][*cursor] = strdup(tok);
        ret[0][*cursor + 1] = NULL;
        tok = strtok(NULL, " ");
        (*cursor)++;
    }
    return (true);
}

bool split_quoteset(char *quoteset, char fist_char, char ***ret, int i)
{
    static int cursor = 0;

    if (!i)
        cursor = 0;
    if ((fist_char == '\"') - (i % 2) != 0) {
        *ret = realloc(*ret, (cursor + 2) * sizeof(char *));
        if (!*ret)
            return (false);
        ret[0][cursor] = strdup(quoteset);
        ret[0][cursor + 1] = NULL;
        cursor++;
    }
    else
        split_out_quote(quoteset, ret, &cursor);
    return (true);
}

char **split_command(char *command)
{
    char **quoteset = NULL;
    char **ret = NULL;
    char *tok = NULL;
    char *str;

    if (!command || command[0] == '\n' || command[0] == '\0')
        return (NULL);
    if (!(str = strdup(command)))
        return (NULL);
    tok = strtok(str, "\"");
    for (int i = 0; tok != NULL; i++) {
        if (!(quoteset = realloc(quoteset, (i + 2) * sizeof(char *))))
            return (NULL);
        quoteset[i] = strdup(tok);
        quoteset[i + 1] = NULL;
        tok = strtok(NULL, "\"");
    }
    for (int i = 0; quoteset[i]; i++)
        if (!split_quoteset(quoteset[i], command[0], &ret, i))
            return (NULL);
    return (ret);
}