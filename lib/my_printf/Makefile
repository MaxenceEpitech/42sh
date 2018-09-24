##
## Makefile for my_printf in /home/JB.Melet/Projets/PSU_2016_my_printf
## 
## Made by JeanBaptiste Melet
## Login   <JB.Melet@epitech.net>
## 
## Started on  Tue Apr  4 10:45:40 2017 JeanBaptiste Melet
## Last update Wed Aug  9 14:15:12 2017 JeanBaptiste Melet
##

AR		=	ar rc

RM		=	rm -f

CFLAGS		+=	-Wall -Wextra -Werror -I ./include/

SRC		=	converter_b.c		\
			converter_o.c		\
			converter_S.c		\
			converter_x.c		\
			my_putchar.c		\
			my_put_nbr.c		\
			my_put_nbr_u.c		\
			my_putstr.c		\
			my_printf.c		\
			printf_tab.c		\
			process.c		\
			process_two.c		\
			process_three.c

NAME		=	libprint.a

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		mv $(NAME) ..

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all

.PHONY:		all clean fclean re
