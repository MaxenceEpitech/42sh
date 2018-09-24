/*
** parsing.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_42sh/execution
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Wed Oct  4 15:53:14 2017 jean-baptiste
** Last update Sun Oct  8 18:04:51 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

char		**parsing_or_and(t_info_shell *shell, int *loop)
{
  int		i;
  int		j;
  char		**mem;
  char		**tmp;

  (1 == 1) ? (i = -1, j = -1) : 1;
  if (((mem = malloc(sizeof(char *) * my_tablen(shell->tab))) == NULL)
      || ((tmp = malloc(sizeof(char *) * my_tablen(shell->tab))) == NULL))
    return (NULL);
  while ((my_strcmp(shell->tab[++i], "&&") != 0)
         && (my_strcmp(shell->tab[i], "||") != 0))
    {
      if (shell->tab[i] == NULL)
	{
          *loop = 0;
          return (mem);
        }
      tmp[i] = my_strdup(shell->tab[i]);
    }
  tmp[i] = NULL;
  while (shell->tab[i] != NULL)
    mem[++j] = my_strdup(shell->tab[++i]);
  mem[j] = NULL;
  shell->tab = tmp;
  return (mem);
}

void		marck_init(t_info_shell *shell, int *marck)
{
  int           i;

  i = 0;
  while (shell->tab[i] != NULL)
    {
      if (my_strcmp(shell->tab[i], "&&") == 0)
	{
          *marck = AND;
          break ;
	}
      if (my_strcmp(shell->tab[i], "||") == 0)
	{
          *marck = OR;
          break ;
	}
      i += 1;
    }
}

int		detect_or_and(t_info_shell *shell, int marck)
{
  if (marck == AND)
    if (shell->exit_value == 1)
      return (1);
  if (marck == OR)
    if (shell->exit_value == 0)
      return (1);
  return (0);
}

int		parsing(t_info_shell *shell)
{
  char		**save;
  int		marck;
  int		loop;

  if (my_tablen(shell->tab) != 0)
    {
      marck = -1;
      loop = -1;
      while (loop != 0)
	{
	  marck_init(shell, &marck);
	  if (((save = parsing_or_and(shell, &loop)) == NULL)
	      || ((find_flags(shell)) == 84))
	    return (84);
	  if ((shell->flags_value == 0) && (shell->tab[0] != NULL))
	    execute_command(shell);
	  if (detect_or_and(shell, marck) == 1)
	    break ;
	  shell->tab = save;
	  shell->flags_value = 0;
	}
    }
  return (shell->exit_value);
}
