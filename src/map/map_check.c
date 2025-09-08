/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:54:43 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/08 15:14:33 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static void	update_counts(char tile, int *p, int *e, int *c )
{
	if (tile == 'P')
		(*p)++;
	else if (tile == 'E')
		(*e)++;
	else if (tile == 'C')
		(*c)++;
}

static int	check_count(char **map)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;
	int	c_count;
	
	i = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			update_counts(map[i][j], &p_count, &e_count, &c_count);
			j++;
		}
		i++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (0);
	return (1);
}

static int	check_walls(t_game *game, int height, int width)
{
	int	i;
	
	i = 0;
	while (i < width)
	{
		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
			return (0);		
		i++;
	}
	return (1);
}

static int	check_rectangle(t_game *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{	
	if (!check_count(game->map) || !check_rectangle(game))
		return (0);
	if (!check_walls(game, game->height, game->width))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}
