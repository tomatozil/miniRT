#ifndef HIT_H
#define HIT_H

# include "structures.h"

void	set_face_normal(t_ray ray, t_hit_record *rec);
void	get_discriminant_sp(t_discriminant *d, t_sphere *sp, t_ray ray);
void	get_discriminant_cy(t_discriminant *d, t_cylinder *cy, t_ray ray);

int		hit(t_object *objects, t_ray ray, t_hit_record *rec);
int		hit_sphere(t_object *object, t_ray ray, t_hit_record *rec);
int 	hit_plane(t_object *object, t_ray ray, t_hit_record *rec);
int		hit_cylinder(t_object *object, t_ray ray, t_hit_record *rec);

#endif
