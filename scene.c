#include "minirt.h"

t_canvas	canvas_set(int w, int h)
{
	t_canvas	canvas;

	canvas.canvas_w = w;
	canvas.canvas_h = h;
	canvas.aspect_ratio = (double)w / (double)h;
	return (canvas);
}

t_cam	cam_set(t_canvas canvas, t_point3 origin)
{
	t_cam	cam;
	double	focal_len;
	double	viewport_h;

	double 	fov = 70.0;

	focal_len = 1.0;
	double h = tan(fov/2);
	viewport_h = 2.0 * h;
	cam.origin = origin;
	cam.viewport_h = viewport_h;
	cam.viewport_w = viewport_h * canvas.aspect_ratio;
	cam.focal_len = focal_len;
	cam.dir_horizontal = vec3(cam.viewport_w, 0, 0);
	cam.dir_vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = minus(cam.origin, vec3(0, 0, cam.focal_len));
	cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_vertical, 2));
	cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_horizontal, 2));
	return (cam);
}