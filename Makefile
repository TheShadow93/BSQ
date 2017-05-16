##
## Makefile for  in /home/sumeet.singh/delivery/CPE_2016_BSQ
## 
## Made by Sumeet Singh
## Login   <sumeet.singh@epitech.net>
## 
## Started on  Wed Dec 14 19:04:30 2016 Sumeet Singh
## Last update Sat Dec 17 00:07:15 2016 Sumeet Singh
##

NAME	= bsq

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -ansi -pedantic

SRCS	= main.c \
	  ./my_files/my_tools.c \
	  ./my_files/my_get_nbr.c \
	  ./my_files/my_parse.c \
	  ./my_files/my_next_line.c \
	  ./my_files/my_algorithm.c \
	  ./my_files/my_getting_pos.c \
	  ./my_files/my_error_manager.c

OBJ   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re
