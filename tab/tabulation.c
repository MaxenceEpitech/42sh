/*
** tabulation.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_minishell2
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Mon Sep  4 14:54:53 2017 jean-baptiste
** Last update Mon Sep  4 20:26:49 2017 jean-baptiste
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

char		**sort_dir(char *command)
{
  int		i;
  int		j;
  int		size;
  char		**dir;
  char		**new_tab;

  i = 0;
  size = 0;
  j = 0;
  if (((dir = my_ls(".", &size)) == NULL)
      || ((new_tab = malloc(sizeof(char *) * size + 1)) == NULL))
    return (NULL);
  while (dir[i] != NULL)
    {
      if (my_find_str(dir[i], command) == 1)
	new_tab[j++] = my_strdup(dir[i]);
      i += 1;
    }
  new_tab[j] = NULL;
  free_all(NULL, dir);
  return (new_tab);
}

void		tabulation(char *command)
{
  char		**tab;
  int		i;

  i = 0;
  tab = sort_dir(command);
  if (my_tablen(tab) == 1)
    {
      while (command[i] == *tab[i])
	i += 1;
      while (*tab[i] != '\0')
	{
	  write(0, &(*tab[i]), 1);
	  i += 1;
	}
    }
}
