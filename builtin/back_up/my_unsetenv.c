/*
** my_unsetenv.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel/builtin
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Fri Jun 16 17:32:59 2017 JeanBaptiste Melet
** Last update Mon Oct  2 14:16:55 2017 jean-baptiste
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

char		**delete_env(char *tab, char **environ)
{
  int		i;
  int		j;
  int		index;
  char		**new_env;

  i = 0;
  j = 0;
  if ((index = search_path(environ, tab)) == 84)
    return (NULL);
  if ((new_env = malloc(sizeof(char *) * (my_tablen(environ) + 1))) == NULL)
    return (NULL);
  while (environ[j] != NULL)
    {
      if (j == index)
	j += 1;
      if ((new_env[i] = my_strdup(environ[j])) == NULL)
	break ;
      i += 1;
      j += 1;
    }
  new_env[i + 1] = NULL;
  return (new_env);
}

int		my_unset_env(t_info_shell *shell)
{
  int		i;
  char		**save;

  if (check_tab(shell->tab) == 1)
    return (1);
  i = 1;
  while (shell->tab[i] != NULL)
    {
      if (shell->tab[i] == NULL)
	break ;
      save = environ;
      if ((environ = delete_env(shell->tab[i], environ)) == NULL)
	environ = save;
      i += 1;
    }
  return (0);
}
