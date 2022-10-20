# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 18:41:36 by yeongo            #+#    #+#              #
#    Updated: 2022/10/20 10:14:52 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
FRAMEWORK		:=	-framework OpenGL -framework AppKit
RM				:=	rm -rf

LIBFT			:=	./libft/libft.a
LIBFT_DIR		:=	./libft/
LIBMLX			:=	./mlx/libmlx.a
LIBMLX_DIR		:=	./mlx/
LDFAGS			:=	-L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx

HEADER			:=	./include/
SRC_DIR			:=	./src/
OBJ_DIR			:=	./.obj/

HEADER_BONUS	:=	./bonus/include/
SRC_B_DIR		:=	./bonus/src/
OBJ_B_DIR		:=	./bonus/.obj/

SRC_FILES		:=	$(addsuffix .c,			\
					terminate				\
					init					\
					ft_mlx					\
					parse					\
					parse_util				\
					movement				\
					render					\
					render_component		\
					so_long)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_B_FILES		:=	$(addsuffix .c,			\
					terminate_bonus			\
					init_player_bonus		\
					init_bonus				\
					ft_mlx_bonus			\
					parse_utils_bonus		\
					parse_bonus				\
					movement_bonus			\
					render_component_bonus	\
					render_bonus			\
					so_long_bonus)
OBJ_B_FILES		:=	$(SRC_B_FILES:.c=.o)
SRC_BONUS		:=	$(addprefix $(SRC_B_DIR), $(SRC_B_FILES))
OBJ_BONUS		:=	$(addprefix $(OBJ_B_DIR), $(OBJ_B_FILES))

ifdef BONUS
		INCLUDE			=	$(HEADER_BONUS)
		SRC_FOLDER		=	$(SRC_B_DIR)
		OBJ_FOLDER		=	$(OBJ_B_DIR)
		OBJS			=	$(OBJ_BONUS)
		PRINT			=	BONUS
else
		INCLUDE			=	$(HEADER)
		SRC_FOLDER		=	$(SRC_DIR)
		OBJ_FOLDER		=	$(OBJ_DIR)
		OBJS			=	$(OBJ)
		PRINT			=	SO_LONG
endif

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(LDFAGS) $(FRAMEWORK) -o $@ $^
	@echo "\033[01;32m       SUCCESS!      \033[0m"

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(LIBMLX_DIR) -I$(INCLUDE) -c -o $@ $<

$(LIBFT)	:
	@make -s -C $(LIBFT_DIR) all

$(LIBMLX)	:
	@make -s -C $(LIBMLX_DIR) all 2> /dev/null

.PHONY	:	bonus
bonus	:
	@make BONUS=1 all

.PHONY	:	clean
clean	:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(LIBMLX_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_B_DIR)
	@echo "\033[91m      REMOVE OBJECT      \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "\033[91m      FCLEAN DONE      \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
