#ifndef MINIRT_H
#define MINIRT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"

# include "libft.h"
# include "structures.h"
# include "vector.h"
# include "parse.h"
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

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;36m"

typedef enum e_info_type
{
	AMB	= 0x0001,
	CAM	= 0x0002,
	LIT	= 0x0004,
}	t_info_type;

void	tmp_init(t_info *info);

void draw(t_info *info);

#endif
