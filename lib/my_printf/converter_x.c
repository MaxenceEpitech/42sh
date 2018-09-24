/*
** converteur.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Wed Apr  5 15:54:59 2017 JeanBaptiste Melet
** Last update Tue Jul 25 12:43:10 2017 JeanBaptiste Melet
*/

#include "printf.h"

void		convert(long int nb)
{
  long int	a;
  long int	c;
  long int	nb2;
  long int	l;

  nb2 = nb;
  a = 16;
  if (nb < 16)
    {
      l = nb;
      display(l);
    }
  l = 0;
  while (nb >= a)
    {
      c = a;
      a = a * 16;
    }
  while (c >= 1)
    {
      l = nb2 / c;
      display(l);
      nb2 = nb2 - (l * c);
      c = c / 16;
    }
}

void		convert_two(long int nb)
{
  long int	a;
  long int	c;
  long int	nb2;
  long int	l;

  nb2 = nb;
  a = 16;
  if (nb < 16)
    {
      l = nb;
      display_two(l);
    }
  l = 0;
  while (nb >= a)
    {
      c = a;
      a = a * 16;
    }
  while (c >= 1)
    {
      l = nb2 / c;
      display_two(l);
      nb2 = nb2 - (l * c);
      c = c / 16;
    }
}

void		display(long int l)
{
  if (l == 10)
    my_putchar('a');
  else if (l == 11)
    my_putchar('b');
  else if (l == 12)
    my_putchar('c');
  else if (l == 13)
    my_putchar('d');
  else if (l == 14)
    my_putchar('e');
  else if (l == 15)
    my_putchar('f');
  else
    my_put_nbr(l);
}

void		display_two(long int l)
{
  if (l == 10)
    my_putchar('A');
  else if (l == 11)
    my_putchar('B');
  else if (l == 12)
    my_putchar('C');
  else if (l == 13)
    my_putchar('D');
  else if (l == 14)
    my_putchar('E');
  else if (l == 15)
    my_putchar('F');
  else
    my_put_nbr(l);
}
