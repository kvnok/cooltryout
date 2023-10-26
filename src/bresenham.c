#include "../include/stuff.h"

void bres_draw_line(t_data *data)
{
	// print_coords(data);
	int dx = abs(data->bres->x2 - data->bres->x1); //distance x coords
	int dy = abs(data->bres->y2 - data->bres->y1); //distance y coords
	int sx = data->bres->x1 < data->bres->x2 ? 1 : -1; //slope x
	int sy = data->bres->y1 < data->bres->y2 ? 1 : -1; //slope y
	int err = dx - dy; //move vertical or horizontal
	int e2; //error correction * 2

	while (data->bres->x1 != data->bres->x2 && data->bres->y1 != data->bres->y2) {
		mlx_put_pixel(data->img, data->bres->x1, data->bres->y1, data->bres->color);
		e2 = err * 2; //err * 2 at the start of next calculation
		if (e2 > -dy) {
			err -= dy;
			data->bres->x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			data->bres->y1 += sy;
		}
	}
}