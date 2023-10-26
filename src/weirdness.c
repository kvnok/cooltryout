#include "../include/stuff.h"

void rainbow_screen(t_data *data) {
	int x;
	int y;

	x = 0;
	while (x < WIDTH) {
		y = 0;
		data->color = data->colors[rand() % 3];
		while (y < HEIGHT) {
			// data->color = colors[rand() % 3];
			// data->color = pixel_select(rand() % 255, rand() % 255, rand() % 255, 255);
			mlx_put_pixel(data->img, x, y, data->color);
			y++;
		}
		x++;
	}
}
