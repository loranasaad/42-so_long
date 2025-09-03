/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:30:00 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 19:56:28 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_target(t_game *g, int nx, int ny)
{
	if (ny < 0 || ny >= g->height || nx < 0 || nx >= g->width)
		return (-1);
	if (g->map[ny][nx] == '1')
		return (-1);
	if (g->map[ny][nx] == 'E')
	{	
		if (g->collectibles == 0)
			return (1);
		return (-1);
	}
	if (g->map[ny][nx] == 'C')
		g->collectibles--;
	return (0);
}

int	move_player(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;
	int	check;
	
	nx = g->player_x + dx;
	ny = g->player_y + dy;
	check = check_target(g, nx, ny);
	if (check == -1)
		return (0);
	if (check == 1)
	{
		win_game(g);
		return(1);
	}
	g->map[g->player_y][g->player_x] = '0';
	draw_tile(g, g->player_x, g->player_y);
	g->map[ny][nx] = 'P';
	g->player_x = nx;
	g->player_y = ny;
	g->moves++;
	draw_tile(g, nx, ny);
	show_moves(g);
	return (1);
}

