#include "minirt.h"

void	rotate_camera(t_cam *cam, int keycode)
{
    if (keycode == KEY_UP)
        rotate_obj(&cam->dir, (t_vec3){-ROTATION, 0, 0});
    if (keycode == KEY_DOWN)
        rotate_obj(&cam->dir, (t_vec3){ROTATION, 0, 0});
    if (keycode == KEY_LEFT)
        rotate_obj(&cam->dir, (t_vec3){0, -ROTATION, 0});
    if (keycode == KEY_RIGHT)
        rotate_obj(&cam->dir, (t_vec3){0, ROTATION, 0});
	//-----카메라에서는 없어도 될듯?-----
	if (keycode == 43)
		rotate_obj(&cam->dir, (t_vec3){0, 0, -ROTATION});
	if (keycode == 47)
		rotate_obj(&cam->dir, (t_vec3){0, 0, ROTATION});
	//----------------------------
}

void	rotate_plane(t_plane *plane, int keycode)
{
    if (keycode == KEY_LEFT)
        rotate_obj(&plane->dir, (t_vec3){0, 0, ROTATION});
    if (keycode == KEY_RIGHT)
        rotate_obj(&plane->dir, (t_vec3){0, 0, -ROTATION});
    if (keycode == KEY_UP)
        rotate_obj(&plane->dir, (t_vec3){-ROTATION, 0, 0});
    if (keycode == KEY_DOWN)
        rotate_obj(&plane->dir, (t_vec3){ROTATION, 0, 0});
	if (keycode == 43)
		rotate_obj(&plane->dir, (t_vec3){0, 0, -ROTATION});
	if (keycode == 47)
		rotate_obj(&plane->dir, (t_vec3){0, 0, ROTATION});
}

void	rotate_cylinder(t_cylinder *cylinder, int keycode)
{
    if (keycode == KEY_UP)
        rotate_obj(&cylinder->dir, (t_vec3){0, 0, ROTATION});
    if (keycode == KEY_DOWN)
        rotate_obj(&cylinder->dir, (t_vec3){0, 0, -ROTATION});
    if (keycode == KEY_LEFT)
        rotate_obj(&cylinder->dir, (t_vec3){-ROTATION, 0, 0});
    if (keycode == KEY_RIGHT)
        rotate_obj(&cylinder->dir, (t_vec3){ROTATION, 0, 0});
	if (keycode == 43)
		rotate_obj(&cylinder->dir, (t_vec3){0, 0, -ROTATION});
	if (keycode == 47)
		rotate_obj(&cylinder->dir, (t_vec3){0, 0, ROTATION});
}
