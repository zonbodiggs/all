#---------------------------------------------------#
CC 			= cc

CFLAGS 		= -Wall -Wextra -Werror

NAME 		= libftprintf.a
#---------------------------------------------------#
SRCS		= \
	ft_printf.c\
	ft_printf_utils.c\

OBJ_DIR 	= .obj

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADERS		= ft_printf.h
#---------------------------------------------------#
all : $(NAME)
	
$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re