/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:47:12 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/01 15:47:55 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	int	win_width;
	int	win_height;
	
	win_width = game->width * TILE;
	win_height = game->height * TILE;
	if (!(game->mlx = mlx_init()))
		return (0);
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)	
		return (0);
	return (1);
	
}