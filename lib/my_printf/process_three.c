/*
** process_three.c for process_three in /home/JB.Melet/Projets/Semestre1/Système_Unix/PSU_2016_my_printf
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Tue Jul 25 12:43:55 2017 JeanBaptiste Melet
** Last update Tue Jul 25 12:47:19 2017 JeanBaptiste Melet
*/

#include "printf.h"

int	is_tab(va_list ap)
{
  char	**value;

  value = va_arg(ap, char **);
  print_tab(value);
  return (0);
}
