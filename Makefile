GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			=	push_swap

NAME_BONUS		=	checker

SRCS_DIR		=	./src/

SRCS_BONUS_DIR	=	./src_bonus/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	push_swap.c get_args.c ps_utils.c ps_utils2.c \
					sort_large.c ps_utils3.c swap_functions.c \
					rotate_functions.c reverse_rotate_functions.c \
					push_functions.c sort_3.c sort_4.c sort_5.c \
					ps_utils4.c ps_utils5.c

SRCS_BONUS_F	=	checker.c get_next_line_bonus.c get_next_line_utils_bonus.c \
					ps_utils_bonus.c ps_utils2_bonus.c ps_utils3_bonus.c \
					swap_functions_bonus.c rotate_functions_bonus.c \
					reverse_rotate_functions_bonus.c \
					push_functions_bonus.c get_args_bonus.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

SRCS_BONUS		=	$(addprefix $(SRCS_BONUS_DIR), $(SRCS_BONUS_F))

OBJS 			= $(SRCS:.c=.o)

OBJS_BONUS 		= $(SRCS_BONUS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror 

.c.o:			
				$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Push_swap is ready to sort! Please give some random integers as input..$(RESET)"

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(CC_FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

all:			$(NAME)

bonus:			$(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
re: fclean all
.PHONY: all clean fclean re bonus