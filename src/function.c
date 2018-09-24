/*
** fonction.c for minishell1 in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Jun 15 11:43:37 2017 JeanBaptiste Melet
** Last update Wed Oct  4 17:20:08 2017 jean-baptiste
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

void		free_all(char *str, char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
  free(str);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while ((s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
    i += 1;
  if (s1[i] != s2[i])
    return (1);
  return (0);
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return (-1);
  while (tab[i] != NULL)
    i += 1;
  return (i);
}
