/*
** my_clean_pipes.c for 42sh in /home/loic1.durand/PSU_2016_42sh
** 
** Made by Loïc Durand
** Login   <loic1.durand@epitech.net>
** 
** Started on  Wed Sep 27 14:34:56 2017 Loïc Durand
** Last update Sun Oct  8 17:48:05 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"

char	*add_a_space(char *str, int pos)
{
  char	*new_str;
  int	i;

  i = 0;
  if ((new_str = malloc(sizeof(char)
			* (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (i != pos)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = ' ';
  while (str[i] != 0)
    {
      new_str[i + 1] = str[i];
      i++;
    }
  new_str[i + 1] = 0;
  free(str);
  return (new_str);
}

char	*clean_pipes(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i + 1] != 0)
    {
      if ((str[i] == c && str[i + 1] != c && str[i + 1] != ' '))
	if ((str = add_a_space(str, i + 1)) == NULL)
	  return (NULL);
      if ((i > 0 && str[i] == c && str[i - 1] != c && str[i - 1] != ' '))
	if ((str = add_a_space(str, i)) == NULL)
	  return (NULL);
      i++;
    }
  if ((str[i] == '|' && str[i + 1] == 0))
    if ((str = add_a_space(str, i)) == NULL)
      return (NULL);
  return (str);
}
