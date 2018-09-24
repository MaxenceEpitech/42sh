/*
** repeat.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_42sh/command_bonus
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Thu Sep 21 16:25:28 2017 jean-baptiste
** Last update Mon Sep 25 16:32:31 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

int		my_strisnum(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i += 1;
    }
  return (0);
}

int		repeat_check(t_info_shell *shell)
{
  int		i;

  i = my_tablen(shell->tab);
  if ((i == 1) || (i == 2))
    {
      my_printf("repeat: Too few arguments.\n");
      shell->exit_value = 1;
      return (84);
    }
  if (my_strcmp("repeat", shell->tab[0]) != 0)
    return (84);
  if (my_strisnum(shell->tab[1]) != 0)
    {
      my_printf("repeat: Badly formed number.\n");
      shell->exit_value = 1;
      return (84);
    }
  return (0);
}

static char	**cut_my_tab(char **shell_tab)
{
  int		i;
  int		j;
  char		**tab;

  i = 2;
  j = 0;
  if ((tab = malloc(sizeof(char *) * my_tablen(shell_tab))) == NULL)
    return (NULL);
  while (shell_tab[i] != NULL)
    {
      tab[j] = my_strdup(shell_tab[i]);
      i += 1;
      j += 1;
    }
  tab[j] = NULL;
  return (tab);
}

char		*cut_my_string(char *command)
{
  int		i;
  int		j;
  char		*new_command;

  new_command = malloc(sizeof(char) * my_strlen(command) + 1);
  i = 7;
  j = 0;
  while (command[i] != ' ')
    i += 1;
  while (command[i] != '\0')
    {
      new_command[j] = command[i];
      i += 1;
      j += 1;
    }
  new_command[j] = '\0';
  return (new_command);
}

int		repeat(t_info_shell *shell)
{
  int		i;
  int		nb;
  char		**save_tab;
  char		*save_string;

  i = 0;
  if ((repeat_check(shell)) != 0)
    return (84);
  nb = atoi(shell->tab[1]);
  if ((nb == 0) || (nb < 0))
    return (0);
  save_tab = cut_my_tab(shell->tab);
  save_string = cut_my_string(shell->command);
  while (i < nb)
    {
      shell->command = save_string;
      shell->tab = save_tab;
      execution_in_chain(shell);
      i += 1;
    }
  return (0);
}
