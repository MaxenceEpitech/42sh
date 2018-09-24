/*
** printf.h for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf/include
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Tue Apr  4 14:51:59 2017 JeanBaptiste Melet
** Last update Wed Aug  9 17:30:09 2017 JeanBaptiste Melet
*/

#ifndef PRINTF_H_
# define PRINTF_H_

# include <stdarg.h>

# define NB_FLAG 13

typedef struct	s_flags
{
  int		code;
  int		(*fc)(va_list);
}		t_flags;

void		my_putchar(char);
int		my_put_nbr(int);
int		my_putstr(char *);

void		my_printf(const char *,  ...);
void		display(long int);
void		convert(long int);
void		convert_two(long int);
void		display_two(long int);
int		octal(int);
void		number_display_long(long);
void		my_put_nbr_long(long);
void		readable(int, int);
void		long_readable(long, long);
int		binary(long int);
int		modulo_upcases(char *);
void		print_tab(char **);

int		is_int(va_list);
int		is_star_char(va_list);
int		is_char(va_list);
int		hex_x(va_list);
int		hex_upcasex(va_list);
int		is_octal(va_list);
int		is_pointeur(va_list);
int		is_unsigned_long(va_list);
int		is_binary(va_list);
int		is_octal_s(va_list);
int		put_modulo(va_list);
int		is_tab(va_list);

#endif /* !PRINTF_H_ */
