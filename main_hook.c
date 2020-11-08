#include "main.h"

/*
- w, hはウィンドウ幅, 高さとする。
- mapを[x][y] でなく [y][x] とする。
  - それに伴い描画時に左右反転してしまうので、カメラ平面ベクトルの値を修正する（反転させる）。
- main関数にコードが全て書かれているので、関数分割、変数を構造体にする。
*/

void main_hook(t_img *img)
{
	t_val val;
	int w = 50;
	int h = 50;
	double time = 0;	//time of current frame
	double oldTime = 0; //time of previous frame
	int x;
	double perpWallDist;
	int hit = 0; //was there a wall hit?
	int side;	 //was a NS or a EW wall hit?
	double cameraX;
	int lineHeight;
	int color;
	t_start_end y;

	val.dir.x = -1; //initial direction vector
	val.dir.y = 0;
	val.pos.x = 22; //x and y start position
	val.pos.y = 12;
	val.plane.x = 0; //the 2d raycaster version of camera plane
	val.plane.y = 0.66;

	// while (!done())
	// {
	for (x = 0; x < w; x++)
	{
		//線の位置と方向の計算
		cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		val.ray_dir.x = val.dir.x + val.plane.x * cameraX;
		val.ray_dir.y = val.dir.y + val.plane.y * cameraX;
		//which box of the map we're in
		val.map.x = (int)(val.pos.x);
		val.map.y = (int)(val.pos.y);

		//ＸＹ側から次のＸＹ側までの長さ
		val.delta_dist.x = (val.ray_dir.y == 0) ? 0 : ((val.ray_dir.x == 0) ? 1 : fabs(1 / val.ray_dir.x));
		val.delta_dist.y = (val.ray_dir.x == 0) ? 0 : ((val.ray_dir.y == 0) ? 1 : fabs(1 / val.ray_dir.y));

		//calculate step and initial sideDist
		cal_and_init(&val);
		//perform DDA
		dda(&val, &side, &hit);
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (val.map.x - val.pos.x + (1 - val.step.x) / 2) / val.ray_dir.x;
		else
			perpWallDist = (val.map.y - val.pos.y + (1 - val.step.y) / 2) / val.ray_dir.y;

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
		color = ret_color(&val);
		//give x and y sides different brightness
		if (side == 1)
		{
			color = color / 2;
		}
		// }

		//move forward if no wall in front of you
		ver_line(img,x,&y,color);
	}
	// deal_key(key_code, &val);
}