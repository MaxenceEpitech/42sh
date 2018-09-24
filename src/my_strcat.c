/*
** my_strcat.c for minishell2 in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_minishell2/src
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Fri Sep  1 19:23:55 2017 jean-baptiste
** Last update Fri Sep  1 19:50:08 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"

char		*my_strcat(char *dest, char *src, int bhv)
{
  size_t	i;
  size_t	j;
  char		*new;

  i = (dest != NULL) ? my_strlen(dest) : 0;
  j = (src != NULL) ? my_strlen(src) : 0;
  if ((new = malloc(sizeof(char) * (i + j + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  if (dest != NULL)
    while (dest[i] != '\0')
      {
        new[i] = dest[i];
        i += 1;
      }
  new[i] = '\0';
  if (src != NULL)
    while (src[j] != '\0')
      new[i++] = src[j++];
  new[i] = '\0';
  if (bhv == 2)
    return (new);
  (bhv == 0) ? (free(dest), free(src)) : (free(dest));
  return (new);
}
