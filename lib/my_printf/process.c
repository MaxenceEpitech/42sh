/*
** transformations.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Apr  8 10:14:26 2017 JeanBaptiste Melet
** Last update Sun Apr 16 20:34:01 2017 JeanBaptiste Melet
*/

#include <unistd.h>
#include <stdarg.h>
#include "printf.h"

int	is_int(va_list ap)
{
  int	value;

  value = va_arg(ap, int);
  my_put_nbr(value);
  return (0);
}

int	is_star_char(va_list ap)
{
  char	*value;

  value = va_arg(ap, char *);
  if (value == NULL)
    my_putstr("(null)");
  else
    my_putstr(value);
  return (0);
}

int	is_char(va_list ap)
{
  int	value;

  value = va_arg(ap, int);
  my_putchar(value);
  return (0);
}

int	hex_x(va_list ap)
{
  int	value;

  value = va_arg(ap, unsigned long int);
  convert(value);
  return (0);
}

int	hex_upcasex(va_list ap)
{
  int	value;

  value = va_arg(ap, unsigned long int);
  convert_two(value);
  return (0);
}
