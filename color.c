#include "main.h"

int ret_color(t_val *val)
{
		if (map_value(val->map.x, val->map.y) == 1)
			return RED;
		else if (map_value(val->map.x, val->map.y) == 2)
			return GREEN;
		else if (map_value(val->map.x, val->map.y) == 3)
			return BLUE;
		else if (map_value(val->map.x, val->map.y) == 4)
			return WHITE;
		else
			return YELLOW;
}