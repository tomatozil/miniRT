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
			*(unsigned int *)dst = ((int)(255.999 * colors.x) * 256 * 256) + \
			((int)(255.999 * colors.y) * 256) + (int)(255.999 * colors.z);
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
	t_vec3	u;
	t_vec3	v;

	// ------파싱에서 넣어주는 부분------
	cam->fov = 90.0;
	cam->origin = point3(0, 0, 5);
	cam->dir = vec3(0, 0, -1);
	// ---------------------------

	cam->focal_len = tan((cam->fov * M_PI / 180.0) / 2.0);
	cam->viewport_h = 2.0 * cam->focal_len;
	cam->viewport_w = cam->viewport_h * (double)WIDTH / (double)HEIGHT;
	opposite = mult_t(cam->dir, -1);
	u = unit(cross(cam_set_vup(cam->dir), opposite));
	printf("%lf %lf %lf\n", u.x, u.y, u.z);
	v = cross(opposite, u);
	cam->dir_hor = mult_t(u, cam->viewport_w);
	cam->dir_ver = mult_t(v, cam->viewport_h);
	cam->left_bottom = minus(minus(minus(cam->origin, \
		devide_t(cam->dir_hor, 2)), devide_t(cam->dir_ver, 2)), opposite);
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
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_hook(info->win, 17, 0, red_button, info);
	mlx_hook(info->win, 4, 0, mouse_click, info);

	mlx_loop(info->mlx);
	return (0);
}

