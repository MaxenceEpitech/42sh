/*
** new_printf.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Fri Apr  7 22:19:20 2017 JeanBaptiste Melet
** Last update Wed Aug  9 14:55:07 2017 JeanBaptiste Melet
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

t_flags		g_flags[NB_FLAG] =
  {
    {'s', is_star_char},
    {'d', is_int},
    {'i', is_int},
    {'c', is_char},
    {'x', hex_x},
    {'X', hex_upcasex},
    {'o', is_octal},
    {'p', is_pointeur},
    {'u', is_unsigned_long},
    {'%', put_modulo},
    {'b', is_binary},
    {'S', is_octal_s},
    {'t', is_tab}
  };

int		process(int i, int j, int k, const char *str1)
{
  if (j == 13)
    {
      my_putchar('%');
      if (k == 1)
	my_putchar(' ');
      my_putchar(str1[i + 1]);
    }
  return (0);
}

int		core(const char *str1, va_list ap, int i)
{
  int		j;
  int		k;

  j = -1;
  while (++j < NB_FLAG)
    {
      while ((str1[i + 1] == ' ') || (str1[i + 1] == '\t'))
	{
	  k = 1;
	  i += 1;
	  if ((str1[i + 1] == 'd') || (str1[i + 1] == 'i') ||
	      (str1[i + 1] == 'p'))
	    my_putchar(' ');
	}
      if (str1[i + 1] == g_flags[j].code)
	{
	  g_flags[j].fc(ap);
	  break ;
	}
    }
  process(i, j, k, str1);
  return (i);
}

void		my_printf(const char *str1, ...)
{
  va_list	ap;
  int		i;

  i = -1;
  va_start(ap, str1);
  if (str1 == NULL)
    return ;
  while (str1[++i] != '\0')
    {
      if (str1[i] == '%' && str1[i + 1] != '\0')
	{
	  i = core(str1, ap, i);
	  i += 1;
	}
      else
	my_putchar(str1[i]);
    }
  va_end(ap);
}
