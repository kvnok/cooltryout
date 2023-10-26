/*
maybe in loop hook function that always calculates the collisions
and key hook only draws it, might be unnessesary though
cuz only when the player moves, do i know what do calculate next
*/

/*
void loop_hook_function(void *param) {
	t_data *data;

	data = (t_data *)param;
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		data->color = colors[rand() % 3];
		while (y < HEIGHT)
		{
			// data->color = colors[rand() % 3];
			// data->color = pixel_select(rand() % 255, rand() % 255, rand() % 255, 255);
			mlx_put_pixel(data->img, x, y, data->color);
			y++;
		}
		x++;
	}
}
*/

/*
int main() {
	// mlx_loop_hook(data.mlx, loop_hook_function, &data);
}
*/

/*
should only use this function for key presses
or should i use this for all, and use the action to determine what to do?
void ft_on_key(mlx_key_data_t keydata, void *param) {
}
*/

/*
data->map[map_width][map_height] = {
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '1', '0', '1', '1', '1', '1', '0', '1',
		'1', '0', '1', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '1', '1', '0', '0', '0', '1',
		'1', '0', '0', '0', '1', '1', '0', '0', '0', '1',
		'1', '0', '1', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '1', '0', '0', '0', '0', '1', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'
	};
*/

/*
// draw player
void topdown_player(t_data *data) {
	// draw a dot of 10 pixels wide at the player position
	// draw a line from the player position to the direction the player is facing
	// draw a circle around the player to show the fov
	// draw a line from the player to the edge of the fov
	printf("topdown_player\n");
	static const double PI = 3.1415926535;
	double i, angle, x1, y1;
	int x = data->player.x;
	int y = data->player.y;
	int size = data->player.size;
	for (int j = 0; j < size; j++) {
		int r = j;
		for (i = 0; i < 360; i += 0.1) {
			angle = i;
			x1 = r * cos(angle * PI / 180);
			y1 = r * sin(angle * PI / 180);
			mlx_put_pixel(data->img, x + x1, y + y1, data->color);
		}
	}
	printf("topdown_player done\n");
}
*/

/* ---------------- FROM MLX_BRESENHAM_LINE_ALGO ----------------
#include "stuff.h"
#define SIZE 1280

int32_t pixel_select(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void make_square(t_data *data)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < data->img->height)
	{
		x = 0;
		while (x < data->img->width)
		{
			mlx_put_pixel(data->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void coords_setup(t_data *data)
{
	data->x1 = rand() % SIZE;
	data->y1 = rand() % SIZE;
	data->x2 = rand() % SIZE;
	data->y2 = rand() % SIZE;
	data->color = pixel_select(
		rand() % 255,
		rand() % 255,
		rand() % 255,
		255
	);
}

void print_coords(t_data *data)
{
	printf("(%d, %d)\n(%d, %d)\n", data->x1, data->y1, data->x2, data->y2);
}

void draw_line(t_data *data)
{
	// print_coords(data);
	int dx = abs(data->x2 - data->x1); //distance x coords
	int dy = abs(data->y2 - data->y1); //distance y coords
	int sx = data->x1 < data->x2 ? 1 : -1; //slope x
	int sy = data->y1 < data->y2 ? 1 : -1; //slope y
	int err = dx - dy; //move vertical or horizontal
	int e2; //error correction * 2

	while (data->x1 != data->x2 && data->y1 != data->y2) {
		mlx_put_pixel(data->img, data->x1, data->y1, data->color);
		e2 = err * 2; //err * 2 at the start of next calculation
		if (e2 > -dy) {
			err -= dy;
			data->x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			data->y1 += sy;
		}
	}
}

void loop_hook_function(void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (data->go == true)
	{
		coords_setup(data);
		draw_line(data);
	}
}

void ft_on_key(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = (t_data *)param;

	//press once
	if (keydata.action == MLX_PRESS)
	{
		//close window, exit program
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(data->mlx);
			mlx_terminate(data->mlx);
			exit(0);
		}
		//put screen to black
		if (keydata.key == MLX_KEY_Q)
			make_square(data);
		//start generating lines
		if (keydata.key == MLX_KEY_W)
			data->go = true;
		//stop generating lines
		if (keydata.key == MLX_KEY_E)
			data->go = false;
	}
	if (keydata.action == MLX_REPEAT)
	{
		//manually keeping the generating going
		if (keydata.key == MLX_KEY_R)
		{
			coords_setup(data);
			draw_line(data);
		}
	}
}

int main(int argc, char **argv)
{
	t_data data;

	data.mlx = mlx_init(SIZE, SIZE, "drawing_the_pixels", false);
	data.img = mlx_new_image(data.mlx, SIZE, SIZE);
	data.go = false;
	mlx_loop_hook(data.mlx, loop_hook_function, &data);
	mlx_key_hook(data.mlx, &ft_on_key, &data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return 0;
}

*/