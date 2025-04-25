/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:32:35 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/20 12:18:07 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32 - 1]
		[game->imag->chara->instances->x / 32] != MAP_WALL)
	{
		game->imag->chara->instances->y -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32 + 1] != MAP_WALL)
	{
		game->imag->chara->instances->x += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32 + 1]
		[game->imag->chara->instances->x / 32] != MAP_WALL)
	{
		game->imag->chara->instances->y += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32 - 1] != MAP_WALL)
	{
		game->imag->chara->instances->x -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	collect_orbs(game);
}
