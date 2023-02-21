#include "minirt.h"

t_color3	get_diffuse(t_scene *scene)

t_color3	get_light_amount(t_scene *scene, t_light *lights)
{

}

t_color3	lighting_set(t_scene *scene)
{
	t_color3	light_amount;
	t_object	*lights;

	light_amount = color3(0, 0, 0);
	lights = scene->lights;
	while (lights)
	{
		if (lights->type == POINT_LIGHT)
			light_amount = vec3_plus(light_amount, get_light_amount(scene, lights->element));
		lights = lights->next;
	}
	light_amount = vec3_plus(light_amount, scene->ambient);
	light_amount = color3(light_amount.x * scene->rec.albedo.x, \
	light_amount.y * scene->rec.albedo.y, \
	light_amount.z * scene->rec.albedo.z);
	if (light_amount.x > 1.0 && light_amount.y > 1.0 && light_amount.z > 1.0)
		return (color3(1, 1, 1));
	return (light_amount);
}
