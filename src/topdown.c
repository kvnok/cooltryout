#include "../include/stuff.h"

/*
draw topdown 2D blocks
outlines are probally really annoying to draw
so its better to fill the walls with a color
*/
void topdown_blocks(t_data *data) {
	int x;
	int y;

	x = 0;
	y = 0;
	float block_height = HEIGHT / map_height;
	float block_width = WIDTH / map_width;
	while (y < HEIGHT) {
		x = 0;
		while (x < WIDTH) {
			mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
			int map_y = y / block_height;
			int map_x = x / block_width;
			if (data->map[map_y][map_x] == '1') {
				data->color = 0x302F2CFF;
				mlx_put_pixel(data->img, x, y, data->color);
			}
			x++;
		}
		y++;
	}
}

// draw player
void topdown_player(t_data *data) {
	int size = data->player->size + 1;
	int half_size = size / 2;
	int x = data->player->x * (WIDTH / map_width);
	int y = data->player->y * (HEIGHT / map_height);
	for (int i = -half_size; i < half_size; i++) {
		for (int j = -half_size; j < half_size; j++) {
			mlx_put_pixel(data->img, x + i, y + j, data->player->color);
		}
	}
}

/*
need to figure out how to draw a line from the player to the direction the player is facing
so need the direction and the position of the player
also how long should the line be?
*/

// draw lines
void topdown_drawline(t_data *data) {
	// draw line from player to direction player is facing
	int line_length = 100;
	int x = data->player->x * (WIDTH / map_width);
	int y = data->player->y * (HEIGHT / map_height);
	int x2 = x + (data->player->dir * 100) + line_length;
	int y2 = y + (data->player->dir * 100) + line_length;
	data->bres->x1 = x;
	data->bres->y1 = y;
	data->bres->x2 = x2;
	data->bres->y2 = y2;
	data->bres->color = 0x0000FFFF;
	bres_draw_line(data);
}

// handle collisions
