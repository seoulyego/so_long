# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 18:41:36 by yeongo            #+#    #+#              #
#    Updated: 2022/10/04 19:10:33 by yeongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=		so_long
CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror
FRAMEWORK		:=		-framework OpenGL -framework AppKit
RM				:=		rm -rf

LIBFT			:=		./libft/libft.a
LIBFT_DIR		:=		./libft/

LIBMLX			:=		./mlx/libmlx.a
LIBMLX_DIR		:=		./mlx/

HEADER			:=		./include/
SRC_DIR			:=		./src/
OBJ_DIR			:=		./.obj/

SRC_FILES		:=		$(addsuffix .c,				\
						terminate					\
						init						\
						ft_mlx						\
						parse						\
						parse_util					\
						movement					\
						render						\
						so_long)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCLUDE			:=	$(HEADER)
SRC_FOLDER		:=	$(SRC_DIR)
OBJ_FOLDER		:=	$(OBJ_DIR)
OBJS			:=	$(OBJ)
PRINT			:=	SO_LONG

.PHONY	:	all
all		:	$(OBJ_FOLDER) $(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(FRAMEWORK) -o $@ $^
#	@echo "\033[01;32m       SUCCESS!      \033[0m"

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(LIBMLX_DIR) -I$(INCLUDE) -c -o $@ $<

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(LIBFT)	:
	@make -C $(LIBFT_DIR) all

$(LIBMLX)	:
	@make -C $(LIBMLX_DIR) all

.PHONY	:	clean
clean	:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	@$(RM) $(OBJ_DIR)
#	@echo "\033[91m      REMOVE OBJECT      \033[0m"

.PHONY	:	fclean
fclean	:	clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(NAME)
#	@echo "\033[91m      FCLEAN DONE      \033[0m"

.PHONY	:	re
re		:	fclean
	@make all
