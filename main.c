#include "minirt.h"

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
			*(unsigned int *)dst = ((int)(255.999 * colors.x) * 256 * 256) + ((int)(255.999 * colors.y) * 256) + (int)(255.999 * colors.z);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	mlx_setting(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "test");
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->size_line, &info->endian);
}

void	cam_setting(t_cam *cam)
{
	double	focal_len;
	double	viewport_h;
	double 	fov = 90.0;

	focal_len = 1.0;
	double h = tan(fov/2);
	viewport_h = 2.0 * h;
	cam->viewport_h = viewport_h;
	cam->viewport_w = viewport_h * ((double)WIDTH / (double)HEIGHT);
	cam->focal_len = focal_len;
	cam->dir_horiz = vec3(cam->viewport_w, 0, 0);
	cam->dir_verti = vec3(0, cam->viewport_h, 0);
	cam->left_bottom = minus(cam->origin, vec3(0, 0, cam->focal_len));
	cam->left_bottom = minus(cam->left_bottom, devide_t(cam->dir_verti, 2));
	cam->left_bottom = minus(cam->left_bottom, devide_t(cam->dir_horiz, 2));
}

int main()
{
	t_info		*info;

	if (!(info = malloc(sizeof(t_info))))
		return (0);
	scene_init(info);

	//parse(argv[1], &info);

	cam_setting(&info->cam); // -> 이거 parse() 안 어딘가에 넣으면 좋을듯
	mlx_setting(info); // -> 이거 parse() 안 어딘가에 넣으면 좋을듯

	// render with ray_set
	draw(info);

	// mlx_hook


	mlx_loop(info->mlx);
	return (0);
}

