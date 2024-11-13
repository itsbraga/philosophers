#******************************************************************************#
#	TEXT CUSTOM
#******************************************************************************#

RESET			:=	\e[0m
BOLD			:=	\e[1m
ITAL			:=	\e[3m
BLINK			:=	\e[5m

YELLOW			:=	\e[38;2;255;234;150m
BLUE			:=	\e[34m
CYAN			:=	\e[36m
PURPLE			:=	\e[38;2;211;211;255m
PASTEL_PURPLE	:=	\e[38;2;211;211;255m

#******************************************************************************#
#	BASICS
#******************************************************************************#

NAME		=	philo

CC			=	cc
INC			=	includes/


CFLAGS		=	-Wall -Wextra -Werror -pthread -I
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory

FSANITIZE	=	-fsanitize=thread
VALG_TOOL	=	--tool=helgrind
DEBUG		=	-g -g3

#******************************************************************************#
#	SOURCES
#******************************************************************************#

MAIN_DIR	=	main/
MAIN_F		=	check_args.c init_structs.c main.c

THREADS_DIR	=	threads/
THREADS_F	=	threads.c routine.c supervisor.c

TOOLS_DIR	=	tools/
TOOLS_F		=	lib.c time.c msg.c

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRCS_DIR		=	srcs/
SRCS_F			=	$(addprefix $(MAIN_DIR), $(MAIN_F)) \
					$(addprefix $(THREADS_DIR), $(THREADS_F)) \
					$(addprefix $(TOOLS_DIR), $(TOOLS_F))

OBJS_DIR		=	objs/
OBJS_F			=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_F			=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiled: $(RESET)$(ITAL)$<                                  \n"
				@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@
-include $(DEPS_F)

$(NAME): $(OBJS_F)
			@printf "$(RESET)$(BOLD)\n\n=================[ $(shell bash rainbow.sh "PHILOSOPHERS")"
			@printf "$(BOLD) ]===================\n\n"
			@printf "\t $(PASTEL_PURPLE)Mandatory$(RESET): "
			@printf "$(RESET)$(BLINK)Compilation done!\n\n$(RESET)"
			@printf "$(BOLD)====================================================\n\n$(RESET)"
			@$(CC) $(DEBUG) $(CFLAGS) $(INC) $(OBJS_F) -o $(NAME)

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
		@norminette $(SRCS_DIR) $(INC) | grep -v Norme -B1 || true

.PHONY: all clean fclean re san norm