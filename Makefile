# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:13:14 by annabrag          #+#    #+#              #
#    Updated: 2023/12/19 19:15:36 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COLORS #####################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m


################################### BASICS ###################################

NAME		=	fractol
BONUS		=	fractol_bonus

LIBFT_PATH	=	libft/
MLX_PATH	=	minilibx-linux/

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/

RM		=	rm -rf

MAKEFLAGS	+=	--no-print-directory
MLXFLAGS	=	-lmlx -lXext -lX11


################################### SOURCES ###################################

SRC		= 
	
SRC_BONUS	=


######################## COMBINE DIRECTORIES AND FILES ########################

SRC_DIR		=	src/

SRCS		= 	$(addprefix $(SRC_DIR), $(SRC))
SRCS_BONUS	= 	$(addprefix $(SRC_DIR), $(SRC_BONUS))

OBJ_DIR		=	obj/

OBJ		=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

OBJS 		= 	$(addprefix $(OBJ_DIR), $(OBJ))
OBJS_BONUS	= 	$(addprefix $(OBJ_DIR), $(OBJ_BONUS))


#################################### RULES ####################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(GREEN)Compiling: $(RESET)$(ITAL)$<\n"
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@printf "$(RESET)$(BOLD)$(CYAN)[fractol]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(MLXFLAGS) $(OBJS) libmlx libft.a -o $(NAME)
			@printf "$(PINK) ./fractol ready to draw fractals $(RESET)🦜\n"

# constructs the necessary dependencies 
build:
		@make -sC $(MAKEFLAGS) $(MLX_PATH)
		@make -sC $(MAKEFLAGS) $(LIBFT_PATH)
		@cp $(MLX_PATH)/libmlx .
		@cp $(LIBFT_PATH)/libft.a .
		@make all
		@printf "\n✨ $(BOLD)$(YELLOW)MiniLibX and Libft ready! $(RESET)✨\n"

all:		$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -C $(MLX_PATH) $(MAKEFLAGS)
		@make clean -C $(LIBFT_PATH) $(MAKEFLAGS)
		@printf "$(BOLD)$(PINK)[fractol]: $(RESET)$(PINK)object files $(RESET)\t\t=> CLEANED! 💫\n\n"

fclean: 	clean
			@$(RM) $(NAME) (BONUS)
			@$(RM) $(MLX_PATH)/libmlx $(LIBFT_PATH)/libft.a
			@$(RM) libmlx libft.a
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[MiniLibX]: $(RESET)$(BLUE)exec. files $(RESET)\t=> CLEANED! 🧿\n\n"
			@printf "$(BOLD)$(PURPLE)[LIBFT]: $(RESET)$(PURPLE)exec. files $(RESET)\t=> CLEANED! 🦋\n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[fractol]: $(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED! 🌈\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


################################### BONUS ###################################

$(BONUS):	$(OBJS_BONUS)
			@printf "$(RESET)$(BOLD)$(CYAN)[fractol_bonus]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(MLXFLAGS) $(OBJS_BONUS) libmlx libft.a -o $(BONUS)
			@printf "$(PINK) ./fractol_bonus ready to draw more fractals! $(RESET)🦢\n\n"

bonus:
		@make -sC $(MAKEFLAGS) $(MLX_PATH)
		@make -sC $(MAKEFLAGS) $(LIBFT_PATH)
		@cp $(MLX_PATH)/libmlx .
		@cp $(LIBFT_PATH)/libft.a .
		@make allbonus
		@printf "\n✨ $(BOLD)$(YELLOW)MiniLibX and Libft ready for the bonuses! $(RESET)✨\n"

allbonus:	$(BONUS)

.PHONY:		build all clean fclean re bonus norm