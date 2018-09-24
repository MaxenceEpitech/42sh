/*
** converteur.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Wed Apr  5 15:54:59 2017 JeanBaptiste Melet
** Last update Sun Apr 16 19:49:26 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "printf.h"

int	my_counts(int nb)
{
  int	i;

  i = 1;
  while (nb / 10 != 0)
    {
      nb = nb / 10;
      i += 1;
    }
  return (i);
}

int	octal(int nb)
{
  int	i;
  int	c;
  char	*oct;

  oct = malloc(sizeof(char) * (my_counts(nb) + 2));
  if (oct == NULL)
    return (84);
  i = 0;
  c = 0;
  while (nb != 0)
    {
      c = nb % 8;
      oct[i] = c + '0';
      i += 1;
      nb = nb / 8;
    }
  oct[i] = '\0';
  while (i >= 0)
    {
      my_putchar(oct[i]);
      i -= 1;
    }
  free(oct);
  return (0);
}
