/*
** my_putstr.c for my_putstr in /home/JB.Melet/CPool_Day04
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Thu Mar  2 09:36:28 2017 JeanBaptiste Melet
** Last update Sun Apr 16 20:30:32 2017 JeanBaptiste Melet
*/

#include "printf.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
