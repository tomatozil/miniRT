#include "minirt.h"

void	mlx_setting(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_error("mlx_init() failed");
	if (!info->win)
		info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "test");
	if (!info->img)
		info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->addr)
		info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->size_line, &info->endian);
}

t_vec3	cam_set_vup(t_vec3 dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (vec3(0, dir.y, 1e-6));
	else
		return (vec3(0, 1, 0));
}

void	cam_setting(t_cam *cam) // 원래 이름 cam_init
{
	t_vec3	opposite;
	t_vec3	hor;
	t_vec3	ver;

	// ------파싱에서 넣어주는 부분------
	cam->fov = 90.0;
	cam->origin = point3(0, 0, 5);
	cam->dir = vec3(0, 0, -1);
	// ---------------------------

	cam->focal_len = tan((cam->fov * M_PI / 180.0) / 2.0);
	cam->viewport_h = 2.0 * cam->focal_len;
	cam->viewport_w = cam->viewport_h * (double)WIDTH / (double)HEIGHT;
	opposite = mult_t(cam->dir, -1);
	hor = unit(cross(cam_set_vup(cam->dir), opposite));
	ver = cross(opposite, hor);
	cam->dir_hor = mult_t(hor, cam->viewport_w);
	cam->dir_ver = mult_t(ver, cam->viewport_h);
	cam->left_bottom = minus(minus(minus(cam->origin, \
		devide_t(cam->dir_hor, 2)), devide_t(cam->dir_ver, 2)), opposite);
}

void	scene_init(t_info *info)
{
	mlx_setting(info);
	cam_setting(&info->cam);
}

static void	parse(char *argv, t_info *info)
{
	char	*content;

	content = ft_strdup("");
	if (!content)
		ft_error("memory alloc failed");
	check_file_extension(argv);
	read_file(argv, &content);
	parse_to_info(content, info);
	scene_init(info);
}

void draw(t_info *info)
{
	int			i;
	int 		j;
	char		*dst;
	t_color3	colors;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			info->ray = ray_primary(info->cam, \
			(double)i / (WIDTH - 1), \
			(HEIGHT - 1 - (double)j) / (HEIGHT - 1));
			colors = ray_color(info->ray, info);
			dst = info->addr + (j * info->size_line + i * 4);
			*(unsigned int *)dst = ((int)(255.999 * colors.x) * 256 * 256) + \
			((int)(255.999 * colors.y) * 256) + (int)(255.999 * colors.z);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

//void	tmp_init(t_info *info)
//{
//	t_object	*objects;
//	t_light		light;
//
//	objects = object(SPHERE, sphere(point3(2, 0, -5), color3(0, 0, 0.5), 2));
//	obj_add(&objects, object(SPHERE, sphere(point3(-3, 0, -20), color3(0, 0.5, 0), 10)));
//	obj_add(&objects, object(PLANE, plane(point3(0, -3, 0), unit(vec3(-0.4, -1, 0)), color3(1, 1, 0))));
//	obj_add(&objects, object(PLANE, plane(point3(0, -8, 0), unit(vec3(0.3, -1, 0)), color3(0, 1, 0))));
//	obj_add(&objects, object(CYLINDER, cylinder(point3(-1, 2, -4), unit(vec3(-0.4, -1, 1)), color3(1, 0.5, 0), 1, 5)));
//	obj_add(&objects, object(SPHERE, sphere(point3(3, 3, -5), color3(0, 0.5, 0.5), 1)));
//	info->objects = objects;
//
//	light = light_set(point3(0, 10, 0), color3(1, 1, 1), 0.5);
//	info->light = light;
//
//	info->ambient.ratio = 0.3;
//
//	info->ambient.amount = mult_t(color3(1, 1, 1), info->ambient.ratio);
//}

int main(int argc, char *argv[])
{
	t_info		info;

	ft_memset(&info, 0, sizeof(t_info));
//	tmp_init(&info);
//	mlx_setting(&info);
//	cam_setting(&info.cam);

	if (argc != 2)
		ft_error("wrong number of arguments");

	parse(argv[1], &info);
	draw(&info);
//	mlx_hook(info.win, 2, 0, key_press, info);
//	mlx_hook(info.win, 17, 0, red_button, info);
	mlx_loop(info.mlx);
	return (0);
}

