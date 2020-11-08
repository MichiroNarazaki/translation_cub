#include "main.h"

void ver_line(t_img *img, int x, t_start_end *y, int color)
{
	int y_cnt;
	int ceiling_color;
	int skyblue;

	skyblue = 0x001c2c52;
	ceiling_color = 0x000f2f0f;
	y_cnt = 0;
	while (y_cnt < y->start)
	{
		img->data[x + (y_cnt - 1) * WIDTH] = skyblue;
		y_cnt++;
	}
	while (y_cnt < y->end)
	{
		img->data[x + (y_cnt - 1) * WIDTH] = color;
		y_cnt++;
	}
	while (y_cnt < HEIGHT)
	{
		img->data[x + (y_cnt - 1) * WIDTH] = ceiling_color;
		y_cnt++;
	}
}
