# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 15:04:38 by areheman          #+#    #+#              #
#    Updated: 2022/06/02 15:17:36 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c gt_next_line/get_next_line.c gt_next_line/get_next_line_utils.c checkfile.c put_win.c action.c so_long_utils.c animation.c

OBJS = $(SRC:.c=.o)

%.o : %.c
		@$(GCC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
		@make all -C printf
		@$(GCC)  $(MLX) printf/libftprintf.a -o $@ $^

clean :
		@make clean -C printf/
#		@make clean -C mlx #
		@rm -rf $(OBJS)

fclean : clean
		@make fclean -C printf
#		@make fclean -C mlx#
		@rm -rf $(NAME)

re : clean fclean all 

.PHONEY : clean fclean re all 
