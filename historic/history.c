/*
** history.c for 42sh in /home/loic1.durand/PSU_2016_42sh
** 
** Made by Loïc Durand
** Login   <loic1.durand@epitech.net>
** 
** Started on  Tue Sep  5 16:04:25 2017 Loïc Durand
** Last update Sun Oct  8 15:41:01 2017 jean-baptiste
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "printf.h"

char	**history_add(char **old_h, char *line)
{
  char	**new_h;
  int	i;

  if ((new_h = malloc(sizeof(char *) * (my_tablen(old_h) + 2))) == NULL)
    return (NULL);
  new_h[0] = my_strdup(line);
  i = 0;
  while (old_h[i] != NULL)
    {
      new_h[i + 1] = old_h[i];
      i += 1;
    }
  new_h[i + 1] = NULL;
  if (*old_h != NULL)
    free(old_h);
  return (new_h);
}

int	print_historic(t_info_shell *shell)
{
  shell->historic = reverse_tab(shell->historic);
  my_printf("%t", shell->historic);
  shell->historic = reverse_tab(shell->historic);
  return (0);
}
