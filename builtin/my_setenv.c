/*
** my_setenv.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Jun 15 16:56:37 2017 JeanBaptiste Melet
** Last update Fri Oct  6 16:29:44 2017 jean-baptiste
*/

#include <stdlib.h>
#include "printf.h"
#include "minishell.h"

extern char	**environ;

int		check(t_info_shell *shell)
{
  int		i;

  i = 0;
  if (shell->tab[1] == NULL)
    {
      my_display_env(shell);
      return (0);
    }
  if (verif_first_letter(shell->tab[1]) == 1)
    {
      my_printf("%s%s", SETENV_NAME, SETENV_LETTER);
      return (1);
    }
  if (my_str_isalpha(shell->tab[1]) == 1)
    {
      my_printf("%s %s\n", SETENV_NAME, SETENV_ALPHA);
      return (1);
    }
  while (shell->tab[i++] != NULL)
    if (i > 3)
      {
	my_printf("%s", SETENV_AV);
	return (1);
      }
  return (0);
}

int		my_set_env(t_info_shell *shell)
{
  if (check(shell) == 1)
    {
      shell->exit_value = 1;
      return (1);
    }
  if (shell->tab[2] == NULL)
    {
      if ((shell->tab[2] = malloc(sizeof(char) * 1)) == NULL)
	return (84);
      shell->tab[2][0] = '\0';
    }
  setenv(shell->tab[1], shell->tab[2], 1);
  return (0);
}
