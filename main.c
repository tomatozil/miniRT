#include "minirt.h"

#define WIDTH 600
#define HEIGHT 400

/*
void	my_mlx_pixel_put(t_mlx *data, int x, int y)
{
	char	*dst;

	int	i, j;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			double r_d = (double)i / (WIDTH - 1);
			double g_d = (HEIGHT - 1 - (double)j) / (HEIGHT - 1);
			double b_d = 0.25f;

			int r_i = 255.999 * r_d;
			int g_i = 255.999 * g_d;
			int b_i = 255.999 * b_d;

			dst = data->addr + (j * data->size_line + i * 4);
			*(unsigned int *)dst = (r_i * 256 * 256) + (g_i * 256) + b_i;
//			dst = data->addr + (j * data->size_line + i * (data->bits_per_pixel / 8));
//			*dst = '\0';
//			dst += 1;
//			*dst =(char)r_i;
//			dst += 1;
//			*dst =(char)g_i;
//			dst += 1;
//			*dst =(char)b_i;
			i++;
		}
		j++;
	}
}
*/

int main()
{
	t_info		*info;
	t_color3	colors;
	int max_depth = 30;

	char	*dst;

	info = scene_init();

	// mlx setting
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->canvas.canvas_w, info->canvas.canvas_h, "test");
	info->img = mlx_new_image(info->mlx, info->canvas.canvas_w, info->canvas.canvas_h);
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->size_line, &info->endian);


	// render with ray_set
	int j = 0;
	while (j < info->canvas.canvas_h)
	{
		int i = 0;
		while (i < info->canvas.canvas_w)
		{
			double u = (double)i / (info->canvas.canvas_w - 1);
			double v = (info->canvas.canvas_h - 1 - (double)j) / (info->canvas.canvas_h - 1);
			info->ray = ray_primary(info->cam, u, v);
			colors = ray_color(info->ray, info, max_depth);
			int r = 255.999 * colors.x;
			int g = 255.999 * colors.y;
			int b = 255.999 * colors.z;
			dst = info->addr + (j * info->size_line + i * 4);
			*(unsigned int *)dst = (r * 256 * 256) + (g * 256) + b;
			i++;
		}
		j++;
	}
//	my_mlx_pixel_put(&data, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_loop(info->mlx);
}

