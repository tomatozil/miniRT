#ifndef RAY_H
#define RAY_H

# include "minirt.h"

t_ray	ray(t_point3 point, t_vec3 vec);
t_point3	ray_dest(t_ray ray, double t);
t_ray	ray_primary(t_cam cam, double horiz, double verti);
t_color3 ray_color(t_scene *scene, int depth);

#endif
