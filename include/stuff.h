#ifndef STUFF_H
# define STUFF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 960

#define map_width 10
#define map_height 10

typedef struct s_vec2 {
	float			x;
	float			y;
}	t_vec2;

typedef struct s_bres
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	uint32_t		color;
}	t_bres;

typedef struct s_player {
	float			x;
	float			y;
	float			angle;
	float			fov;
	float			speed;
	float			dir;
	float			rot_speed;
	float			move_speed;
	t_vec2			plane;
	uint32_t		color;
	int				size;
}	t_player;

typedef struct s_data {
	mlx_t			*mlx;
	mlx_image_t		*img;
	uint32_t		color;
	char			**map;
	uint32_t		colors[3];
	t_player		*player;
	t_bres			*bres;
}	t_data;

// init_fill_struct.c
char		**fill_map(t_data *data);
void		init_data(t_data *data);

// topdown.c
void		topdown_blocks(t_data *data);
void		topdown_player(t_data *data);
void		topdown_drawline(t_data *data);

// bresenham.c
void		bres_draw_line(t_data *data);

// utils.c
int32_t		pixel_select(int32_t r, int32_t g, int32_t b, int32_t a);
void		print_map(char **map);

// weirdness.c
void		rainbow_screen(t_data *data);

// keyhook.c
void		topdown_draw(t_data *data);
void loop_hook_func(void *param);

// cleanup.c
void		free_map(t_data *data);
void		cleanup(t_data *data);

#endif
