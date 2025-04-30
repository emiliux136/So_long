/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:15:21 by emilgarc          #+#    #+#             */
/*   Updated: 2025/04/30 12:52:47 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 256
# define HEIGHT 256

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
# define FTL "Failed to load: "

# define BUFF_SIZE 10000
# define FALSE		1
# define TRUE		0
# define MOVE		32

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*chara;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_2;
}				t_textures;

typedef struct s_images
{
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
	int					n_exit;
	int					n_entry;
	char				**map_2;
}						t_game;

int		main(int argc, char **argv);

//=================== MAPS MANAGEMENT ===================//

int		check_mapextension(char **name);
char	**read_map(char *script_map);
int		check_map(char **map, t_game *game);
int		empty_map(char **map);
int		rectangle_map(char **map);
int		wall_map(char **map);
int		min_titles(t_game *game);
void	free_map(char **map);
void	free_images(t_game *game);
int		usefull(t_game *game, char *fd);
void	flood_map(t_game *game, int y, int x);
int		*start_position(char **map);
int		check_flood(char **map);
void	size_map(t_game *game, char **map);

//=================== ERROR MANAGEMENT ===================//

int		wrongwall(void);
int		emptymsg(void);
void	imag_error(t_game *game);
int		wrong_map(char **map);
int		init_terminator(t_game *game);
void	free_game(t_game *game);

//=================== MLX42 COMMUNICATION ===================//

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