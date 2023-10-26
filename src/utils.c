#include "../include/stuff.h"

int32_t pixel_select(int32_t r, int32_t g, int32_t b, int32_t a) {
	return (r << 24 | g << 16 | b << 8 | a);
}

void print_map(char **map) {
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map_height) {
		x = 0;
		while (x < map_width) {
			printf("|%c|", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
