#******************************************************************************#
#	FEATURES
#******************************************************************************#

RESET		:=	\e[0m
BOLD		:=	\e[1m
ITAL		:=	\e[3m
BLINK		:=	\e[5m

ORANGE		:=	\e[38;5;208m
YELLOW		:=	\e[33m
GREEN		:=	\e[32m
BLUE		:=	\e[34m
CYAN		:=	\e[36m

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

#******************************************************************************#
#	SOURCES
#******************************************************************************#

EXEC_DIR	=	exec/
EXEC_F		=	check_args.c

THREADS_DIR	=	threads/
THREADS_F	=	actions.c destroy.c init.c routine.c

TOOLS_DIR	=	tools/
TOOLS_F		=	lib.c time.c msg.c

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRCS_DIR		=	srcs/
SRCS_F			=	$(addprefix $(EXEC_DIR), $(EXEC_F)) \
					$(addprefix $(THREADS_DIR), $(THREADS_F)) \
					$(addprefix $(TOOLS_DIR), $(TOOLS_F)) \
					main.c

OBJS_DIR		=	objs/
OBJS_F			=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_F			=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(GREEN)Compiled: $(RESET)$(ITAL)$<                                  \n"
				@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS_F)

$(NAME): $(OBJS_F)
			@printf "$(RESET)$(BOLD)\n\n=================$(shell bash rainbow.sh " PHILOSOPHERS ")"
			@printf "$(BOLD)=================\n\n"
			@printf "\t $(ORANGE)[Mandatory]$(RESET): "
			@printf "$(RESET)Compilation done!\n\n"
			@printf "$(BOLD)================================================\n\n$(RESET)"
			@$(CC) $(DEBUG) $(CFLAGS) $(OBJS_F) -o $(NAME)

clean:
		@rm -rf $(OBJS_DIR)
		@printf "\n$(BOLD)$(BLUE)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@rm -rf $(NAME)
			@printf "$(BOLD)$(CYAN)[exec]:  $(RESET)Full clean completed!\n\n"

re:		fclean all
			@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

san: $(FSANITIZE)

norm:
		@clear
		@norminette $(SRCS_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re san norm