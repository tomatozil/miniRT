#include "minirt.h"

int	hit_object(t_object *object, t_ray ray, t_hit_record *rec)
{
	int hit_result;

	hit_result = FALSE;
	if (object->type == SPHERE)
		hit_result = hit_sphere(object, ray, rec);
	if (object->type == PLANE)
		hit_result = hit_plane(object, ray, rec);
//	if (object->type == CYLINDER)
//		hit_result = hit_cylinder(object, ray, rec);
	return (hit_result);
}

int	hit(t_object *objects, t_ray ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = FALSE;
	while (objects)
	{
		if (hit_object(objects, ray, rec) != FALSE)
		{
			hit_result = TRUE;
			rec->t_max = rec->t;
		}
		objects = objects->next;
	}
	return (hit_result);
}

void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = dot(ray.dir, rec->normal_v);
	if (rec->front_face > 0)
		rec->normal_v = mult_t(rec->normal_v, -1.0);
}

int hit_plane(t_object *object, t_ray ray, t_hit_record *rec)
{
	t_plane	*plane;
	double	numerator;
	double	denominator;
	double 	root;
	/* 내적 x 광선의 방정식 = 판별식
	 (P - P0)∙N = 0
	 (O + tD - P0)∙N = 0;
	 ~
	 t = (P0 - O)∙N / (D∙N)
	 */
	plane = (t_plane *)object->element;
	denominator = dot(ray.dir, plane->dir);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numerator = dot(minus(plane->center, ray.origin), plane->dir);
	root = numerator / denominator;
	if (root < rec->t_min || rec->t_max < root)
		return (FALSE);
	rec->t = root;
	rec->hit_point = ray_dest(ray, root);
	rec->normal_v = plane->dir; // 평면의 방향이 곧 법선벡터
	rec->rgb = plane->rgb;
	// 광선과 평면이 평행인 상태에서 겹치면?(해가 무한대로 나오면?)
	set_face_normal(ray, rec);
	return (TRUE);
}

//int	hit_plane(t_object *object, t_ray ray, t_hit_record *rec)
//{
//	t_plane *plane;
//	double	numerator;
//	double	denominator;
//	double	sol;
//
//	plane = (t_plane *)object->element;
//	denominator = dot(ray.dir, plane->dir);
//	if (fabs(denominator) < EPSILON)
//		return (FALSE);
//	numerator = dot(minus(plane->center, ray.origin), plane->dir);
//	sol = numerator / denominator;
//	if (sol < rec->t_min || rec->t_max < sol)
//		return (FALSE);
////	rec->t_max = sol;
//	rec->t = sol;
//	rec->hit_point = ray_dest(ray, sol);
//	rec->normal_v = plane->dir;
//	rec->rgb = plane->rgb;
//	set_face_normal(ray, rec);
//	return (TRUE);
//}

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
	/* 구의 방정식 x 광선의 방정식 = 판별식 (근의 공식을 활용)
	 (O + tD - C)(O + tD - C) = r*r
	 t*t*D∙D + 2*t*D∙(O - C) + (O - C)∙(O - C) - r*r = 0
	 a*t*t + b*t + c = 0
	 a = D∙D, b = 2D∙(O - C), c = (O - C)∙(O - C) - r*r
	 discriminant = b*b - 4*a*c

	ray_to_center = minus(ray.origin, sphere.center);
	a = vec3_dot(ray.dir, ray.dir);
	b = 2.0 * vec3_dot(ray_set.dir, ray_to_center);
	c = dot(ray_to_center, ray_to_center) - sphere.radius_d;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0) // 표면에 스칠 때(dis == 0)는 왜 고려 x?
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
	 */

	sphere = (t_sphere *)object->element;
	ray_to_center = minus(ray.origin, sphere->center);
	// 짝수 근의 공식 판별식
	a = pow(vlen(ray.dir), 2);
	b = dot(ray.dir, ray_to_center);
	c = pow(vlen(ray_to_center), 2) - sphere->radius_d;
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
	rec->normal_v = devide_t(minus(rec->hit_point, sphere->center), sphere->radius);
	rec->rgb = sphere->rgb;
	set_face_normal(ray, rec);
	return (TRUE);
}