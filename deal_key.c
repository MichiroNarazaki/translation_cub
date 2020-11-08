#include"main.h"

int deal_key(int key_code, t_val *val)
{
	
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
	{
		if (map_value((int)(val->pos.x + val->dir.x * val->move_speed) ,(int)(val->pos.y)) == false)
			val->pos.x += val->dir.x * val->move_speed;
		if (map_value((int)(val->pos.x),(int)(val->pos.y + val->dir.y * val->move_speed)) == false)
			val->pos.y += val->dir.y * val->move_speed;
	}
	else if (key_code == KEY_S)
	{
		if (map_value((int)(val->pos.x - val->dir.x * val->move_speed),(int)(val->pos.y)) == false)
			val->pos.x -= val->dir.x * val->move_speed;
		if (map_value((int)(val->pos.x),(int)(val->pos.y - val->dir.y * val->move_speed)) == false)
			val->pos.y -= val->dir.y * val->move_speed;
	}
	else if (key_code == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		double old_DirX = val->dir.x;
		val->dir.x = val->dir.x * cos(-val->rot_speed) - val->dir.y * sin(-val->rot_speed);
		val->dir.y = old_DirX * sin(-val->rot_speed) + val->dir.y * cos(-val->rot_speed);
		double oldPlaneX = val->plane.x;
		val->plane.x = val->plane.x * cos(-val->rot_speed) - val->plane.y * sin(-val->rot_speed);
		val->plane.y = oldPlaneX * sin(-val->rot_speed) + val->plane.y * cos(-val->rot_speed);
	}
	else if (key_code == KEY_D)
	{

		//both camera direction and camera plane must be rotated
		double old_DirX = val->dir.x;
		val->dir.x = val->dir.x * cos(val->rot_speed) - val->dir.y * sin(val->rot_speed);
		val->dir.y = old_DirX * sin(val->rot_speed) + val->dir.y * cos(val->rot_speed);
		double oldPlaneX = val->plane.x;
		val->plane.x = val->plane.x * cos(val->rot_speed) - val->plane.y * sin(val->rot_speed);
		val->plane.y = oldPlaneX * sin(val->rot_speed) + val->plane.y * cos(val->rot_speed);
	}
	return (0);
}