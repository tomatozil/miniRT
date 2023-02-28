#include "minirt.h"

void	re_start(t_info *info)
{

}

int	key_press(int keycode, t_info *info)
{
//	if (keycode == 53)
//		exit(0);
//	if (keycode == 51)
//		re_start(info);
//	object_transformation(keycode, info);
//	camera_transformation(keycode, info);
//	light_transformation(keycode, info);
//	draw(info);
//	return (0);
}

int	red_button(int exitcode, t_info *info)
{
	//free?
	mlx_destroy_window(info->mlx, info->win);
	exit(exitcode);
}
