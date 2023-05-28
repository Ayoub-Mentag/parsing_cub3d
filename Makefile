GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRCS = parsing.c ${GET_NEXT_LINE} ft_split.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -Ofast -g -fsanitize=address
LINKS = -lmlx -framework OpenGL -framework AppKit

NAME = cub3d

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf $(NAME)

re : fclean all