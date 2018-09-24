/*
** command_normed.c for minishell2 in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_minishell2/src
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Sun Sep  3 21:19:30 2017 jean-baptiste
** Last update Sun Oct  8 17:49:01 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"

char		*command_normed(char *command, char sep)
{
  int		i;
  int		j;
  char		*str;

  if ((str = malloc(sizeof(char) * my_strlen(command)
                    + my_count(command, sep) + 1)) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (command[++i] != '\0')
    {
      if ((command[i] == sep) && i != 0 &&(command[i - 1] != ' '))
        str[j++] = ' ';
      str[j] = command[i];
      if ((command[i] == sep) && (command[i + 1] != ' ') && command[i + 1] != 0)
        str[j++ + 1] = ' ';
      j += 1;
    }
  str[j] = '\0';
  if ((str = clean_pipes(str, '|')) == NULL)
    return (NULL);
  if ((str = clean_pipes(str, '&')) == NULL)
    return (NULL);
  return (str);
}
