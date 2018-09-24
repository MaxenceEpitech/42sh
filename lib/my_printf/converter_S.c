/*
** converteur-S.c for my_printf in /home/JB.Melet/Projets/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Apr  8 13:15:19 2017 JeanBaptiste Melet
** Last update Sun Apr 16 19:49:44 2017 JeanBaptiste Melet
*/

#include <unistd.h>
#include "printf.h"

int	modulo_upcases(char *str)
{
  while (*str)
    {
      if ((*str >= 32 && *str < 127))
	my_putchar(*str);
      else
	{
	  if (*str < 8)
	    my_putstr("\\00");
	  else if (*str < 64)
	    my_putstr("\\0");
	  else
	    my_putstr("\\");
	  octal(*str);
	}
      str += 1;
    }
  return (0);
}
