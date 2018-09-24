/*
** converteur.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Wed Apr  5 15:54:59 2017 JeanBaptiste Melet
** Last update Fri Apr 14 12:32:46 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "printf.h"

int	my_counts_digits(long int nb)
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

int	binary(long int nb)
{
  int	i;
  int	c;
  char	*binary;

  binary = malloc(sizeof(char) * 32);
  if (binary == NULL)
    return (84);
  i = 0;
  c = 0;
  while (nb != 0)
    {
      c = nb % 2;
      binary[i] = c + '0';
      i = i + 1;
      nb = nb / 2;
    }
  binary[i] = '\0';
  while (i >= 0)
    {
      my_putchar(binary[i]);
      i = i - 1;
    }
  free(binary);
  return (0);
}
