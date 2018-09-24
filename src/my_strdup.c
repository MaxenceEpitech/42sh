/*
** my_strdup.c for strdup in /home/JB.Melet/CPool_Day08
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Wed Mar  8 21:18:18 2017 JeanBaptiste Melet
** Last update Wed Jun 21 13:27:49 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "minishell.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*copy;

  i = 0;
  if (src == NULL)
    return (NULL);
  if ((copy = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      copy[i] = src[i];
      i = i + 1;
    }
  copy[i] = '\0';
  return (copy);
}
