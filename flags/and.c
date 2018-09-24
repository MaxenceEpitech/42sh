/*
** and.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_minishell2/flags
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Tue Sep  5 11:29:37 2017 jean-baptiste
** Last update Thu Sep  7 17:20:10 2017 jean-baptiste
*/

#include "stdlib.h"
#include "minishell.h"
#include "printf.h"

char		**copy_my_tab(char **tab)
{
  int		i;
  char		**new;

  i = 0;
  if ((new = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      new[i] = my_strdup(tab[i]);
      i += 1;
    }
  new[i] = NULL;
  return (new);
}

char		**reverse_tab(char **tab)
{
  int		i;
  int		j;
  char		*tmp;

  i = 0;
  j = 0;
  while (tab[j] != NULL)
    j += 1;
  j -= 1;
  while (i <= j)
    {
      tmp = my_strdup(tab[i]);
      tab[i] = my_strdup(tab[j]);
      tab[j] = my_strdup(tmp);
      i += 1;
      j -= 1;
    }
  free(tmp);
  return (tab);
}

static char	**cut_mem(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  i -= 1;
  while ((my_strcmp(tab[i], "&&") != 0) && (i != 0))
    {
      free(tab[i]);
      i -= 1;
    }
  tab[i] = NULL;
  return (tab);
}

static char	**cut(char **tab, char ***mem)
{
  int		i;
  char		**new;

  i = 0;
  if ((new = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (my_strcmp(tab[i], "&&") != 0)
    {
      new[i] = my_strdup(tab[i]);
      i += 1;
    }
  new[i] = NULL;
  *mem = reverse_tab(*mem);
  *mem = cut_mem(*mem);
  if (my_tablen(*mem) != 1)
    *mem = reverse_tab(*mem);
  return (new);
}

int		and(t_info_shell *shell)
{
  char		**mem;
  int		mark;

  mark = 0;
  shell->flags_value = 1;
  mem = copy_my_tab(shell->tab);
  while (1)
    {
      if (my_tablen(shell->tab) != 1)
	shell->tab = cut(shell->tab, &mem);
      execute_command(shell);
      if ((shell->exit_value == 1) || (mark == 1))
	break ;
      shell->tab = mem;
      if (my_tablen(mem) == 1)
	mark = 1;
    }
  free_all(NULL, mem);
  return (0);
}
