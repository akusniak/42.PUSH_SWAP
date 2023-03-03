NAME = push_swap
CHECKER = checker

CC = @cc
CFLAGS = -Wall -Wextra -Werror

COLOUR_GREEN=\033[0;32m

RM = @rm -f

SRCS =	action.c\
		data.c\
		leave.c\
		parsing.c\
		position.c\
		push_swap.c\
		search.c\
		state.c\
		sub_algo.c\
		utils/search_utils.c\
		utils/action_utils.c\
		utils/push_utils.c\
		utils/push_utils_bis.c\
		utils/push_utils_terce.c\
		utils/operations/push.c\
		utils/operations/rotate.c\
		utils/operations/swap.c

SRCS_BONUS = bonus/bonus.c\
		bonus/data_bonus.c\
		bonus/leave_bonus.c\
		bonus/parsing_bonus.c\
		bonus/position_bonus.c\
		bonus/state_bonus.c\
		bonus/utils_bonus/push_utils_bis_bonus.c\
		bonus/utils_bonus/push_utils_bonus.c\
		bonus/utils_bonus/push_utils_terce_bonus.c\
		bonus/utils_bonus/operations_bonus/push_bonus.c\
		bonus/utils_bonus/operations_bonus/rotate_bonus.c\
		bonus/utils_bonus/operations_bonus/swap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS =  $(SRCS_BONUS:.c=.o)

LIB = @make bonus -C ./libft

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
				$(LIB)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
				@echo "$(COLOUR_GREEN) $(NAME) compilation is done"

lib :
		$(LIB)

all :
		$(NAME)

bonus : $(OBJS_BONUS)
			$(LIB)
			$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(CHECKER)
			@echo "$(COLOUR_GREEN) $(CHECKER) compilation is done"

clean :
		$(RM) $(OBJS) $(OBJS_BONUS)
		@echo "$(COLOUR_GREEN) clean is done"

fclean : clean
		$(RM) $(NAME) $(CHECKER)
		@cd ./libft && make fclean
		@echo "$(COLOUR_GREEN) fclean is done"

re : fclean all

.PHONY: all clean fclean re lib bonus
