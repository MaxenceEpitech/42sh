/*
** execute_command.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Fri Jun 16 14:22:31 2017 JeanBaptiste Melet
** Last update Thu Oct  5 14:34:54 2017 jean-baptiste
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

extern char	**environ;

char		*core_exec(t_info_shell *shell, char *env_path,
			   char *valid_path, char **paths)
{
  int		i;

  i = 0;
  while (paths[i] != NULL)
    {
      if ((paths[i] = my_strcat(paths[i], "/", 1)) == NULL
	  || (shell->tab[0] != NULL
	      && (paths[i] = my_strcat(paths[i], shell->tab[0], 1)) == NULL))
	return (NULL);
      if (shell->tab[0] != NULL && access(shell->tab[0], X_OK) != -1)
	{
	  valid_path = my_strcat(shell->tab[0], NULL, 2);
	  free_all(env_path, paths);
	  return (valid_path);
	}
      if (shell->tab[0] != NULL && access(paths[i], X_OK) != -1)
	{
	  valid_path = my_strcat(paths[i], NULL, 2);
	  free_all(env_path, paths);
	  return (valid_path);
	}
      i += 1;
    }
  return (NULL);
}

char		*is_valid_command(t_info_shell *shell)
{
  char		*without_path;
  char		*env_path;
  char		*valid_path;
  char		**paths;
  char		*output;

  if ((env_path = get_path(environ, "PATH")) == NULL)
    env_path = shell->path_save;
  if ((paths = my_str_to_wordtab(env_path, ':')) == NULL)
    {
      without_path = my_strcat(PATH, PATH_TWO, 2);
      without_path = my_strcat(without_path, PATH_THREE, 2);
      paths = my_str_to_wordtab(without_path, ':');
    }
  valid_path = NULL;
  if ((output = core_exec(shell, env_path, valid_path, paths)) != NULL)
    return (output);
  free_all(env_path, paths);
  return (NULL);
}

static t_builtin	g_key[11]=
  {
    {"cd", my_cd},
    {"env", my_display_env},
    {"setenv", my_set_env},
    {"unsetenv", my_unset_env},
    {"exit", my_exit},
    {"..", cd_point},
    {"history", print_historic},
    {"alias", create_my_alias},
    {"repeat", repeat},
    {"which", which},
    {"where", where}
  };

int		execute_command(t_info_shell *shell)
{
  int		i;
  char		*valid_path;

  i = 0;
  while (i < 11)
    {
      if (my_strcmp(shell->tab[0], g_key[i].code) == 0)
	{
	  g_key[i].fc(shell);
	  return (shell->exit_value);
	}
      i += 1;
    }
  valid_path = is_valid_command(shell);
  shell->exit_value = exec(shell, valid_path);
  return (shell->exit_value);
}
