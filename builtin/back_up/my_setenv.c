/*
** my_setenv.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Jun 15 16:56:37 2017 JeanBaptiste Melet
** Last update Mon Oct  2 14:16:37 2017 jean-baptiste
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
      return (1);
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

char		**copy(char **environ, int *i)
{
  char		**new_env;

  *i = 0;
  if ((new_env = malloc(sizeof(char *) * ((my_tablen(environ)) + 2))) == NULL)
    return (NULL);
  while (environ[*i] != NULL)
    {
      if ((new_env[*i] = malloc(sizeof(char) * my_strlen(environ[*i]))) == NULL)
	return (NULL);
      new_env[*i] = environ[*i];
      *i += 1;
    }
  new_env[*i] = NULL;
  return (new_env);
}

char		**new_env(char **tab, char **environ)
{
  int		i;
  char		**new_env;

  new_env = copy(environ, &i);
  if (tab[2] != NULL)
    {
      new_env[i] = my_strdup(tab[1]);
      new_env[i] = my_strcat(new_env[i], "=", 2);
      new_env[i] = my_strcat(new_env[i], tab[2], 2);
      new_env[i] = my_strcat(new_env[i], "\0", 2);
      new_env[i + 1] = NULL;
      return (new_env);
    }
  else if (tab[2] == NULL)
    {
      new_env[i] = my_strdup(tab[1]);
      new_env[i] = my_strcat(new_env[i], "=", 2);
      new_env[i] = my_strcat(new_env[i], "\0", 2);
      new_env[i + 1] = NULL;
      return (new_env);
    }
  return (new_env);
}

char		**change_env(char **tab, char **environ, int index)
{
  int		i;
  int		j;
  char		**new_env;

  i = 0;
  j = 0;
  if ((new_env = malloc(sizeof(char *) * ((my_tablen(environ)) + 1))) == NULL)
    return (NULL);
  while (environ[i] != NULL)
    {
      if ((new_env[i] = malloc(sizeof(char) * my_strlen(environ[i]))) == NULL)
	return (NULL);
      new_env[i] = environ[i];
      i += 1;
    }
  new_env[i + 1] = NULL;
  while (new_env[index][j - 1] != '=')
    j += 1;
  new_env[index][j] = '\0';
  if (tab[2] == NULL)
    return (new_env);
  else if (tab[2] != NULL)
    new_env[index] = my_strcat(new_env[index], tab[2], 2);
  return (new_env);
}

int		my_set_env(t_info_shell *shell)
{
  int		i;

  if (check(shell) == 1)
    {
      shell->exit_value = 1;
      return (1);
    }
  if ((i = search_path(environ, shell->tab[1])) == 84)
    {
      if ((environ = new_env(shell->tab, environ)) == NULL)
	return (84);
      return (0);
    }
  if ((environ = change_env(shell->tab, environ, i)) == NULL)
    return (84);
  return (0);
}
