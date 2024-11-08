#******************************************************************************#
#	FEATURES
#******************************************************************************#

RESET		:=	\e[0m
BOLD		:=	\e[1m
ITAL		:=	\e[3m
BLINK		:=	\e[5m

YELLOW		:=	\e[33m
GREEN		:=	\e[32m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\e[38;2;255;182;193m

#******************************************************************************#
#	BASICS
#******************************************************************************#

NAME_BONUS	=	philo_bonus

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -pthread -Iinclude/
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory

FSANITIZE	=	-fsanitize=thread
DEBUG		=	-g -g3

#******************************************************************************#
#	SOURCES
#******************************************************************************#

EXEC_DIR	=	exec/
EXEC_F		=	

THREADS_DIR	=	threads/
THREADS_F	=	

TOOLS_DIR	=	tools/
TOOLS_F		=	

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRCS_DIR	=	bonus_srcs/
SRCS_F		=	$(addprefix $(EXEC_DIR), $(EXEC_F)) \
				$(addprefix $(THREADS_DIR), $(THREADS_F)) \
				$(addprefix $(TOOLS_DIR), $(TOOLS_F)) \
				main.c

OBJS_DIR	=	bonus_objs/
OBJS_F		=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_F		=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))


#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME_BONUS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(GREEN)Compiled: $(RESET)$(ITAL)$<                                  \n"
				@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS_F)

$(NAME_BONUS): $(OBJS_F)
				@printf "$(RESET)$(BOLD)$(shell bash rainbow.sh "[Bonus]"): "
				@printf "$(RESET)Compilation done!\n\n"
				@$(CC) $(DEBUG) $(CFLAGS) $(OBJS_F) -o $(NAME_BONUS)

clean:
		@rm -rf $(OBJS_DIR)
		@printf "\n$(BOLD)$(PURPLE)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@rm -rf $(NAME_BONUS)
			@printf "$(BOLD)$(PINK)[exec]:  $(RESET)Full clean completed!\n\n"

re:		fclean all
			@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

san: $(FSANITIZE)

norm:
		@clear
		@norminette $(SRCS_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re san norm