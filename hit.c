#include "minirt.h"

int	hit_object(t_object *object, t_ray ray, t_hit_record *rec)
{
	int hit_result;

	hit_result = FALSE;
	if (object->type == SPHERE)
		hit_result = hit_sphere(object, ray, rec);
	return (hit_result);
}

int	hit(t_object *object, t_ray ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = FALSE;
	while (object)
	{
		if (hit_object(object, ray, rec) != FALSE)
		{
			hit_result = TRUE;
			rec->t_max = rec->t;
		}
		object = object->next;
	}
	return (hit_result);
}

void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vec3_dot(ray.dir_v, rec->normal_v);
	if (rec->front_face > 0)
		rec->normal_v = vec3_mult_t(rec->normal_v, -1.0);
}

int	hit_sphere(t_object *object, t_ray ray, t_hit_record *rec)
{
	t_vec3	ray_to_center;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrt_d;
	double	root;
	t_sphere	*sphere;
	/* 근의 공식 판별식
	 (O + tD - C)(O + tD - C) = r*r
	 t*t*D∙D + 2*t*D∙(O - C) + (O - C)∙(O - C) - r*r = 0
	 a*t*t + b*t + c = 0
	 a = D∙D, b = 2D∙(O - C), c = (O - C)∙(O - C) - r*r
	 discriminant = b*b - 4*a*c

	ray_to_center = vec3_minus(ray.origin, sphere.center);
	a = vec3_dot(ray.dir_v, ray.dir_v);
	b = 2.0 * vec3_dot(ray.dir_v, ray_to_center);
	c = vec3_dot(ray_to_center, ray_to_center) - sphere.radius_d;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0) // 표면에 스칠 때(dis == 0)는 왜 고려 x?
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
	 */

	sphere = (t_sphere *)object->element;
	ray_to_center = vec3_minus(ray.origin, sphere->center);
	// 짝수 근의 공식 판별식
	a = pow(vec3_len(ray.dir_v), 2);
	b = vec3_dot(ray.dir_v, ray_to_center);
	c = pow(vec3_len(ray_to_center), 2) - sphere->radius_d;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrt_d = sqrt(discriminant);
	root = (-b - sqrt_d) / a;
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (-b + sqrt_d) / a;
		if (root < rec->t_min || rec->t_max < root)
			return (FALSE);
	}
	rec->t = root;
	rec->hit_point = ray_dest(ray, root);
	rec->normal_v = vec3_devide_t(vec3_minus(rec->hit_point, sphere->center), sphere->radius);
	rec->albedo = object->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}