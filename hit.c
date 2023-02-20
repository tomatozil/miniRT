#include "minirt.h"

double	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vec3	ray_to_center;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	/* 근의 공식 판별식
	 (O + tD - C)(O + tD - C) = r*r
	 t*t*D∙D + 2*t*D∙(O - C) + (O - C)∙(O - C) - r*r = 0
	 a*t*t + b*t + c = 0
	 a = D∙D, b = 2D∙(O - C), c = (O - C)∙(O - C) - r*r
	 discriminant = b*b - 4*a*c

	ray_to_center = vec3_minus(ray.origin, sphere.center);
	a = vec3_dot(ray.dir, ray.dir);
	b = 2.0 * vec3_dot(ray.dir, ray_to_center);
	c = vec3_dot(ray_to_center, ray_to_center) - sphere.radius_d;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0) // 표면에 스칠 때(dis == 0)는 왜 고려 x?
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
	 */

	ray_to_center = vec3_minus(ray.origin, sphere.center);
	// 짝수 근의 공식 판별식
	a = pow(vec3_len(ray.dir), 2);
	b = vec3_dot(ray.dir, ray_to_center);
	c = pow(vec3_len(ray_to_center), 2) - sphere.radius_d;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return ()
}