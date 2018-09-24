/*
** my_put_nbr.c for my_put_nbr in /home/JB.Melet/CPool_Day03
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Fri Mar  3 09:32:25 2017 JeanBaptiste Melet
** Last update Sun Apr 16 20:29:56 2017 JeanBaptiste Melet
*/

#include "printf.h"

void		number_display_long(long nb)
{
  long		digits;
  long		nb2;
  long		exp;

  nb2 = nb;
  digits = 0;
  while (nb2 != 0)
    {
      digits = digits + 1;
      nb2 = nb2 / 10;
    }
  while (digits != 0)
    {
      exp = digits - 1;
      nb2 = 1;
      while (exp != 0)
	{
	  nb2 = nb2 * 10;
	  exp = exp - 1;
	}
      long_readable(nb, nb2);
      digits = digits - 1;
      nb = nb - nb2 * (nb / nb2);
    }
}

void		long_readable(long nb, long nb2)
{
  long		readable;

  readable = (nb / nb2) + '0';
  my_putchar(readable);
}

void		my_put_nbr_long(long nb)
{
  if (nb == 0)
    my_putchar('0');
  else if (nb < 0)
    {
      my_putchar('-');
      number_display_long(-nb);
    }
  else
    number_display_long(nb);
}
