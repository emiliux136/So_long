/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:57 by emilgarc          #+#    #+#             */
/*   Updated: 2025/02/05 16:24:38 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int empty_map(char **map)
{
	if(map[0])
		return (TRUE);
	else
		return (FALSE);
}

int rectangle_map(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if(ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	wrong_map(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == MAP_EXIT || map[i][j] == MAP_ENTRY
				|| map[i][j] == MAP_WALL || map[i][j] == MAP_FLOOR
				|| (map[i][j] == MAP_COLLECTABLE)))
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

int	wall_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	line;

	line = 0;
	while (map[line])
		line++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[line - 1][i] != '1')
			return (FALSE);
		i++;
	}
	j = 0;
	while (i < (line - 1))
	{
		if (map[j][0] != '1' || map[ft_strlen(map[0])][0] != '1')
			return (FALSE);
		j++;
	}
	return (TRUE);
}
