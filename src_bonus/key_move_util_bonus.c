#include "minirt_bonus.h"

void	key_move(void *clicked, int type, t_vec3 dir, int keycode)
{
    if (type == PLANE)
        move_plane((t_plane *)((t_object *)clicked)->element, dir, keycode);
    if (type == SPHERE)
        move_sphere((t_sphere *)((t_object *)clicked)->element, dir, keycode);
    if (type == CYLINDER)
        move_cylinder((t_cylinder *)((t_object *)clicked)->element, dir, keycode);
    if (type == LIGHT)
        move_light((t_light *)clicked, dir, keycode);
    if (type == CAMERA)
        move_camera((t_cam *)clicked, keycode);
}

int is_move_key(int keycode)
{
    if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
		keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
        return (TRUE);
    return (FALSE);
}


void	move_obj(t_point3 *point, t_vec3 dir)
{
    *point = plus(*point, dir);
}
