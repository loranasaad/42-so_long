/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:20:59 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/01 15:53:27 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	on_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		on_close(game);
	return (0);
}