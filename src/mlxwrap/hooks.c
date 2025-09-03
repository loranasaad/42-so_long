/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:20:59 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 17:59:25 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_close(t_game *game)
{
	destroy_textures(game);
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	on_key(int keycode, t_game *game)
{	
	if (keycode == KEY_ESC)
		on_close(game);
	if (game->ended == 1)
		return (0);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}