/*
** alias.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Aug 19 19:02:42 2017 JeanBaptiste Melet
** Last update Mon Oct  2 14:31:57 2017 jean-baptiste
*/

#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "printf.h"

char		**get_my_alias()
{
  int		i;
  int		j;
  char		*txt;
  char		**alias;
  char		**valid_tab;

  i = 0;
  j = 0;
  txt = my_strdup(MY_ALIAS);
  if ((alias = my_str_to_wordtab(txt, '\n')) == NULL)
    return (NULL);
  if ((valid_tab = malloc(sizeof(char *) * ((my_tablen(alias)) + 1))) == NULL)
    return (NULL);
  while (alias[i] != NULL)
    {
      if ((my_find_str(alias[i], "alias ") == 1))
	valid_tab[j++] = my_strdup(alias[i]);
      i += 1;
    }
  valid_tab[j] = NULL;
  free_all(txt, alias);
  return (valid_tab);
}

char		**cut_alias(char **tab)
{
  int		i;
  int		j;
  char		**alias;
  char		buffer[2];

  if ((alias = malloc(sizeof(char *) * ((my_tablen(tab)) + 1))) == NULL)
    return (NULL);
  i = 0;
  buffer[1] = '\0';
  while (tab[i] != NULL)
    {
      j = 0;
      alias[i] = NULL;
      while (tab[i][j] != ' ')
	j += 1;
      while (tab[i][++j] != '=')
	{
	  buffer[0] = tab[i][j];
	  alias[i] = my_strcat(alias[i], buffer, 1);
	}
      i += 1;
    }
  alias[i] = NULL;
  return (alias);
}

char		**cut_commands(char **tab)
{
  int		i;
  int		j;
  char		**commands;
  char		buffer[2];

  if ((commands = malloc(sizeof(char *) * ((my_tablen(tab)) + 1))) == NULL)
    return (NULL);
  i = 0;
  buffer[1] = '\0';
  while (tab[i] != NULL)
    {
      j = 0;
      commands[i] = NULL;
      while (tab[i][j] != '\'')
	j += 1;
      while (tab[i][++j] != '\'')
	{
	  buffer[0] = tab[i][j];
	  commands[i] = my_strcat(commands[i], buffer, 1);
	}
      i += 1;
    }
  commands[i] = NULL;
  return (commands);
}

char		**create_new_command(char **commands, char **alias,
				     t_info_shell *shell, int size)
{
  t_count	ct;
  char		**new_tab;
  char		**tmp;

  (1 == 1) ? (ct.i = 0, ct.j = 0, ct.k = 0) : 1;
  if ((new_tab= malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (shell->tab[ct.i] != NULL)
    {
      ct.l = -1;
      while (alias[++ct.l] != NULL)
	{
	  if (((my_strcmp(shell->tab[ct.i], alias[ct.l])) == 0) && ++ct.i)
	    {
	      tmp = my_str_to_wordtab(commands[ct.l], ' ');
	      while (tmp[ct.k] != NULL)
		new_tab[ct.j++] = my_strdup(tmp[ct.k++]);
	    }
	}
      new_tab[ct.j++] = my_strdup(shell->tab[ct.i++]);
      if (new_tab[ct.j - 1] == NULL)
	break ;
    }
  (1 == 1) ? (new_tab[ct.j] = NULL, free_all(NULL, tmp)) : 1;
  return (new_tab);
}

int		recognize_my_alias(char **commands,
				   char **alias, t_info_shell *shell)
{
  int		i;
  int		j;
  int		size;

  i = -1;
  size = (my_tablen(shell->tab) + my_tablen(commands)) + 1;
  while (shell->tab[++i] != NULL)
    {
      j = -1;
      while (alias[++j] != NULL)
	{
	  if ((my_strcmp(shell->tab[i], alias[j])) == 0)
	    {
	      if (my_tablen(shell->tab) != 1)
		shell->tab = create_new_command(commands, alias, shell, size);
	      else
		{
		  free_all(NULL, shell->tab);
		  shell->tab = my_str_to_wordtab(commands[j], ' ');
		}
	      return (0);
	    }
	}
    }
  return (1);
}
