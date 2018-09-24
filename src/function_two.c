/*
** function_two.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/src
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Aug 12 17:06:01 2017 JeanBaptiste Melet
** Last update Sat Oct  7 15:05:16 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

extern char	**environ;

int		my_count(char *str, char sep)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	j += 1;
      i += 1;
    }
  j = j * 2;
  return (j);
}

int		free_tmp(t_info_shell *shell, char *tmp)
{
  shell->mem = NULL;
  free(tmp);
  return (0);
}

void		init_struct(t_info_shell *shell)
{
  shell->exit_value = 0;
  shell->alias_value = 0;
  if ((shell->historic = malloc(sizeof(char *) * 1)) == NULL)
    return ;
  shell->historic[0] = NULL;
  shell->path_save = get_path(environ, "PATH");
}

void		free_struct(t_info_shell *shell)
{
  free_all(shell->command, shell->tab);
  free_all(shell->mem, shell->tab_mem);
  free_all(shell->path_save, shell->historic);
  free_all(NULL, shell->alias_tab);
}
