/*
** read_file.c for read_file.c in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/src
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Fri Aug 18 08:51:31 2017 JeanBaptiste Melet
** Last update Mon Sep  4 13:55:33 2017 jean-baptiste
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minishell.h"
#include "printf.h"

char		*read_file(char *path)
{
  char		*my_file;
  int		fd;
  char		buffer[2];

  buffer[1] = '\0';
  my_file = NULL;
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_printf("%s: %s", path, NO_SUCH_FILE);
      return (NULL);
    }
  while (read(fd, buffer, 1) != 0)
    my_file = my_strcat(my_file, buffer, 1);
  close(fd);
  return (my_file);
}
