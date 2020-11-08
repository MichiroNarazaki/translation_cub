#include "main.h"

void dda(t_val *val,int *side,int *hit)
{
	while (*hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (val->side_dist.x < val->side_dist.y)
		{
			val->side_dist.x += val->delta_dist.x;
			val->map.x += val->step.x;
			*side = 0;
		}
		else
		{
			val->side_dist.y += val->delta_dist.y;
			val->map.y += val->step.y;
			*side = 1;
		}
		//Check if ray has hit a wall
		if (map_value(val->map.x,val->map.y) > 0)
			*hit = 1;
	}
}