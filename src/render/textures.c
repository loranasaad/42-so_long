/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:36:03 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 17:30:24 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void destroy_textures(t_game *game)
{
	if (game->img_floor.ptr)
		mlx_destroy_image(game->mlx, game->img_floor.ptr);
	if (game->img_wall.ptr)
		mlx_destroy_image(game->mlx, game->img_wall.ptr);
	if (game->img_exit.ptr)
		mlx_destroy_image(game->mlx, game->img_exit.ptr);
	if (game->img_player.ptr)
		mlx_destroy_image(game->mlx, game->img_player.ptr);
	if (game->img_coin.ptr)
		mlx_destroy_image(game->mlx, game->img_coin.ptr);
	game->img_floor.ptr = NULL;
	game->img_wall.ptr = NULL;
	game->img_exit.ptr = NULL;
	game->img_player.ptr = NULL;
	game->img_coin.ptr = NULL;
}

static int	check_textures(t_game *game)
{
	if (!game->img_floor.ptr || game->img_floor.h != TILE 
		|| game->img_floor.w != TILE)
		return (0);
	if (!game->img_wall.ptr || game->img_wall.h != TILE 
		|| game->img_wall.w != TILE)
		return (0);
	if (!game->img_exit.ptr || game->img_exit.h != TILE 
		|| game->img_exit.w != TILE)
		return (0);
	if (!game->img_player.ptr || game->img_player.h != TILE 
		|| game->img_player.w != TILE)
		return (0);
	if (!game->img_coin.ptr || game->img_coin.h != TILE 
		|| game->img_coin.w != TILE)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	game->img_floor.ptr = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
		 &game->img_floor.w, &game->img_floor.h);
	printf("floor: %p %d %d\n", game->img_floor.ptr, game->img_floor.w, game->img_floor.h);
	game->img_wall.ptr = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
		 &game->img_wall.w, &game->img_wall.h);
	printf("wall : %p %d %d\n", game->img_wall.ptr,  game->img_wall.w,  game->img_wall.h);
	game->img_exit.ptr = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
		 &game->img_exit.w, &game->img_exit.h);
	printf("exit : %p %d %d\n", game->img_exit.ptr,  game->img_exit.w,  game->img_exit.h);
	game->img_player.ptr = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
		 &game->img_player.w, &game->img_player.h);
	printf("plyr : %p %d %d\n", game->img_player.ptr,game->img_player.w,game->img_player.h);
	game->img_coin.ptr = mlx_xpm_file_to_image(game->mlx, "assets/coin.xpm",
		 &game->img_coin.w, &game->img_coin.h);
	printf("coin : %p %d %d\n", game->img_coin.ptr,  game->img_coin.w,  game->img_coin.h);
	if (!check_textures(game))
	{
		write(2, "error! check textures\n", 22);
		destroy_textures(game);
		return (0);
	}
	return(1);
}