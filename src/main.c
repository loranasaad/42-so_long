/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:31:23 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/01 16:35:29 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;
	if (argc != 2)
	{
		write(2, "Invalid argument\n", 18);
		return (1);
	}
	if (!load_map(&game, argv[1]) || !init_mlx(&game) )
		return (1);
	print_map(&game); 
	mlx_hook(game.win, 17, 0, on_close, &game);
	mlx_hook(game.win, 2, 0, on_key, &game);
	mlx_loop(game.mlx);
	return (0);
}