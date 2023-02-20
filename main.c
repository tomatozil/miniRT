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
	const t_canvas	canvas = canvas_set(720, 360);
	t_mlx	data = {0, 0, 0, 0, 0, 0, 0};
	t_cam	cam;
	t_ray	ray;
	t_color3 colors;

	char	*dst;

	// mlx setting
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, canvas.canvas_w, canvas.canvas_h, "test");
	data.img = mlx_new_image(data.mlx, canvas.canvas_w, canvas.canvas_h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);

	// camera
	cam = cam_set(canvas, point3(0, 0, 0));

	t_sphere	sphere = sphere_set(point3(0, 0, -5), 2);

	// render with ray
	int j = 0;
	while (j < canvas.canvas_h)
	{
		int i = 0;
		while (i < canvas.canvas_w)
		{
			double u = (double)i / (canvas.canvas_w - 1);
			double v = (canvas.canvas_h - 1 - (double)j) / (canvas.canvas_h - 1);
			ray = ray_primary(cam, u, v);
			colors = ray_color(ray, sphere);
			int r = 255.999 * colors.x;
			int g = 255.999 * colors.y;
			int b = 255.999 * colors.z;
			dst = data.addr + (j * data.size_line + i * 4);
			*(unsigned int *)dst = (r * 256 * 256) + (g * 256) + b;
			i++;
		}
		j++;
	}
//	my_mlx_pixel_put(&data, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

