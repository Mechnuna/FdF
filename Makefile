NAME	=   fdf
LIBRARIES = -lmlx -lm  -L$(MINILIBX_DIRECTORY)
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.dylib
MINILIBX_DIRECTORY = ./minilibx_macos_del/

SRCS	= draw.c \
			fdf.c \
			gnl.c \
			libft1.c \
			libft2.c  \
			libft3.c \
			read_file.c \
			split.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
INCS	= .

%.o : %.c 
#	${CC} ${FLAGS} $(LIBRARIES) -c $< -o ${<:.c=.o} -I${INCS}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
# $(NAME): 
# 	@$(MAKE) -sC $(MINILIBX_DIRECTORY)
# 	@$(CC) $(FLAGS) -I. $(OBJS) $(LIBRARIES) -o $(NAME)
# 	mv minilibx_macos_del/libmlx.dylib .
$(NAME): $(OBJS)
		$(MAKE) -sC $(MINILIBX_DIRECTORY)
		$(CC) $(FLAGS) -o $(NAME)  $(OBJS) $(LIBRARIES)
		mv minilibx_macos_del/libmlx.dylib .

all: $(NAME)

bonus: all
fclean: clean
	$(RM) $(NAME)
	$(RM) libmlx.dylib

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o%