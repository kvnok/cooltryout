#include "../include/stuff.h"

void topdown_draw(t_data *data) {
	topdown_blocks(data);
	topdown_player(data);
	topdown_drawline(data);
}

void loop_hook_func(void *param) {
	t_data *data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)) {
		cleanup(data);
		exit(0);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) {
		data->player->y -= 0.05;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) {
		data->player->y += 0.05;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) {
		data->player->x -= 0.05;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) {
		data->player->x += 0.05;
	}
	// if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)) {

	// }
	// if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)) {

	// }
	topdown_draw(data);
}
