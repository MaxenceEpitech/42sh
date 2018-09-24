/*
** transformationsV2.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Apr  8 11:28:00 2017 JeanBaptiste Melet
** Last update Sun Apr 16 20:35:06 2017 JeanBaptiste Melet
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int	is_octal(va_list ap)
{
  int	value;

  value = va_arg(ap, int);
  octal(value);
  return (0);
}

int	is_pointeur(va_list ap)
{
  int	value;

  value = va_arg(ap, unsigned long int);
  if (value == 0)
    my_putstr("(nil)");
  else
    {
      my_putstr("0x");
      convert(value);
    }
  return (0);
}

int	is_unsigned_long(va_list ap)
{
  long	value;

  value = va_arg(ap, long);
  my_put_nbr_long(value);
  return (0);
}

int	is_binary(va_list ap)
{
  int	value;

  value = va_arg(ap, int);
  binary(value);
  return (0);
}

int	is_octal_s(va_list ap)
{
  char	*value;

  value = va_arg(ap, char *);
  if (value == NULL)
    my_putstr("(null)");
  else
    modulo_upcases(value);
  return (0);
}
