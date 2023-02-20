#ifndef OBJECT_H
#define OBJECT_H

# include "minirt.h"

t_object	*object(t_obj_type type, void *element);
t_sphere	*sphere(t_point3 center, double radius);

#endif
