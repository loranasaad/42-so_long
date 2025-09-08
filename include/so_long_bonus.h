/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:34:54 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/05 11:55:59 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

# define TILE 32
# define KEY_ESC 53
# define KEY_W     13
# define KEY_A     0
# define KEY_S     1
# define KEY_D     2
# define KEY_LEFT  123
# define KEY_RIGHT 124
# define KEY_DOWN  125
# define KEY_UP    126

typedef struct s_anim
{
	int	dir;
	int	frame;
	int	tick;
	int	speed;
}		t_anim;

typedef struct s_pimgs
{
	t_img	down[3];
	t_img	left[3];
	t_img	right[3];
	t_img	up[3];
}			t_pimgs;


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
	int		ended;
	t_img	img_wall;
	t_img	img_floor;
	t_img	img_player;
	t_img	img_exit;
	t_img	img_coin;
	t_anim	p_anim;
	t_pimgs	p_img;
}			t_game;

int		check_map(t_game *game);

int		load_map(t_game *game, const char *file);

void	win_game(t_game *g);

void	init_player_coll(t_game *game ,char *str, int i);
void	free_map(char **map);

int		init_mlx(t_game *game);

void 	destroy_textures(t_game *game);
int		load_textures(t_game *game);

void	draw_tile(t_game *g, int x, int y);
void	draw_map(t_game *game);

int		move_player(t_game *game, int x, int y);

int		on_close(t_game *game);
int		on_key(int keycode, t_game *game);

char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);

void	show_moves(t_game *g);



#endif