/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:15:21 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/18 17:56:13 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 256
#define HEIGHT 256

# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/gnl/get_next_line_bonus.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdint.h>

# define MAP_EXIT 'E'
# define MAP_ENTRY 'P'
# define MAP_COLLECTABLE 'C'
# define MAP_WALL '1'
# define MAP_FLOOR '0'

# define PARAM_ERROR_MSG "Error:\nIncorrect parameters number. (ㅠ﹏ㅠ)\n"
# define FILE_EXT_MSG "Error:\nInvalid map extension. (ㅠ﹏ㅠ)\n"
# define EMPTY_MSG "Error:\nEmpty map. (ㅠ﹏ㅠ)\n"
# define RECT_MSG "Error:\nNon rectangular map. (ㅠ﹏ㅠ)\n"
# define WRONG_MSG "Error:\nComponents are not valid. (ㅠ﹏ㅠ)\n"
# define WALL_MSG "Error:\nWalls aren't closed. (ㅠ﹏ㅠ)\n"
# define MIN_TILES_MSG "Error:\nComponents are not valid. (ㅠ﹏ㅠ)\n"
# define PATH_MSG "Error:\nCan't find a way out. (ㅠ﹏ㅠ)\n"

# define BUFF_SIZE 10000
# define FALSE		1
# define TRUE		0
# define MOVE		32

typedef struct s_textures {
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*chara;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_2;
}				t_textures;

typedef struct s_images {
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collec;
	mlx_image_t	*chara;
	mlx_image_t	*exit;
	mlx_image_t	*exit_2;
}				t_images;

typedef struct s_game
{
	struct s_textures	*textu;
	struct s_images		*imag;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					count_collec;
	int					move_count;
	int					n_collec;
	char				**map_2;
}						t_game;

int 	main(int argc, char **argv);

//=================== MAPS ===================//

int 	check_mapextension(char **name); //chequea que la extension es .ber
char	**read_map(char *script_map); //lee el mapa y lo devuelve en un char al que le hacemos un split
int		check_map(char **map); // FUNCION RAMAL QUE CHEQUEA LAS DE ABAJO
int		empty_map(char **map); //si el mapa esta vacio
int		rectangle_map(char **map); //si es un rectangulo
int		wrong_map(char **map); //si algo no se corresponde a lo esperable... ejemplo hay una letra que no es nada
int		wall_map(char **map); //chequea si las paredes esteriores estan cerradas 
int		min_titles(char **map); // falla si no hay coleccionables o salidas suficientes
void	free_map(char **map); 
int		valido(t_game *game, char *fd);
void	flood_map(t_game *game, int y, int x); //rellena todo el mapa de X de forma iterativa
int		*start_position(char **map); //mira donde empieza nuestro personaje y devuelve las coordenadas en forma de doble valor numérico
int		check_flood(char **map); // Comprueba que todo se ha rellenado de X correctamente
void	size_map(t_game *game, char **map); //almacena el numero de coleccionables en n_collect y el mapwidth y el map height 
// multipica i*32 por que cada casilla tiene 32pixeles
int		total_collec(t_game *game); //Cuenta la cantidad de coleccionables que hay y los devuelve

int		wrongwall();
char	**emptymsg();
//=================== MLX42 ===================//

int		init_game(t_game *game);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_map(t_game *game, t_images *image);
void	draw_floor(t_game *game, t_images *image);

//=================== MOVE ===================//

void	my_key_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);

//=================== COLLECT ===================//

void	collect_orbs(t_game *game);
void	delete_orbs(t_game *game);
int		total_collec(t_game *game);

#endif