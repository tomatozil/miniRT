NAME = miniRT
BONUS = miniRT_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS =	-L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS = $(addprefix ./src/, ${SRCS_FILES})
SRCS_FILES = main.c \
			vector1.c \
			vector2.c \
			vector3.c \
			ray.c \
			hit.c \
			hit_sphere_plane.c \
			hit_cylinder.c \
			setting.c \
			lighting.c \
			parse_file.c \
			parse_major_object.c \
			parse_minor_object.c \
			parse_util.c \
			key_move.c \
			key_move_util.c \
			key_rotate.c \
			key_rotate_util.c \
			key.c

SRCS_BONUS = $(addprefix ./src_bonus/, ${SRCS_BONUS_FILES})
SRCS_BONUS_FILES = main_bonus.c \
			vector1_bonus.c \
			vector2_bonus.c \
			vector3_bonus.c \
			ray_bonus.c \
			hit_bonus.c \
			hit_sphere_plane_bonus.c \
			hit_cylinder_bonus.c \
			setting_bonus.c \
			lighting_bonus.c \
			parse_file_bonus.c \
			parse_major_object_bonus.c \
			parse_minor_object_bonus.c \
			parse_util_bonus.c \
			key_move_bonus.c \
			key_move_util_bonus.c \
			key_rotate_bonus.c \
			key_rotate_util_bonus.c \
			key_bonus.c

INCLUDES = -I./includes
INCLUDES_BONUS = -I./includes_bonus

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBFT = libft/libft.a

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_BONUS) -c -o $@ $<

all : $(NAME)

$(NAME) :$(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus : $(BONUS)

$(BONUS) :$(OBJS_BONUS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS)

clean :
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS) $(OBJS_BONUS)

fclean :
	make clean
	rm -f $(LIBFT)
	rm -f $(NAME) $(BONUS)

re :
	make fclean
	make all

.PHONY : clean fclean re all bonus
