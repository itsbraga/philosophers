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
CFLAGS		=	-Wall -Wextra -Werror -Iinclude/
MAKEFLAGS	+=	--no-print-directory
RM			=	rm -rf

#******************************************************************************#
#	SOURCES
#******************************************************************************#

EXEC_DIR		=	exec/
EXEC_FILES		=	check_args.c main.c

THREAD_DIR		=	threads/
THREAD_FILES	=	init.c routine.c

TOOLS_DIR		=	tools/
TOOLS_FILES		=	utils.c time.c lib.c

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRC_DIR			=	srcs/
SRCS			=	$(addprefix $(THREAD_DIR), $(THREAD_FILES)) \
					$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
					$(addprefix $(TOOLS_DIR), $(TOOLS_FILES))

OBJ_DIR			=	objs/
OBJ_NAMES		=	$(SRCS:.c=.o)
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(THREAD_DIR), $(EXEC_DIR), \
											$(TOOLS_DIR))
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))

#******************************************************************************#
#	DEPENDENCIES
#******************************************************************************#

DEP_NAMES		=	$(SRCS:.c=.d)
DEP_DIRS		=	$(addprefix $(OBJ_DIR), $(THREAD_DIR), $(EXEC_DIR), \
											$(TOOLS_DIR))
DEPS			=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			@printf "$(BOLD)\n================= PHILOSOPHERS =================\n\n"
			@printf "$(ITAL)$(PURPLE)Generating: $(RESET)$(ITAL)$<          \r"
			@printf "\n\n$(RESET)$(shell bash rainbow.sh "[Mandatory]"): "
			@printf "$(RESET)$(BOLD)$(PINK)Compilation done!\n\n$(RESET)"
			@printf "$(BOLD)================================================\n\n"
			@$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME)
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]: $(RESET)Full clean completed!\n\n"

re:		fclean all
			@printf "✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

norm:
		@clear
		@norminette $(SRC_DIR) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re diff norm