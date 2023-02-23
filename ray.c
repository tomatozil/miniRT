#include "minirt.h"

t_ray	ray_set(t_point3 point, t_vec3 vec)
{
	t_ray new;

	new.origin = point;
	new.dir_v = unit(vec);
	return (new);
}

t_point3	ray_dest(t_ray ray, double t)
{
	t_point3	dest;

	dest = plus(ray.origin, mult_t(ray.dir_v, t));
	return (dest);
}

t_ray	ray_primary(t_cam cam, double horiz, double verti)
{
	t_ray ray_p;

	ray_p.origin = cam.origin;
	ray_p.dir_v = plus(cam.left_bottom, mult_t(cam.dir_horizontal, horiz));
	ray_p.dir_v = plus(ray_p.dir_v, mult_t(cam.dir_vertical, verti));
	ray_p.dir_v = minus(ray_p.dir_v, ray_p.origin);
	ray_p.dir_v = unit(ray_p.dir_v);
	return (ray_p);
}

//t_vec3	random_in_unit_sphere(void)
//{
//}

t_color3 ray_color(t_ray ray, t_info *scene, int depth)
{
	double	t;

	scene->rec = record_init();
	if (depth <= 0)
		return (color3(0, 0, 0));
	if (hit(scene->objects, ray, &scene->rec))
	{
//		t_point3 target = plus(scene->rec.hit_point, scene->rec.normal_v);
//		target = plus(target, random_in_unit_sphere());
//		ray_color(ray_set(scene->rec.hit_point, minus(target, scene->rec.hit_point)),scene, depth - 1);
//		return (mult_t(lighting_set(objects), 0.5));
		return (lighting_set(scene));
	}
//		return (mult_t(plus(scene->rec.normal_v, color3(1.0, 1.0, 1.0)), 0.5));
//		return (devide_t(color3(scene->rec.normal_v.x + 1, scene->rec.normal_v.y + 1, scene->rec.normal_v.z + 1), 2.0));
	// -1 < n.y < 1
	// 0 < n.y + 1 < 2
	// 0 < (n.y + 1) / 2 < 1
	t = 0.5 * (ray.dir_v.y + 1.0); // 0.0 < (y + 1.0) / 2 < 1.0 (y좌표를 기준으로 그라데이션 주기 -> 범위 정하기)
	return (plus(mult_t(color3(1.0, 1.0, 1.0), 1.0 - t), mult_t(color3(0.5, 0.7, 1.0), t)));
}