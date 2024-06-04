#---------------------------------------------------#
CC			= cc

CFLAGS 		= -g3 -Wall -Wextra #-Werror

NAME 		=  philo

#---------------------------------------------------#
SRCS		= src/main.c\
			  src/philo.c\
			  src/init.c\
			  src/exit.c\
			  src/philo_utils.c

INCLUDE		= includes/tools.c\

OBJ_DIR		= .obj

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(INCLUDE:%.c=$(OBJ_DIR)/%.o)

HEADERS		= includes/philo.h includes/tools.h

#---------------------------------------------------#
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o  $(NAME)

$(OBJ_DIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -pthread -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re