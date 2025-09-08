/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:55:48 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/08 15:12:41 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static char	**dup_map(char **map, int height)
{
	int		i;
	char	**copy;
	
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	ff_visit(int x, int y, t_flood *fl)
{
	if (y < 0 || y >= fl->height || x < 0 || x >= fl->width)
		return ;
	if (fl->map[y][x] == '1' || fl->map[y][x] == 'V')
		return ;
	if (fl->map[y][x] == 'E')
	{
		fl->found_e = 1;
		fl->map[y][x] = 'V';
		return ;
	}
	if (fl->map[y][x] == 'C')
		fl->found_c++;
	fl->map[y][x] = 'V';
	ff_visit(x + 1, y, fl);
	ff_visit(x - 1, y, fl);
	ff_visit(x, y - 1, fl);
	ff_visit(x, y + 1, fl);
}


int	check_path(t_game *g)
{
	t_flood flood;

	flood.map = dup_map(g->map, g->height);
	if (!flood.map)
		return (0);
	flood.found_c = 0;
	flood.found_e = 0;
	flood.height = g->height;
	flood.width = g->width;
	ff_visit(g->player_x, g->player_y, &flood);
	if (flood.found_c != g->collectibles || !flood.found_e)
	{
		free_map(flood.map);
		return (0);
	}
	free_map(flood.map);
	return (1);
}