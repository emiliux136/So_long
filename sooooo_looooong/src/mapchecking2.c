/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecking2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:59 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/20 13:29:44 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	min_titles(char **map)
{
	int	i;
	int	o;
	int	salida;
	int	colec;

	i = 0;
	salida = 0;
	colec = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (map[i][o] == MAP_EXIT || map[i][o] == MAP_ENTRY)
				salida++;
			if (map[i][o] == MAP_COLLECTABLE)
				colec++;
			o++;
		}
		i++;
	}
	if (salida != 2 || colec < 1)
		return (FALSE);
	return (TRUE);
}

int	*start_position(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == MAP_ENTRY)
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_map(t_game *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->map_width || y > game->map_height
			|| game->map_2[y][x] == '1' || game->map_2[y][x] == 'X'))
	{
		game->map_2[y][x] = 'X';
		flood_map(game, y + 1, x);
		flood_map(game, y - 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y, x - 1);
	}
}

int	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == MAP_WALL || map[i][j] == MAP_FLOOR
				|| map[i][j] == 'X'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	usefull(t_game *game, char *fd)
{
	int	*pos;

	game->map_2 = read_map(fd);
	pos = start_position(game->map_2);
	flood_map(game, pos[0], pos[1]);
	if (check_flood(game->map_2) == FALSE)
	{
		free(pos);
		free_map(game->map_2);
		return (ft_printf(PATH_MSG), FALSE);
	}
	free(pos);
	free_map(game->map_2);
	return (TRUE);
}
