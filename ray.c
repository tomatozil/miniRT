#include "minirt.h"

t_ray	ray_set(t_point3 point, t_vec3 vec)
{
	t_ray new;

	new.origin = point;
	new.dir = unit(vec);
	return (new);
}

t_point3	ray_dest(t_ray ray, double t)
{
	t_point3	dest;

	dest = plus(ray.origin, mult_t(ray.dir, t));
	return (dest);
}

t_ray	ray_primary(t_cam cam, double half_w, double half_h)
{
	t_ray ray;

	ray.origin = cam.origin;
	ray.dir = plus(cam.left_bottom, mult_t(cam.dir_horiz, half_w));
	ray.dir = plus(ray.dir, mult_t(cam.dir_verti, half_h));
	ray.dir = minus(ray.dir, ray.origin);
	ray.dir = unit(ray.dir);
	return (ray);
}

//t_vec3	random_in_unit_sphere(void)
//{
//}

t_color3 ray_color(t_ray ray, t_info *info)
{
	double	t;

	info->rec.t_min = EPSILON;
	info->rec.t_max = INFINITY;
	if (hit(info->objects, ray, &info->rec))
		return (lighting_set(info));
//		return (mult_t(plus(info->rec.normal_v, color3(1.0, 1.0, 1.0)), 0.5));
//		return (devide_t(color3(info->rec.normal_v.x + 1, info->rec.normal_v.y + 1, info->rec.normal_v.z + 1), 2.0));
	// -1 < n.y < 1
	// 0 < n.y + 1 < 2
	// 0 < (n.y + 1) / 2 < 1
	t = 0.5 * (ray.dir.y + 1.0); // 0.0 < (y + 1.0) / 2 < 1.0 (y좌표를 기준으로 그라데이션 주기 -> 범위 정하기)
	return (plus(mult_t(color3(1.0, 1.0, 1.0), 1.0 - t), mult_t(color3(0.5, 0.7, 1.0), t)));
}