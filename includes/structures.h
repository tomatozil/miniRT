#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int 	size_line;
	int 	endian;
}	t_mlx;

struct s_dot3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_dot3 t_point3;
typedef struct s_dot3 t_vec3;
typedef struct s_dot3 t_color3;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir_v;
}	t_ray;

typedef struct s_cam
{
	t_point3	origin;
	double		viewport_w;
	double		viewport_h;
	t_vec3		dir_horizontal;
	t_vec3		dir_vertical;
	double		focal_len;
	double		fov;
	t_point3	left_bottom;
}	t_cam;

typedef struct s_canvas
{
	int		canvas_w;
	int		canvas_h;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_object
{
	t_obj_type	type;
	void		*element;
	void		*next;
	t_color3	albedo;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	t_color3	rgb;
	double		radius; //-> diameter / 2.0 (결과가 double 이어야함)
	double 		radius_d; //-> radius * radius
}	t_sphere;

typedef struct s_plane
{
	t_point3	center;
	t_vec3		dir;
	t_color3	rgb;
}	t_plane;

typedef struct	s_cylinder
{
	t_point3	center;
	t_vec3		dir;
	t_color3	rgb;
	double 		radius; //-> diameter / 2.0 (결과가 double 이어야함)
	double 		radius_d; //-> radius * radius
	double 		height;
}	t_cylinder;

typedef struct s_hit_record
{
	t_point3	hit_point;
	t_vec3		normal_v;
	double		t;
	double		t_min; // t가 음수면 광선이 뒤를 향하는 것 = 카메라 뒤에 있는 것
	double 		t_max; // 너무 멀 경우
	int 		front_face;
	t_color3	albedo;
}	t_hit_record;

typedef struct s_light
{
	t_point3	origin;
	t_color3	amount;
	double		bright_ratio;
}	t_light;

typedef struct s_ambient
{
	t_color3	amount;
	double		ambient_ratio;
}	t_ambient;

typedef struct s_info
{
	t_canvas		canvas;
	t_cam			cam;
	t_object		*objects;
	t_object		*lights;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_info;

#endif
