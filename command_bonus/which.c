/*
** which.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_42sh/command_bonus
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Mon Sep 25 16:05:43 2017 jean-baptiste
** Last update Mon Sep 25 17:58:56 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

static char	**cut_my_tab(t_info_shell *shell)
{
  char		**new_tab;
  int		i;
  int		j;

  if ((new_tab = malloc(sizeof(char *)
			* my_tablen(shell->tab) + 1)) == NULL)
    return (NULL);
  i = 1;
  if (shell->tab[i] == NULL)
    return (NULL);
  j = 0;
  while (shell->tab[i] != NULL)
    {
      new_tab[j] = my_strdup(shell->tab[i]);
      j += 1;
      i += 1;
    }
  new_tab[j] = NULL;
  return (new_tab);
}

int		which_verif(t_info_shell *shell)
{
  if (my_tablen(shell->tab) == 1)
    {
      shell->exit_value = 1;
      my_printf("which: Too few arguments.\n");
      return (84);
    }
  return (0);
}

static t_builtin	g_key[10]=
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
    {"which", which}
  };

void		verif_path(t_info_shell *shell, int ptr)
{
  char		*path;

  if (my_strcmp(shell->tab[0], "echo") == 0)
    {
      my_printf("echo: shell built-in command.\n");
      ptr = 1;
    }
  if (ptr == 0)
    {
      if ((path = is_valid_command(shell)) != NULL)
	my_printf("%s\n", path);
      else
	{
	  my_printf("%s: %s", shell->tab[0], COMMAND_ERROR);
	  shell->exit_value = 1;
	}
    }
  ptr = 0;
}

int		which(t_info_shell *shell)
{
  int		i;
  int		ptr;

  ptr = 0;
  if ((which_verif(shell)) != 0)
    return (84);
  while (1)
    {
      i = 0;
      if ((shell->tab = cut_my_tab(shell)) == NULL)
	break ;
      while (i < 10)
	{
	  if (my_strcmp(shell->tab[0], g_key[i].code) == 0)
	    {
	      my_printf("%s: shell built-in comand.\n", g_key[i].code);
	      ptr = 1;
	    }
	  i += 1;
	}
      verif_path(shell, ptr);
    }
  return (0);
}
