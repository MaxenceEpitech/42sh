/*
** my_put_nbr.c for my_put_nbr in /home/JB.Melet/CPool_Day03
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Fri Mar  3 09:32:25 2017 JeanBaptiste Melet
** Last update Sun Apr 16 20:25:25 2017 JeanBaptiste Melet
*/

#include "printf.h"

void		number_display(int nb)
{
  int		digits;
  int		nb2;
  int		exp;

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
      readable(nb, nb2);
      digits = digits - 1;
      nb = nb - nb2 * (nb / nb2);
    }
}

void		readable(int nb, int nb2)
{
  int		readable;

  readable = (nb / nb2) + '0';
  my_putchar(readable);
}

int		my_put_nbr(int nb)
{
  if (nb == 0)
    my_putchar('0');
  else if (nb < 0)
    {
      my_putchar('-');
      number_display(-nb);
    }
  else
    number_display(nb);
  return (0);
}
