/*
** my_ls.c for my_ls in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_tetris
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Tue Jul 18 17:54:01 2017 JeanBaptiste Melet
** Last update Mon Sep  4 15:21:59 2017 jean-baptiste
*/

#include <stdlib.h>
#include <dirent.h>
#include "printf.h"
#include "minishell.h"

int		dir_len(char *path, int nb)
{
  struct dirent *ptr;
  int		i;
  DIR		*dir;

  i = 0;
  if (((dir = opendir(path)) == NULL) || ((ptr = readdir(dir)) == NULL))
    return (84);
  while (ptr != NULL)
    {
      if (nb != 0)
	{
	  if ((ptr->d_name)[0] != '.')
	    i += 1;
	}
      else if (nb == 0)
	i += 1;
      ptr = readdir(dir);
    }
  return (i);
}

char		**my_ls(char *path, int *size)
{
  struct dirent *ptr;
  int		i;
  DIR		*dir;
  char		**tab;
  int		len;

  i = 0;
  if ((len = dir_len(path, 0) + 1) == 84)
    return (NULL);
  *size = len;
  if ((tab = malloc(sizeof(char *) * len + 1)) == NULL)
    return (NULL);
  if (((dir = opendir(path)) == NULL) || ((ptr = readdir(dir)) == NULL))
    return (NULL);
  while (ptr != NULL)
    {
      tab[i++] = my_strdup(ptr->d_name);
      ptr = readdir(dir);
    }
  closedir(dir);
  tab[i] = NULL;
  return (tab);
}
