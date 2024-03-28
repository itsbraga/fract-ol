#################################################################################
#																				#
#				      				COLORS										#
#																				#
#################################################################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM			:=	\e[2m
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


#################################################################################
#																				#
#				    				BASICS										#
#																				#
#################################################################################

NAME		=	fractol
B_NAME		=	fractol_bonus

LIBFT_PATH	=	libft/
LIBFT_X		=	$(addprefix $(LIBFT_PATH), libft.a)
MLX_PATH	=	mlx/
MLX_X		=	$(addprefix $(MLX_PATH), libmlx.a)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g -g3
MLXFLAGS	=	-Lmlx -lX11 -lXext
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory

RM			=	rm -rf


#################################################################################
#																				#
#				    				SOURCES										#
#																				#
#################################################################################

CONFIGS_DIR		=	configs/
CONFIGS_FILES	=	mlx_exit.c mlx_events.c

EXEC_DIR		=	exec/
EXEC_FILES		=	equation.c fractal_sets.c init.c

SETS_DIR		=	sets/
SETS_FILES		=	mandelbrot.c julia.c

PARSING_DIR		=	parsing/
PARSING_FILES	=	check_args.c parse_args.c

TOOLS_DIR		=	tools/
TOOLS_FILES		=	pixels.c help.c errors.c utils.c

BONUS_DIR		=	bonus/
BONUS_FILES		=	new_events.c


#################################################################################
#																				#
#								COMBINE FILES									#
#				    				and											#
#								DIRECTORIES										#
#									  											#
#################################################################################

SRC_DIR		=	src/

SRCS		=	$(addprefix $(CONFIGS_DIR), $(CONFIGS_FILES)) \
				$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
				$(addprefix $(SETS_DIR), $(SETS_FILES)) \
				$(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
				$(addprefix $(TOOLS_DIR), $(TOOLS_FILES)) \
				main.c

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRCS:.c=.o)

OBJ_DIRS	=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR), \
							$(SETS_DIR), $(PARSING_DIR), $(TOOLS_DIR))

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#############################	  BONUS PART	#################################

B_SRC_DIR	=	src/

B_SRCS		=	$(addprefix $(CONFIGS_DIR), $(CONFIGS_FILES)) \
				$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
				$(addprefix $(SETS_DIR), $(SETS_FILES)) \
				$(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
				$(addprefix $(TOOLS_DIR), $(TOOLS_FILES)) \
				$(addprefix $(BONUS_DIR), $(BONUS_FILES)) \
				main_bonus.c

B_OBJ_DIR	=	obj/obj_bonus/

B_OBJ_NAMES	=	$(B_SRCS:.c=.o)

B_OBJ_DIRS	=	$(addprefix $(B_OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR), \
							$(SETS_DIR), $(PARSING_DIR), $(TOOLS_DIR), \
							$(BONUS_DIR))

B_OBJS		=	$(addprefix $(B_OBJ_DIR), $(B_OBJ_NAMES))


#################################################################################
#																				#
#								DEPENDENCIES									#
#																				#
#################################################################################

DEP_NAMES	=	$(SRCS:.c=.d)

DEP_DIRS	=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR), \
							$(SETS_DIR), $(PARSING_DIR), $(TOOLS_DIR))

DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))


#############################	  BONUS PART	#################################

B_DEP_NAMES	=	$(B_SRCS:.c=.d)

B_DEP_DIRS	=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR), \
							$(SETS_DIR), $(PARSING_DIR), $(TOOLS_DIR), \
							$(BONUS_DIR))

B_DEPS		=	$(addprefix $(B_OBJ_DIR), $(B_DEP_NAMES))


#################################################################################
#																				#
#				     				RULES										#
#																				#
#################################################################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
				@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
#				@$(CC) $(DEPFLAGS) $(CFLAGS) -I/usr/include -Imlx -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			@make -sC $(MLX_PATH) $(MAKEFLAGS)
			@printf "\n\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n"
			@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
			@if [ ! -f .build ]; then \
				printf "\t\t%s\n" \
				"   ▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄   " \
				"   █▒▒░░░░░░░░░▒▒█   " \
				"    █░░█░░░░░█░░█    " \
				" ▄▄  █░░░▀█▀░░░█  ▄▄ " \
				"█░░█ ▀▄░░░░░░░▄▀ █░░█"; \
				printf "\n\n"; \
				touch .build; fi
			@printf "$(RESET)$(shell bash rainbow.sh "[FRACT-OL Mandatory]"): "
			@printf "$(RESET)$(BOLD)$(YELLOW)Compilation done!\n\n$(RESET)"
			@$(CC) -O3 $(CFLAGS) $(OBJS) -Inc $(LIBFT_X) -Inc $(MLX_X) $(MLXFLAGS) -o $(NAME)
#			@$(CC) -O3 $(CFLAGS) $(OBJS) -Inc $(LIBFT_X) -Inc $(MLX_X) $(MLXFLAGS) -L/usr/lib -o $(NAME)
			@printf "$(RESET)$(PINK)You can now generate fractals. $(RESET)🌈\n\n"

all:	$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -sC $(MLX_PATH) $(MAKEFLAGS)
		@make clean -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME) $(B_NAME)
			@$(RM) $(MLX_X) $(LIBFT_X)
			@find . -name ".build" -delete
			@find . -name ".b_build" -delete
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]: $(RESET)Full clean completed!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

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
		@norminette $(SRC_DIR) $(LIBFT_PATH) | grep -v Norme -B1 || true


#################################################################################
#																				#
#				     				BONUS										#
#																				#
#################################################################################

$(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c
					@mkdir -p $(B_OBJ_DIRS)
					@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
					@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
#					@$(CC) $(DEPFLAGS) $(CFLAGS) -I/usr/include -Imlx -c $< -o $@
-include $(B_DEPS)

$(B_NAME): $(B_OBJS)
				@make -sC $(MLX_PATH) $(MAKEFLAGS)
				@printf "\n\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n"
				@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
				@if [ ! -f .b_build ]; then \
					printf "\t\t%s\n" \
					"        @@                " \
					"          @@              " \
					"           @@             " \
					"          @  @            " \
					"         @    @           " \
					"        @      @          " \
					"       @        @         " \
					"   #######;      @        " \
					" ########_##;   #######   " \
					"##########_##;########_## " \
					"##########_##;#########_##" \
					" ########_##;##########_##" \
					"   #######;   ########_## " \
					"                #######   "; \
					printf "\n\n"; \
					touch .b_build; fi
				@printf "$(RESET)$(shell bash rainbow.sh "[FRACT-OL Bonus]"): "
				@printf "$(RESET)$(BOLD)$(YELLOW)Compilation done!\n\n$(RESET)"
				@$(CC) -O3 $(CFLAGS) $(B_OBJS) -Inc $(LIBFT_X) -Inc $(MLX_X) $(MLXFLAGS) -o $(B_NAME)
#				@$(CC) -O3 $(CFLAGS) $(B_OBJS) -Inc $(LIBFT_X) -Inc $(MLX_X) $(MLXFLAGS) -L/usr/lib -o $(B_NAME)
				@printf "$(RESET)$(PINK)Bonuses are ready to launch! $(RESET)🍒\n\n"

bonus:		$(B_NAME)

.PHONY:		all clean fclean re diff norm bonus