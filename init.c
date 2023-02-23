#include "minirt.h"

t_info	*scene_init(void)
{
	t_info		*scene;
	t_object	*objects;
	t_object	*lights;
	double		amb_strength;

	if (!(scene = malloc(sizeof(t_info))))
		return (NULL);
	scene->canvas = canvas_set(960, 540);
	scene->cam = cam_set(scene->canvas, point3(1, 0, 10));

	objects = object(SPHERE, sphere(point3(0, 0, -5), 0.5), color3(0.5, 0, 0));
	obj_add(&objects, object(SPHERE, sphere(point3(0, 0, -20), 10), color3(0, 0.5, 0)));
	obj_add(&objects, object(SPHERE, sphere(point3(-2, 4, -11), 2), color3(0, 0.6, 0)));
	scene->objects = objects;

	lights = object(POINT_LIGHT, light(point3(0, 0, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->lights = lights;

	amb_strength = 0.1;

	scene->ambient = mult_t(color3(1, 1, 1), amb_strength);
	return (scene);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.t_min = EPSILON;
	record.t_max = 21474836;
	return (record);
}