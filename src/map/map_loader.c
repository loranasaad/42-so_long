/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:13:02 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/03 17:31:12 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

static void clear_nl(char *str)
{
	int	i;
	
	if (!str)
		return;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		str[i] = '\0';
}

static int	map_height(const char *file)
{
	int			height;
	int			fd;
	char		*line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
static int	parse_map(t_game *game, const char *file)
{
	int	fd;
	int	i;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while((game->map[i] = get_next_line(fd)))
	{	
		clear_nl(game->map[i]);
		init_player_coll(game, game->map[i], i);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}

int	load_map(t_game *game, const char *file)
{	
	ft_bzero(game, sizeof(t_game));
	game->height = map_height(file);
	game->map = malloc((game->height + 1) * (sizeof(char *)));
	if (!game->map)
		return (0);
	if (!parse_map(game, file))
		return (0);
	game->width = ft_strlen(game->map[0]);
	if (!check_map(game))
	{
		write(2, "Error\nInvalid map\n", 19);
		free_map(game->map);
		game->map = NULL;
		return (0);
	}
	return  (1);
}
