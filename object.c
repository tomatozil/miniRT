#include "minirt.h"

t_sphere	sphere_set(t_point3 center, double radius)
{
	t_sphere	new;

	new.center = center;
	new.radius = radius;
	new.radius_d = radius * radius;
	return (new);
}