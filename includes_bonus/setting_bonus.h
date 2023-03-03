#ifndef SETTING_BONUS_H
#define SETTING_BONUS_H

# include "structures_bonus.h"

void	mlx_setting(t_info *info);
t_vec3	cam_set_vup(t_vec3 dir);
void	cam_setting(t_cam *cam);
void	free_objects(t_info *info);

#endif
