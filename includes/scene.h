#ifndef SCENE_H
#define SCENE_H

# include "minirt.h"

t_canvas	canvas_set(int w, int h);
t_cam	cam_set(t_canvas canvas, t_point3 origin);

t_sphere	sphere_set(t_point3 center, double radius);

#endif
