/*
** my_display_env.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel/builtin
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Fri Jun 16 17:32:37 2017 JeanBaptiste Melet
** Last update Sun Aug 20 13:26:26 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "printf.h"
#include "minishell.h"

extern char	**environ;

int		my_display_env(t_info_shell *shell)
{
  int		i;

  (void)shell;
  i = 0;
  while (environ[i] != NULL)
    {
      my_printf("%s\n", environ[i]);
      i += 1;
    }
  return (0);
}
