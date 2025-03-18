/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:24:04 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/18 17:59:01 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->n_collec = total_collec(game);
	game->map_width = ft_strlen(map[0]) * 32;
	while (map[i])
		i++;
	game->map_height = i * 32;
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

char	**read_map(char *script_map)
{
	int 	fd;
	char	*temp_map;
	char	**map;
	int		nbytes;

	nbytes = 0;
	temp_map = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if(!temp_map)
		return (0);
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
			free(temp_map);
			return (0);
	}
	nbytes = read(fd, temp_map, BUFF_SIZE);
	if (nbytes == -1 || nbytes == 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}

int	check_map(char **map)
{
	if (empty_map(map) == FALSE)
		return (ft_printf(EMPTY_MSG), FALSE);
	if (rectangle_map(map) == FALSE)
		return (ft_printf(RECT_MSG), FALSE);
	if (wrong_map(map) == FALSE)
		return (ft_printf(WRONG_MSG), FALSE);
	if (wall_map(map) == FALSE)
		return  (ft_printf(WALL_MSG), FALSE);
	if (min_titles(map) == FALSE)
		return (ft_printf(MIN_TILES_MSG), FALSE);
	return (TRUE);
}