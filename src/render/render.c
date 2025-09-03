/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:37:17 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 18:31:25 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_put_image(t_game *g, char c, int x, int y)
{	
	x = x * TILE;
	y = y * TILE;
	mlx_put_image_to_window(g->mlx, g->win, g->img_floor.ptr, x, y);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall.ptr, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit.ptr, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player.ptr, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_coin.ptr, x, y);
}

void	draw_tile(t_game *g, int x, int y)
{
	char	c;

	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return;
	c = g->map[y][x];
	draw_put_image(g, c, x, y);
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			draw_put_image(g, g->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

