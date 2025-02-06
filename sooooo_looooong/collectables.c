/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:00 by emilgarc          #+#    #+#             */
/*   Updated: 2025/02/06 19:10:18 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_collec(t_game *game)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	delete_orbs(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->n_collec;
	while (i < count)
	{
		if (((game->imag->collec->instances[i].y
				== game->imag->chara->instances->y)
			&& (game->imag->collec->instances[i].x
				== game->imag->chara->instances->x))
			&& game->imag->collec->instances[i].enabled == true)
		{
			count--;
			game->imag->collec->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	collect_orbs(t_game *game)
{
	if(game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] == MAP_COLLECTABLE)
	{
		delete_orbs(game);
		game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] = MAP_FLOOR;
		game->count_collec++;
		if (game->count_collec == game->n_collec)
			game->imag->exit->instances->enabled = false;
	}
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] == MAP_EXIT)
	{
		if (game->count_collec == game->n_collec)
			mlx_close_window(game->mlx);
	}
}
