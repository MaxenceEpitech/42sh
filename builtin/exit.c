/*
** exit.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel/builtin
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sun Jun 18 15:01:15 2017 JeanBaptiste Melet
** Last update Mon Aug 21 19:22:07 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

int		my_exit(t_info_shell *shell)
{
  my_printf("%s", EXIT);
  free_struct(shell);
  exit(0);
  return (0);
}
