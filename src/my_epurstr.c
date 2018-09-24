/*
** my_epurstr.c for my_epurstr in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Aug 10 17:28:15 2017 JeanBaptiste Melet
** Last update Sat Aug 19 17:01:50 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "minishell.h"

char	*little_verif(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    i += 1;
  if (str[i - 1] == ';')
    str[i - 1] = '\0';
  return (str);
}

char	*my_epurstr(char *str)
{
  int	i;
  int	x;
  char	*str2;

  i = 0;
  x = 0;
  if ((str == NULL)
      || ((str2 = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL))
    return (NULL);
  while (str[i] != '\0')
    {
      while (((str[i] == ' ' || str[i] == '\t') &&
	      (str[i + 1] == ' ' || str[i + 1] == '\t')))
	i++;
      if (str[i] == '\t')
	str[i] = ' ';
      str2[x++] = str[i++];
    }
  str2[x] = '\0';
  if (str2[x - 1] == ' ' || str2[x - 1] == '\t')
    str2[x - 1] = '\0';
  if ((*str2 == ' ' || *str2 == '\t'))
    str2++;
  free(str);
  return (str2);
}
