#include "../include/stuff.h"

char **fill_map(t_data *data) {
	int x;
	int y;

	x = 0;
	y = 0;
	data->map = malloc(sizeof(char *) * map_height);
	char random_change[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '1', '1'};

	while (y < map_height) {
		data->map[y] = malloc(sizeof(char) * map_width + 1);
		x = 0;
		while (x < map_width) {
			if (x == 0 || x == map_width - 1 || y == 0 || y == map_width - 1) {
				data->map[y][x] = '1';
			} else {
				data->map[y][x] = random_change[rand() % 10];
			}
			x++;
		}
		data->map[y][x] = '\0';
		y++;
	}
	// printf("map filled\n");
	print_map(data->map);
	// printf("map printed\n");
	return data->map;
}

void init_data(t_data *data) {
	// printf("init_data\n");
	data->mlx = mlx_init(WIDTH, HEIGHT, "mlx42pilot", true);
	// printf("mlx_init\n");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// printf("mlx_new_image\n");
	data->map = fill_map(data);
	// printf("fill_map\n");
	data->colors[0] = 0xFF0000FF;
	data->colors[1] = 0x00FF00FF;
	data->colors[2] = 0x0000FFFF;
	// printf("init_data done\n");
	// player
	data->player = malloc(sizeof(t_player));
	data->player->x = 2;
	data->player->y = 5;
	data->player->dir = 0;
	data->player->plane.x = 0;
	data->player->plane.y = 0.66;
	data->player->move_speed = 0.05;
	data->player->rot_speed = 0.05;
	data->player->color = 0x0000FFFF;
	data->player->angle = 0;
	data->player->fov = 60;
	data->player->speed = 0.05;
	data->player->size = 20;
	// bres
	data->bres = malloc(sizeof(t_bres));
	data->bres->x1 = 0;
	data->bres->y1 = 0;
	data->bres->x2 = 0;
	data->bres->y2 = 0;
}
