# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho <hcho@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 22:15:05 by hcho              #+#    #+#              #
#    Updated: 2020/12/04 22:22:08 by hcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = rush-02
SOURCES = main.c
OBJECTS = main.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: 
	clean 
	rm -f $(TARGET)

re: 
	fclean all
