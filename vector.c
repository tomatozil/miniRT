#include "minirt.h"

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_color3	color3(double x, double y, double z)
{
	t_color3	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

void	vec3_set(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double	vec3_len(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3	vec3_plus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.x + vec2.x;
	new.y = vec1.y + vec2.y;
	new.z = vec1.z + vec2.z;
	return (new);
}

t_vec3	vec3_minus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.x - vec2.x;
	new.y = vec1.y - vec2.y;
	new.z = vec1.z - vec2.z;
	return (new);
}

double	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 normal;

	normal.x = vec1.y * vec2.z - vec1.z * vec2.y;
	normal.y = vec1.z * vec2.x - vec1.x * vec2.z;
	normal.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (normal);
}

t_vec3	vec3_unit(t_vec3 vec)
{
	t_vec3	new;
	double	len;

	len = vec3_len(vec);
	if (len == 0)
	{
		printf("Error: Devider is 0\n");
		exit(1);
	}
	new.x = vec.x / len;
	new.y = vec.y / len;
	new.z = vec.z / len;
	return (new);
}

// 벡터 스칼라 곱하기(길이 늘리기), 스칼라 나누기 ?
t_vec3	vec3_mult_t(t_vec3 vec, double t)
{
	t_vec3	new;

	new.x = vec.x * t;
	new.y = vec.y * t;
	new.z = vec.z * t;
	return (new);
}

t_vec3	vec3_devide_t(t_vec3 vec, double t)
{
	t_vec3	new;

	new.x = vec.x / t;
	new.y = vec.y / t;
	new.z = vec.z / t;
	return (new);
}