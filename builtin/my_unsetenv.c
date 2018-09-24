/*
** my_unsetenv.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel/builtin
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Fri Jun 16 17:32:59 2017 JeanBaptiste Melet
** Last update Mon Oct  2 14:15:57 2017 jean-baptiste
*/

#include <stdlib.h>
#include "printf.h"
#include "minishell.h"

extern char	**environ;

int		check_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if (i == 1)
    {
      my_printf("unsetenv: Too few arguments.\n");
      return (1);
    }
  return (0);
}

int		my_unset_env(t_info_shell *shell)
{
  int		i;

  if (check_tab(shell->tab) == 1)
    return (1);
  i = 1;
  while (shell->tab[i] != NULL)
    {
      if (shell->tab[i] == NULL)
	break ;
      unsetenv(shell->tab[i]);
      i += 1;
    }
  return (0);
}
