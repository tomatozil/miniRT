#ifndef HIT_H
#define HIT_H

# include "minirt.h"

int	hit(t_object *object, t_ray ray, t_hit_record *rec);
int	hit_sphere(t_object *object, t_ray ray, t_hit_record *rec);

#endif
