# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 22:58:03 by fbazaz            #+#    #+#              #
#    Updated: 2024/03/29 00:05:17 by aakouhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = mandatory/events.c mandatory/error.c mandatory/initial.c mandatory/julia.c mandatory/main.c mandatory/mandelbrot.c
SRC += utils/ft_putendl_fd.c utils/ft_strcmp.c utils/ft_tolower.c utils/ft_atof.c utils/ft_isdigit.c

SRC_BONUS = bonus/burningship_bonus.c bonus/events_bonus.c bonus/error_bonus.c bonus/initial_bonus.c bonus/julia_bonus.c bonus/main_bonus.c bonus/mandelbrot_bonus.c bonus/tricorn_bonus.c
SRC_BONUS += utils/ft_putendl_fd.c utils/ft_strcmp.c utils/ft_tolower.c utils/ft_atof.c utils/ft_isdigit.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(OBJ_BONUS)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re