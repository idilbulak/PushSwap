GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			=	push_swap

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	push_swap.c get_args.c array_utils.c array_utils2.c \
					sort.c sort_large.c sort_utils.c swap_functions.c   \
					rotate_functions.c reverse_rotate_functions.c \
					push_functions.c sort_3.c sort_4.c sort_5.c

BONUS_F			=	checker.c get_next_line.c get_next_line_utils.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

BONUS			=	$(addprefix $(SRCS_DIR), $(BONUS_F))

ifdef WITH_BONUS
OBJS = $(SRCS:.c=.o) $(BONUS:.c=.o)
else
OBJS = $(SRCS:.c=.o)
endif

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror 

.c.o:			
				$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Push_swap is ready to sort! Please give some random integers as input..$(RESET)"

all:			$(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus