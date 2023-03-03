#include "minirt_bonus.h"

int	in_shadow(t_object *objects, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.t_min = 0;
	rec.t_max = light_len;
	if (hit(objects, light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

int	check_in_shadow(t_info *info, t_light light, t_phong_light *pl)
{
	double	light_len;
	t_ray	r_light_ray;

	pl->l_dir = minus(light.origin, info->rec.hit_point);
	light_len = vlen(pl->l_dir);
	r_light_ray = ray_set(plus(info->rec.hit_point, \
	mult_t(info->rec.normal, EPSILON)), unit(pl->l_dir));
	if (in_shadow(info->objects, r_light_ray, light_len))
		return (TRUE);
	return (FALSE);
}

t_color3	get_light_amount(t_info *info, t_light light)
{
	t_phong_light	pl;
	t_vec3			project;
	double			brightness;

	if (check_in_shadow(info, light, &pl))
		return (color3(0, 0, 0));
	pl.l_dir = unit(pl.l_dir);
	pl.diff_stren = fmax(dot(pl.l_dir, info->rec.normal), 0.0);
	pl.diffuse = mult_t(light.amount, pl.diff_stren);
	project = mult_t(info->rec.normal, dot(pl.l_dir, info->rec.normal));
	pl.reflect = plus(mult_t(pl.l_dir, -1.0), \
	mult_t(project, 2.0));
	pl.view = unit(mult_t(info->ray.dir, -1.0));
	pl.similar = pow(fmax(dot(pl.reflect, pl.view), 0.0), SHININESS);
	pl.specular = mult_t(mult_t(light.amount, pl.similar), SPEC_STREN);

	brightness = light.ratio * LUMEN;
	return (mult_t(plus(pl.diffuse, pl.specular), brightness));
}

t_color3	lighting_set(t_info *info)
{
	t_color3	light_amount;
	t_light		light;

	light_amount = color3(0, 0, 0);
	light = info->light;

	light_amount = plus(light_amount, get_light_amount(info, light));
	light_amount = plus(light_amount, info->ambient.amount);
	light_amount = color3(light_amount.x * info->rec.rgb.x, \
	light_amount.y * info->rec.rgb.y, \
	light_amount.z * info->rec.rgb.z);
	return(color3(fmin(light_amount.x , 1.0), fmin(light_amount.y , 1.0), fmin(light_amount.z , 1.0)));
}
