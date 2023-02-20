#include "minirt.h"

t_ray	ray(t_point3 point, t_vec3 vec)
{
	t_ray new;

	new.origin = point;
	new.dir = vec3_unit(vec);
	return (new);
}

t_point3	ray_dest(t_ray ray, double t)
{
	t_point3	dest;

	dest = vec3_plus(ray.origin, vec3_mult(ray.dir, t));
	return (dest);
}

t_ray	ray_primary(t_cam cam, double horiz, double verti)
{
	t_ray ray_p;

	ray_p.origin = cam.origin;
	ray_p.dir = vec3_plus(cam.left_bottom, vec3_mult(cam.dir_horizontal, horiz));
	ray_p.dir = vec3_plus(ray_p.dir, vec3_mult(cam.dir_vertical, verti));
	ray_p.dir = vec3_minus(ray_p.dir, ray_p.origin);
	ray_p.dir = vec3_unit(ray_p.dir);
	return (ray_p);
}

t_color3	ray_color(t_ray ray, t_sphere sphere)
{
	double	t;

	t = hit_sphere(sphere, ray);
	if (t > 0.0)
	{
		t_vec3 n = vec3_unit(vec3_minus(ray_dest(ray, t), sphere.center));
		return (vec3_devide(color3(n.x + 1, n.y + 1, n.z + 1), 2.0));
		// -1 < n.y < 1
		// 0 < n.y + 1 < 2
		// 0 < (n.y + 1) / 2 < 1
	}
	t = 0.5 * (ray.dir.y + 1.0); // 0.0 < (y + 1.0) / 2 < 1.0 (y좌표를 기준으로 그라데이션 주기 -> 범위 정하기)
	return (vec3_plus(vec3_mult(color3(1.0, 1.0, 1.0), 1.0 - t), vec3_mult(color3(0.5, 0.7, 1.0), t)));
}