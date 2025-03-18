/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:08:33 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/18 17:39:24 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures)); 
	if (!game->textu)
    {
        printf("Error:\nFailed to allocate memory for textures.\n");
        exit(EXIT_FAILURE);
    }
	game->textu->floor = mlx_load_png("./textures/floor.png");
	game->textu->wall = mlx_load_png("./textures/wall.png");
	game->textu->collec = mlx_load_png("./textures/Spark21.png");
	game->textu->chara = mlx_load_png("./textures/Mago.png");
	game->textu->exit = mlx_load_png("./textures/Salida.png");
	game->textu->exit_2 = mlx_load_png("./textures/Salida2.png");
	if (!game->textu->floor || !game->textu->wall || !game->textu->collec || 
        !game->textu->chara || !game->textu->exit || !game->textu->exit_2)
    {
        printf("Error:\nFailed to load one or more textures.\n");
        if (!game->textu->floor) printf("Failed to load: ./textures/floor.png\n");
        if (!game->textu->wall) printf("Failed to load: ./textures/wall.png\n");
        if (!game->textu->collec) printf("Failed to load: ./textures/spark21.png\n");
        if (!game->textu->chara) printf("Failed to load: ./textures/Mago.png\n");
        if (!game->textu->exit) printf("Failed to load: ./textures/salida.png\n");
        if (!game->textu->exit_2) printf("Failed to load: ./textures/salida2.png\n");
        exit(EXIT_FAILURE);
    }
	ft_printf("OK: Textures loaded propperly \n");
}

void	get_images(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_images)); 	
	if (!game->imag)
    {
        printf("Error:\nFailed to allocate memory for images.\n");
        exit(EXIT_FAILURE);
    }
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->imag->chara = mlx_texture_to_image(game->mlx, game->textu->chara);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->chara);
	mlx_delete_texture(game->textu->exit);
	mlx_delete_texture(game->textu->exit_2);
	ft_printf("OK: Images loaded propperly \n");
}

void	draw_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
			if (game->map[y][x] == MAP_WALL)
				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
			if (game->map[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx, image->exit_2, x * 32, y * 32);
				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_images *image)
{
	int	x;
	int	y;
	
	draw_floor(game, image);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == MAP_COLLECTABLE)
				mlx_image_to_window(game->mlx, image->collec, x * 32, y * 32);
			if (game->map[y][x] == MAP_ENTRY)
				mlx_image_to_window(game->mlx, image->chara, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
