#include "main.h"

void cal_and_init(t_val *val)
{
	if (val->ray_dir.x < 0)
	{
		val->step.x = -1;
		val->side_dist.x = (val->pos.x - val->map.x) * val->delta_dist.x;
	}
	else
	{
		val->step.x = 1;
		val->side_dist.x = (val->map.x + 1.0 - val->pos.x) * val->delta_dist.x;
	}
	if (val->ray_dir.y < 0)
	{
		val->step.y = -1;
		val->side_dist.y = (val->pos.y - val->map.y) * val->delta_dist.y;
	}
	else
	{
		val->step.y = 1;
		val->side_dist.y = (val->map.y + 1.0 - val->pos.y) * val->delta_dist.y;
	}
}