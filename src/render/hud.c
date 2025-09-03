/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:48:27 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 20:15:39 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_hud_background(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall.ptr, i * TILE, 0);
		i++;
	}
}

void	show_moves(t_game *g)
{
	char	*num;
	char	*msg;

	num = ft_itoa(g->moves);
	if (!num)
		return;
	msg = "Moves: ";
	draw_hud_background(g);
	mlx_string_put(g->mlx, g->win, 8, TILE / 2, 0xFFFFFF, msg);
	mlx_string_put(g->mlx, g->win, 60, TILE / 2, 0xFFFFFF, num);
	free(num);
}