#include "main.h"

int deal_key(int key_code, t_game *game)
{
	double old_dirX;
	double old_planeX;

	// printf("x : %lf , ", game->val.pos.x);
	// printf("y : %lf\n", game->val.pos.y);
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
	{
		printf("w\n");
		if (map_value((int)(game->val.pos.y), (int)(game->val.pos.x + game->val.dir.x * game->val.move_speed)) == 0)
			game->val.pos.x += game->val.dir.x * game->val.move_speed;
		if (map_value((int)(game->val.pos.y + game->val.dir.y * game->val.move_speed), (int)(game->val.pos.x)) == 0)
			game->val.pos.y += game->val.dir.y * game->val.move_speed;
	}
	else if (key_code == KEY_S)
	{
		printf("s\n");
		if (map_value((int)(game->val.pos.y), (int)(game->val.pos.x - game->val.dir.x * game->val.move_speed)) == 0)
			game->val.pos.x -= game->val.dir.x * game->val.move_speed;
		if (map_value((int)(game->val.pos.y - game->val.dir.y * game->val.move_speed), (int)(game->val.pos.x)) == 0)
			game->val.pos.y -= game->val.dir.y * game->val.move_speed;
	}
	else if (key_code == KEY_A)
	{
		printf("a\n");
		//both camera direction and camera plane must be rotated
		old_dirX = game->val.dir.x;
		game->val.dir.x = game->val.dir.x * cos(-game->val.rot_speed) - game->val.dir.y * sin(-game->val.rot_speed);
		game->val.dir.y = old_dirX * sin(-game->val.rot_speed) + game->val.dir.y * cos(-game->val.rot_speed);
		old_planeX = game->val.plane.x;
		game->val.plane.x = game->val.plane.x * cos(-game->val.rot_speed) - game->val.plane.y * sin(-game->val.rot_speed);
		game->val.plane.y = old_planeX * sin(-game->val.rot_speed) + game->val.plane.y * cos(-game->val.rot_speed);
	}
	else if (key_code == KEY_D)
	{
		printf("d\n");
		//both camera direction and camera plane must be rotated
		old_dirX = game->val.dir.x;
		game->val.dir.x = game->val.dir.x * cos(game->val.rot_speed) - game->val.dir.y * sin(game->val.rot_speed);
		game->val.dir.y = old_dirX * sin(game->val.rot_speed) + game->val.dir.y * cos(game->val.rot_speed);
		old_planeX = game->val.plane.x;
		game->val.plane.x = game->val.plane.x * cos(game->val.rot_speed) - game->val.plane.y * sin(game->val.rot_speed);
		game->val.plane.y = old_planeX * sin(game->val.rot_speed) + game->val.plane.y * cos(game->val.rot_speed);
	}
	g_key_1();
	// printf("x : %lf , ", game->val.pos.x);
	// printf("y : %lf\n", game->val.pos.y);
	return (0);
}