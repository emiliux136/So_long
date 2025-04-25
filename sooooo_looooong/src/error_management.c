/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:32 by emilgarc          #+#    #+#             */
/*   Updated: 2025/04/25 13:07:26 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function that prints the wall error management.
int	wrongwall(void)
{
	ft_printf("%s", WALL_MSG);
	return (FALSE);
}

//Function that prints the empty map error management.
char	**emptymsg(void)
{
	ft_printf("%s", EMPTY_MSG);
	return (0);
}

//Function that prints the image error management.
void	imag_error(t_game *game)
{
	if(game)	
		printf("Error:\nFailed to load one or more textures.\n");
	if (!game->textu->floor)
		printf("%s./textures/floor.png\n", FTL);
	if (!game->textu->wall)
		printf("%s./textures/wall.png\n", FTL);
	if (!game->textu->collec)
		printf("%s./textures/spark21.png\n", FTL);
	if (!game->textu->chara)
		printf("%s./textures/Mago.png\n", FTL);
	if (!game->textu->exit)
		printf("%s./textures/salida.png\n", FTL);
	if (!game->textu->exit_2)
		printf("%s./textures/salida2.png\n", FTL);
}

//Function that calls the mlx terminator and ends all the process.
int	init_terminator(t_game *game)
{
	mlx_terminate(game->mlx);
	return (FALSE);
}
