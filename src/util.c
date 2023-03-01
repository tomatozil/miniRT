#include "minirt.h"

void	obj_add(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

#include "minirt.h"

void	reverse_color(t_object *obj)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->element;
		sphere->rgb = (t_point3){1 - sphere->rgb.x, \
			1 - sphere->rgb.y, 1 - sphere->rgb.z};
	}
	else if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->element;
		plane->rgb = (t_point3){1 - plane->rgb.x, \
			1 - plane->rgb.y, 1 - plane->rgb.z};
	}
	else if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->element;
		cylinder->rgb = (t_point3){1 - cylinder->rgb.x, \
			1 - cylinder->rgb.y, 1 - cylinder->rgb.z};
	}
}
