#ifndef LIST_H
#define LIST_H

# include "minirt.h"

void	obj_add(t_object **list, t_object *new);
int	red_button(int exitcode, t_info *info);
int	key_press(int keycode, t_info *info);
int mouse_click(int click, int x, int y, t_info *info);

#endif
