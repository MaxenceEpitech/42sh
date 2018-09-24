/*
** my_cd.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Jun 15 17:28:38 2017 JeanBaptiste Melet
** Last update Wed Aug 23 18:11:02 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "printf.h"
#include "minishell.h"

extern char	**environ;

int		cd_point(t_info_shell *shell)
{
  (void)shell;
  if ((chdir("..")) == -1)
    return (84);
  return (0);
}

int		cd_check(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if (i > 2)
    {
      my_printf("%s", CD_AV);
      return (1);
    }
  return (0);
}

int		cd_minus(char *path, char **dir, char **save)
{
  if ((my_strcmp(path, "-") == 0))
    {
      if (*dir != NULL)
	{
	  *save = getcwd((char *)NULL, 0);
	  chdir(*dir);
	}
      else
	my_printf("%s", CD_DIR);
      *dir = *save;
      return (0);
    }
  return (1);
}

int		my_cd(t_info_shell *shell)
{
  char		*path;
  static char	*dir = NULL;
  static char	*save = NULL;

  if (cd_check(shell->tab) == 1)
    return (0);
  if (shell->tab[1] == NULL)
    path = get_path(environ, "HOME");
  else
    path = shell->tab[1];
  if ((cd_minus(path, &dir, &save)) == 0)
    return (0);
  dir = getcwd((char *)NULL, 0);
  if ((chdir(path)) == -1)
    {
      shell->exit_value = 1;
      my_printf("%s: %s.\n", path, strerror(errno));
      return (84);
    }
  free(path);
  return (0);
}
