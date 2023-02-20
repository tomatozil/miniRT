#include "minirt.h"

t_object	*object(t_obj_type type, void *element)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
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