/*
** my_cd.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Jun 15 17:28:38 2017 JeanBaptiste Melet
** Last update Wed Aug 23 16:56:51 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int		search_path(char **my_env, char *key)
{
  t_count	ct;
  char		*mem;

  ct.i = 0;
  while (my_env[ct.i] != NULL)
    {
      ct.j = 0;
      ct.k = 0;
      if ((mem = malloc(sizeof(char) * my_strlen(my_env[ct.i]))) == NULL)
	return (84);
      while (my_env[ct.i][ct.j] != '=')
	{
	  mem[ct.k++] = my_env[ct.i][ct.j++];
	}
      mem[ct.k] = '\0';
      if (my_strcmp(mem, key) == 0)
	{
	  free(mem);
	  return (ct.i);
	}
      free(mem);
      ct.i += 1;
    }
  return (84);
}

char		*get_path(char **my_env, char *key)
{
  int		i;
  int		j;
  int		k;
  char		*tmp;

  i = search_path(my_env, key);
  if (i == 84)
    return (NULL);
  j = 0;
  k = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(my_env[i] + 1))) == NULL)
    return (NULL);
  while (my_env[i][j - 1] != '=')
    j += 1;
  while (my_env[i][j] != '\0')
    {
      tmp[k++] = my_env[i][j++];
    }
  tmp[k] = '\0';
  return (tmp);
}
