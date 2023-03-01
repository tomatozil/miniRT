#ifndef LIST_H
#define LIST_H

# include "structures.h"

void	obj_add(t_object **list, t_object *new);
int	red_button(int exitcode, t_info *info);
int	key_press(int keycode, t_info *info);

#endif
