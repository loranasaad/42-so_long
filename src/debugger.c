#include <stdio.h>
#include "so_long.h"

void    print_map(t_game *game)
{
    int i = 0;

    printf("---- MAP DEBUG ----\n");
    while (game->map[i])
    {
        printf("%s\n", game->map[i]);
        i++;
    }
    printf("-------------------\n");
    printf("Width: %d  Height: %d\n", game->width, game->height);
}