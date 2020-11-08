#include "main.h"

/*
- w, hはウィンドウ幅, 高さとする。
- mapを[x][y] でなく [y][x] とする。
  - それに伴い描画時に左右反転してしまうので、カメラ平面ベクトルの値を修正する（反転させる）。
- main関数にコードが全て書かれているので、関数分割、変数を構造体にする。
*/

void main_hook_init(t_game *game)
{

	game->val.dir.x = -1; //initial direction vector
	game->val.dir.y = 0;
	game->val.pos.x = 12; //x and y start position
	game->val.pos.y = 10;
	game->val.plane.x = 0.1; //the 2d raycaster version of camera plane
	game->val.plane.y = 0.66;
}

void main_hook(t_game *game)
{
	int w = WIDTH;
	int h = HEIGHT;
	int x;
	double perpWallDist;
	int hit;  //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	double cameraX;
	double frameTime;
	int lineHeight;
	int color;
	t_start_end y;

	// while (!done())
	// {
	for (x = 0; x < w; x++)
	{
		//線の位置と方向の計算
		cameraX = -(2 * x / (double)w - 1); //x-coordinate in camera space
		game->val.ray_dir.x = game->val.dir.x + game->val.plane.x * cameraX;
		game->val.ray_dir.y = game->val.dir.y + game->val.plane.y * cameraX;
		//which box of the map we're in
		game->val.map.x = (int)(game->val.pos.x);
		game->val.map.y = (int)(game->val.pos.y);

		//ＸＹ側から次のＸＹ側までの長さ
		game->val.delta_dist.x = (game->val.ray_dir.y == 0) ? 0 : ((game->val.ray_dir.x == 0) ? 1 : fabs(1 / game->val.ray_dir.x));
		game->val.delta_dist.y = (game->val.ray_dir.x == 0) ? 0 : ((game->val.ray_dir.y == 0) ? 1 : fabs(1 / game->val.ray_dir.y));
		hit = 0;
		//calculate step and initial sideDist
		cal_and_init(&game->val);
		//perform DDA
		dda(&game->val, &side, &hit);
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (game->val.map.x - game->val.pos.x + (1 - game->val.step.x) / 2) / game->val.ray_dir.x;
		else
			perpWallDist = (game->val.map.y - game->val.pos.y + (1 - game->val.step.y) / 2) / game->val.ray_dir.y;

		/***************************************************************/
		//Calculate height of line to draw on screen
		lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		y.start = -lineHeight / 2 + h / 2;
		if (y.start < 0)
			y.start = 0;
		y.end = lineHeight / 2 + h / 2;
		if (y.end >= h)
			y.end = h - 1;
		//choose wall color
		color = ret_color(&game->val);
		//give x and y sides different brightness
		if (side == 1)
		{
			color = color / 2;
		}
		// }

		//move forward if no wall in front of you
		ver_line(&(game->img), x, &y, color);
	}
	printf("-----------------------------------\n");
	printf("| (x ,y) : ( %lf , %lf ) |\n",game->val.pos.x,game->val.pos.y);
	printf("-----------------------------------\n");
	// //timing for input and FPS counter
	// oldTime = time;
	// time = getTicks();
	// double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
	// print(1.0 / frameTime); //FPS counter
	// redraw();
	// cls();

	frameTime = 0.1;
	//speed modifiers
	game->val.move_speed = frameTime * 5.0; //the constant value is in squares/second
	game->val.rot_speed = frameTime * 3.0;	//the constant value is in radians/second
											// readKeys();
											// printf("%d\n", x);
											// deal_key(key_code, &game->val);
}