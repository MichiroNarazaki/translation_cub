#include "main.h"

void ver_line(t_img *img, int x, t_start_end *y, int color)
{
	int y_cnt;

	y_cnt = y->start;
	while (y_cnt < y->end)
	{
		img->data[x + (y_cnt - 1) * WIDTH] = color;
		y_cnt++;
	}
}
