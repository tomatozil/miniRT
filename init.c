#include "minirt.h"

t_info	*scene_init(void)
{
	t_info		*info;
	t_object	*objects;
	t_light		light;

	if (!(info = malloc(sizeof(t_info))))
		return (NULL);
	info->canvas = canvas_set(960, 540);
	info->cam = cam_set(info->canvas, point3(1, 0, 10));

	objects = object(SPHERE, sphere(point3(2, 0, -5), 0.5), color3(0.5, 0, 0));
	obj_add(&objects, object(SPHERE, sphere(point3(-3, 0, -20), 10), color3(0, 0.5, 0)));
	obj_add(&objects, object(SPHERE, sphere(point3(-2, 4, -11), 2), color3(0, 0.6, 0)));
	info->objects = objects;

	light = light_set(point3(0, 0, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0);
	info->light = light;

	info->ambient.ratio = 0.1;

	info->ambient.amount = mult_t(color3(1, 1, 1), info->ambient.ratio);
	return (info);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.t_min = EPSILON;
	record.t_max = 21474836;
	return (record);
}