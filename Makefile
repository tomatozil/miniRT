NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS =	-L./mlx -lmlx -framework OpenGL -framework Appkit
INCLUDES = -I./includes

SRCS = $(addprefix ./src/, ${SRCS_FILES})
SRCS_FILES = main.c \
		parse_file.c \
		parse_major_object.c \
		parse_minor_object.c \
		parse_util.c \
		vector.c \
		object.c \
		ray.c \
		hit.c \
		lighting.c \
		util.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<


$(NAME) :$(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean :
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re all