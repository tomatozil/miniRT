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
# include "scene.h"
# include "hit.h"

# include "list.h"
# include "object.h"

t_scene			*scene_init(void);
t_hit_record	record_init(void);

#endif
