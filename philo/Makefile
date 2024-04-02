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
# B_NAME		=	philo_bonus

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

SRC_DIR			=	srcs/
SRCS			=	$(addprefix $(CONFIGS_DIR), $(CONFIGS_FILES)) \
					$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
					main.c

OBJ_DIR			=	objs/
OBJ_NAMES		=	$(SRCS:.c=.o)
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR))
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))

#############################	  BONUS PART	#################################

# B_SRC_DIR		=	bonus_srcs/
# B_SRCS		=	$(addprefix $(CONFIGS_DIR), $(CONFIGS_FILES)) \
# 					$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
# 					main_bonus.c

# B_OBJ_DIR		=	bonus_objs/
# B_OBJ_NAMES	=	$(B_SRCS:.c=.o)
# B_OBJ_DIRS	=	$(addprefix $(B_OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR))
# B_OBJS		=	$(addprefix $(B_OBJ_DIR), $(B_OBJ_NAMES))

#******************************************************************************#
#	DEPENDENCIES
#******************************************************************************#

DEP_NAMES		=	$(SRCS:.c=.d)
DEP_DIRS		=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR))
DEPS			=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))

#############################	  BONUS PART	#################################

# B_DEP_NAMES	=	$(B_SRCS:.c=.d)
# B_DEP_DIRS	=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR))
# B_DEPS		=	$(addprefix $(B_OBJ_DIR), $(B_DEP_NAMES))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
				@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			@printf "$(RESET)$(shell bash rainbow.sh "[PHILO Mandatory]"): "
			@printf "$(RESET)$(BOLD)$(YELLOW)Compilation done!\n\n$(RESET)"
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME)
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

#******************************************************************************#
#	BONUS
#******************************************************************************#

# $(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c
# 					@mkdir -p $(dir $@)
# 					@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
# 					@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
# -include $(B_DEPS)

# $(B_NAME): $(B_OBJS)
# 				@printf "$(RESET)$(shell bash rainbow.sh "[FRACT-OL Bonus]"): "
# 				@printf "$(RESET)$(BOLD)$(YELLOW)Bonus compilation done!\n\n$(RESET)"
# 				@$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)

# bonus:		$(B_NAME)

.PHONY:		all clean fclean re diff norm