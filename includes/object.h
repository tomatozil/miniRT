#ifndef OBJECT_H
#define OBJECT_H

# include "minirt.h"

t_object	*object(t_obj_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_light		*light(t_point3 light_origin, t_color3 light_amount, double bright_ratio);

#endif
