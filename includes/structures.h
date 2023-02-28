#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

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
	t_vec3		dir;
}	t_ray;

typedef struct s_cam
{
	t_point3	origin;
	t_vec3		dir;
	double		fov;

	double		viewport_w;
	double		viewport_h;
	t_vec3		dir_hor;
	t_vec3		dir_ver;
	double		focal_len;
	t_point3	left_bottom;
}	t_cam;

typedef struct s_object
{
	t_obj_type	type;
	void		*element;
	void		*next;
}	t_object;

typedef struct s_sphere
{
	t_point3	point;
	t_color3	rgb;
	double		radius; //-> diameter / 2.0 (결과가 double 이어야함)
	double 		radius_d; //-> radius * radius
}	t_sphere;

typedef struct s_plane
{
	t_point3	point;
	t_vec3		dir;
	t_color3	rgb;
}	t_plane;

typedef struct	s_cylinder
{
	t_point3	point;
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
	double		front_face;
	t_color3	rgb;
}	t_hit_record;

typedef struct s_light
{
	t_point3	origin;
	t_color3	amount;
	double		ratio;
}	t_light;

typedef struct s_ambient
{
	t_color3	amount;
	double		ratio;
}	t_ambient;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int 			size_line;
	int 			endian;
	t_cam			cam;
	t_object		*objects;
	t_light			light;
	t_ambient		ambient; //추후 t_ambient
	t_ray			ray;
	t_hit_record	rec;
}	t_info;

#endif
