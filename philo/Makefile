#******************************************************************************#
#	MODES && COLORS
#******************************************************************************#

RESET		:=	\e[0m
BOLD		:=	\e[1m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

RED			:=	\e[31m
ORANGE		:=	\e[38;5;208m
YELLOW		:=	\e[33m
GREEN		:=	\e[32m
CYAN		:=	\e[36m
BLUE		:=	\e[34m
INDIGO		:=	\e[34;45m
PURPLE		:=	\e[35m
PINK		:=	\e[38;2;255;182;193m

#******************************************************************************#
#	BASICS
#******************************************************************************#

NAME		=	philo
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -pthread -Iinclude/
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory
FSANITIZE	=	-fsanitize=thread
DEBUG		=	-g -g3
RM			=	rm -rf

#******************************************************************************#
#	SOURCES, OBJECTS AND DEPENDENCIES
#******************************************************************************#

SRC_DIR		=	$(shell find srcs -type d)
SRCS		=	$(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
vpath %.c $(SRC_DIR)

OBJ_DIR		=	objs/
OBJS		=	$(patsubst srcs/%.c,$(OBJ_DIR)%.o,$(SRCS))

DEPS		=	$(patsubst srcs/%.c,$(OBJ_DIR)%.d,$(SRCS))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJ_DIR)%.o: %.c
				@mkdir -p $(dir $@)
				@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			@printf "$(BOLD)\n================= PHILOSOPHERS =================\n\n"
			@printf "$(ITAL)$(PURPLE)Generating: $(RESET)$(ITAL)$<          \r"
			@printf "\n\n$(RESET)$(shell bash rainbow.sh "[Mandatory]"): "
			@printf "$(RESET)$(BOLD)$(PINK)Compilation done!\n\n$(RESET)"
			@printf "$(BOLD)================================================\n\n$(RESET)"
			@$(CC) $(CFLAGS) -g3 $(OBJS) -o $(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME)
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]: $(RESET)Full clean completed!\n\n"

re:		fclean all
			@printf "✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

san: $(FSANITIZE)

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

norm:
		@clear
		@norminette $(SRC_DIR) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re diff norm