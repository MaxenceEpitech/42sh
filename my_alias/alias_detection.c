/*
** alias_detection.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/alias
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sun Aug 20 11:29:05 2017 JeanBaptiste Melet
** Last update Wed Oct  4 17:44:13 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

int		create_my_alias(t_info_shell *shell)
{
  char		*new_alias;

  if (alias_check(shell) == 0)
    {
      new_alias = create_valid_alias(shell->tab);
      if (shell->alias_value == 0)
	shell->alias_tab = add_new_alias(shell->alias_tab, new_alias);
      shell->alias_value = 0;
    }
  return (0);
}

int		replace_existing_alias(char *new_alias, t_info_shell *shell)
{
  char		**alias;
  int		i;

  i = 0;
  alias = cut_alias(shell->alias_tab);
  while (alias[i] != NULL)
    {
      if (my_strcmp(alias[i], new_alias) == 0)
	{
	  shell->alias_tab[i] = my_strdup(create_valid_alias(shell->tab));
	  shell->alias_value = 1;
	}
      i += 1;
    }
  free_all(NULL, alias);
  return (0);
}

int		my_alias(t_info_shell *shell)
{
  char		**alias;
  char		**commands;

  if (((alias = cut_alias(shell->alias_tab)) == NULL)
      || ((commands = cut_commands(shell->alias_tab)) == NULL))
    return (84);
  if ((my_strcmp(shell->tab[0], "alias") == 0)
      && (shell->tab[1] != NULL)
      && (shell->tab[2] != NULL))
    replace_existing_alias(shell->tab[1], shell);
  recognize_my_alias(commands, alias, shell);
  free_all(NULL, alias);
  free_all(NULL, commands);
  return (0);
}
