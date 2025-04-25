/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:05:08 by erigolon          #+#    #+#             */
/*   Updated: 2025/04/25 13:30:01 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	free_map(game->map);
	if (game->textu)
		free(game->textu);
	return ;
}

int	init_game(t_game *game)
{
	game->move_count = 0;
	game->count_collec = 0;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!(game->mlx))
		return (FALSE);
	get_textures(game);
	if (!game->textu->floor || !game->textu->wall || !game->textu->collec
		|| !game->textu->chara || !game->textu->exit || !game->textu->exit_2)
		return (init_terminator(game));
	get_images(game);
	if (!game->imag->floor || !game->imag->wall || !game->imag->collec
		|| !game->imag->chara || !game->imag->exit || !game->imag->exit_2)
		return (init_terminator(game));
	draw_map(game, game->imag);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->textu);
	free(game->imag);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(PARAM_ERROR_MSG), 1);
	if (check_mapextension(argv) == FALSE)
		return (ft_printf(FILE_EXT_MSG), FALSE);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (FALSE);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), 1);
	size_map(&game, game.map);
	if (usefull (&game, argv[1]) == FALSE)
		return (free_map(game.map), 1);
	if (init_game(&game) == FALSE)
		return (1);
	return (0);
}
