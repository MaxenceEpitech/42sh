/*
** create_alias.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/alias
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sun Aug 20 11:39:27 2017 JeanBaptiste Melet
** Last update Wed Aug 23 13:59:33 2017 JeanBaptiste Melet
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

int		alias_check(t_info_shell *shell)
{
  if (my_tablen(shell->tab) == 1)
    {
      my_printf("%t", shell->alias_tab);
      return (1);
    }
  if (my_tablen(shell->tab) == 2)
    return (1);
  if ((my_strcmp(shell->tab[0], shell->tab[1]) == 0) && (shell->tab[2] != NULL))
    {
      my_printf("%s", ALIAS_ERROR);
      return (1);
    }
  if ((my_strcmp(shell->tab[0], shell->tab[1]) == 0))
    return (1);
  return (0);
}

char		*create_valid_alias(char **tab)
{
  int		i;
  char		*command;

  i = 2;
  command = NULL;
  command = my_strcat(my_strcat(my_strcat(tab[0], " ", 2), tab[1], 2), "='", 1);
  while (tab[i] != NULL)
    {
      if (i != 2)
	command = my_strcat(command, " ", 1);
      command = my_strcat(command, tab[i], 1);
      i += 1;
    }
  command = my_strcat(command, "'\0", 2);
  return (command);
}

char		**add_new_alias(char **tab, char *command)
{
  int		i;
  char		**new_tab;

  i = 0;
  if ((new_tab = malloc(sizeof(char *) * ((my_tablen(tab) + 1) + 1))) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      new_tab[i] = my_strdup(tab[i]);
      i += 1;
    }
  new_tab[i] = my_strdup(command);
  new_tab[i + 1] = NULL;
  free_all(command, tab);
  return (new_tab);
}
