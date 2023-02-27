#include "minirt.h"

void	scene_init(t_info *info)
{
	t_object	*objects;
	t_light		light;

	objects = object(SPHERE, sphere(point3(2, 0, -5), color3(0, 0, 0.5), 2));
	obj_add(&objects, object(SPHERE, sphere(point3(-3, 0, -20), color3(0, 0.5, 0), 10)));
	obj_add(&objects, object(PLANE, plane(point3(0, -3, 0), vec3(-0.4, -1, 0), color3(1, 1, 0))));
	obj_add(&objects, object(PLANE, plane(point3(0, -8, 0), vec3(0.3, -1, 0), color3(0, 1, 0))));
	obj_add(&objects, object(CYLINDER, cylinder(point3(1, 3, -5), unit(vec3(-0.4, -1, 1)), color3(1, 0.5, 0), 1, 5)));
//	obj_add(&objects, object(SPHERE, sphere(point3(1, 1, -2), color3(0.3, 0.5, 0), 3)));
	obj_add(&objects, object(SPHERE, sphere(point3(3, 3, -5), color3(0, 0.5, 0), 1)));
	info->objects = objects;

	light = light_set(point3(0, 10, 0), color3(1, 1, 1), 0.5);
	info->light = light;

	info->ambient.ratio = 0.3;

	info->ambient.amount = mult_t(color3(1, 1, 1), info->ambient.ratio);
}
