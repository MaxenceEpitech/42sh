/*
** get_next_line.c for matchstick in /home/JB.Melet/Projets/Semestre2/C-Prog-Elem/CPE_2016_matchstick
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Mon Jul 10 19:24:00 2017 JeanBaptiste Melet
** Last update Thu Sep  7 15:27:49 2017 jean-baptiste
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/minishell.h"

static int	my_str_contain(char *str, char rep)
{
  size_t	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      {
	if (str[i] == rep)
	  return (i);
	i += 1;
      }
  return (-1);
}

static char		*get_line(char *line, char **mem)
{
  char			*tmp;

  if (line[0] == '\0')
    return (NULL);
  if (*mem != NULL)
    {
      if ((line = my_strcat(*mem, line, 0)) == NULL)
  	return (NULL);
      *mem = NULL;
    }
  line[my_str_contain(line, '\n')] = '\0';
  tmp = line + my_strlen(line) + 1;
  if (my_strlen(tmp) == 0)
    tmp = NULL;
  if ((*mem = my_strcat(NULL, tmp, 2)) == NULL)
    return (NULL);
  return (line);
}

char		*get_next_line(const int fd)
{
  static int	size = 1;
  static char	*mem = NULL;
  char		buff[READ_SIZE + 1];
  char		*line;

  line = NULL;
  while (size != 0 && my_str_contain(line, '\n') == -1)
    {
      if ((size = read(fd, buff, READ_SIZE)) == -1)
	return (NULL);
      buff[size] = '\0';
      if ((line = my_strcat(line, buff, 1)) == NULL)
	return (NULL);
    }
  if ((line = get_line(line, &mem)) == NULL)
    return (NULL);
  if (my_strlen(line) == 0 && size == 0)
    return (NULL);
  return (line);
}
