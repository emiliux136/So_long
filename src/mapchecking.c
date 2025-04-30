/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:57 by emilgarc          #+#    #+#             */
/*   Updated: 2025/04/30 15:01:25 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if the map exist by looking fot the first line of the matrix.
// If OK return True, if does't find anything return False.
int	empty_map(char **map)
{
	if (map[0])
		return (TRUE);
	else
		return (FALSE);
}

// Measures the first line of the map, and check if all lines
// have the same lenght and return TRUE, if not return FALSE.
int	rectangle_map(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf("%s", RECT_MSG);
			return (FALSE);
		}
		else
			i++;
	}
	return (TRUE);
}

//Go over the whole map with two iterators and checks if everything
//is there, if something is missing return FALSE and prints a message.
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
			{
				ft_printf("%s", WRONG_MSG);
				return (FALSE);
			}
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

//Check if the map is entirely surrounded by wall.
//If everething is OK returns TRUE, if not, FALSE and prints a message.
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
	while (j < line)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (FALSE);
		j++;
	}
	return (TRUE);
}

//This function checks if the extension of the map is correct.
int	check_mapextension(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (av[1][i - 1] == 'r' && av[1][i - 2] == 'e'
		&& av[1][i - 3] == 'b' && av[1][i - 4] == '.')
	{
		if (av[1][i - 5] == '/' || av[1][i - 5] == '\n')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
