#ifndef MINIRT_H
#define MINIRT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# include "structures.h"
# include "vector.h"
# include "ray.h"
# include "hit.h"

# include "util.h"
# include "object.h"

# define FALSE 0
# define TRUE 1
# define WIDTH	1200
# define HEIGHT	800
# define EPSILON 1e-6
# define LUMEN 3

void	scene_init(t_info *info);

void draw(t_info *info);

#endif
