#include "../include/stuff.h"

void free_map(t_data *data) {
	int y;

	y = 0;
	while (y < map_height) {
		free(data->map[y]);
		y++;
	}
	free(data->map);
}

void cleanup(t_data *data) {
	free_map(data);
	free(data->player);
	free(data->bres);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
}
