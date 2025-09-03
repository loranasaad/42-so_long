/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:34:54 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/01 16:36:09 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

# define TILE 64
# define KEY_ESC 53

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	t_img	img_wall;
	t_img	img_floor;
	t_img	img_player;
	t_img	img_exit;
	t_img	img_coin;
}			t_game;

int	check_map(t_game *game);

int	load_map(t_game *game, const char *file);

int	init_mlx(t_game *game);

int	on_close(t_game *game);
int	on_key(int keycode, t_game *game);

void    print_map(t_game *game);

#endif