##
## Makefile for Minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2
## 
## Made by JeanBaptiste Melet
## Login   <JB.Melet@epitech.net>
## 
## Started on  Fri Aug 18 08:26:03 2017 JeanBaptiste Melet
## Last update Sun Oct  8 14:40:14 2017 jean-baptiste
##

NAME		=	42sh

SRC		=	main.c				\
			my_alias/alias.c		\
			my_alias/alias_detection.c	\
			my_alias/create_alias.c		\
			builtin/my_cd.c			\
			builtin/my_display_env.c	\
			builtin/my_setenv.c		\
			builtin/my_unsetenv.c		\
			builtin/exit.c			\
			execution/execute_command.c	\
			execution/execution_in_chain.c	\
			execution/exec.c		\
			execution/find_flags.c		\
			execution/parsing.c		\
			flags/right_redi.c		\
			flags/left_redi.c		\
			flags/pipes.c			\
			flags/double_right_redi.c	\
			flags/and.c			\
			flags/or.c			\
			flags/redi_all.c		\
			historic/history.c		\
			src/find_str.c			\
			src/function.c			\
			src/function_two.c		\
			src/my_epurstr.c		\
			src/my_path.c			\
			src/get_next_line.c		\
			src/my_str_to_wordtab.c		\
			src/my_str_isalpha.c		\
			src/my_strdup.c			\
			src/read_file.c			\
			src/command_verif.c		\
			src/my_strcat.c			\
			src/command_normed.c		\
			tab/tabulation.c		\
			tab/my_ls.c			\
			command_bonus/repeat.c		\
			command_bonus/which.c		\
			command_bonus/where.c		\
			src/my_clean_pipes.c		\
			src/my_magic_quote.c

CFLAGS		+= 	-Wall -Wextra

CPPFLAGS	+=	-I ./include

LIB		=	-L./lib -lprint

LIB2		=	-L./lib -lprint

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -g3

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

my:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB2)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all

.PHONY:		all clean fclean
