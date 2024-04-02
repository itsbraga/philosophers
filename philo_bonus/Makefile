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

NAME_BONUS	=	philo_bonus
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g -g3
MAKEFLAGS	+=	--no-print-directory
RM			=	rm -rf

#******************************************************************************#
#	SOURCES
#******************************************************************************#

CONFIGS_DIR		=	configs/
CONFIGS_FILES	=	

EXEC_DIR		=	exec/
EXEC_FILES		=	

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRC_DIR			=	bonus_srcs/
SRCS			=	$(addprefix $(CONFIGS_DIR), $(CONFIGS_FILES)) \
					$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
					main.c

OBJ_DIR			=	bonus_objs/
OBJ_NAMES		=	$(SRCS:.c=.o)
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR))
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))

#******************************************************************************#
#	DEPENDENCIES
#******************************************************************************#

DEP_NAMES		=	$(SRCS:.c=.d)
DEP_DIRS		=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR))
DEPS			=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME_BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
				@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME_BONUS): $(OBJS)
				@printf "$(RESET)$(shell bash rainbow.sh "[PHILO Bonus]"): "
				@printf "$(RESET)$(BOLD)$(YELLOW)Compilation done!\n\n$(RESET)"
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME_BONUS)

clean:
		@$(RM) $(OBJ_DIR)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME_BONUS)
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]: $(RESET)Full clean completed!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:		fclean all
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n"
			@printf "\n\n✨ $(BOLD)CLEANING and REBUILDING DONE! $(RESET)✨\n\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

norm:
		@clear
		@norminette $(SRC_DIR) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re diff norm