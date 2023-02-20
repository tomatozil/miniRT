#ifndef VECTOR_H
#define VECTOR_H

# include "minirt.h"

t_point3	point3(double x, double y, double z);
t_vec3	vec3(double x, double y, double z);
t_color3	color3(double x, double y, double z);

void	vec3_set(t_vec3 *vec, double x, double y, double z);
double	vec3_len(t_vec3 vec);
t_vec3	vec3_plus(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_minus(t_vec3 vec1, t_vec3 vec2);
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_unit(t_vec3 vec);
t_vec3	vec3_mult(t_vec3 vec, double t);
t_vec3	vec3_devide(t_vec3 vec, double t);

#endif
