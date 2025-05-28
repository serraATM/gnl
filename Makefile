# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tu_nombre <tu_email@ejemplo.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 00:00:00 by tu_nombre          #+#    #+#              #
#    Updated: 2025/05/28 00:00:00 by tu_nombre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
BUFFER = -D BUFFER_SIZE=42

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
HEADER = get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(BUFFER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all