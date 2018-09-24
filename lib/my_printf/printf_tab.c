/*
** printf_tab.c for printf in /home/JB.Melet/Projets/Semestre1/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Tue Jul 25 12:38:16 2017 JeanBaptiste Melet
** Last update Sat Aug 19 17:38:12 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "printf.h"

void		print_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab[i] != NULL)
    {
      while (tab[i] != NULL)
	{
	  my_printf("%s\n", tab[i]);
	  i += 1;
	}
    }
}
