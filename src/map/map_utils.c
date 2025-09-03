/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:34:08 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 19:44:05 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_coll(t_game *game ,char *str, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == 'P')
		{
			game->player_x = j;
			game->player_y = i;
		}
		if (str[j] == 'C')
			(game->collectibles)++;
		j++;	
	}
	return;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}