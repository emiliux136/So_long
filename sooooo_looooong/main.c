/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:05:08 by erigolon          #+#    #+#             */
/*   Updated: 2025/02/06 19:18:45 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->move_count = 0;
	game->count_collec = 0;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if(!(game->mlx))
		return (FALSE);
	get_textures(game);
	get_images(game);
	draw_map(game, game->imag);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->textu);
	free(game->imag);
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if(argc != 2)
		return (ft_printf(PARAM_ERROR_MSG), 1);
	game.map = read_map(argv[1]);
	if(!game.map)
		return(FALSE);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), 1);
	size_map(&game, game.map);
	if (valido (&game, argv[1]) == FALSE)
		return (free_map(game.map), 1);
	if (init_game(&game) == FALSE)
		return (1);
	return (0);
}

