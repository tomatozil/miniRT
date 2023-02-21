#include "minirt.h"

t_object *object(t_obj_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*new;

	if (!(new = malloc(sizeof(t_sphere))))
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->radius_d = radius * radius;
	return (new);
}

t_light	*light(t_point3 light_origin, t_color3 light_amount, double bright_ratio)
{
	t_light	*new;

	if (!(new = malloc(sizeof(t_light))))
		return (NULL);
	new->origin = light_origin;
	new->amount = light_amount;
	new->bright_ratio = bright_ratio;
	return (new);
}