#ifndef LIST_H
#define LIST_H

# include "structures.h"

void	mlx_setting(t_info *info);
t_vec3	cam_set_vup(t_vec3 dir);
void	cam_setting(t_cam *cam);
void	free_objects(t_info *info);

#endif
