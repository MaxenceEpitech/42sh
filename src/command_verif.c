/*
** command_verif.c for minishell2 in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_minishell2/src
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Sat Aug 26 18:38:14 2017 jean-baptiste
** Last update Fri Oct  6 16:31:58 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

int		pipe_verif(t_info_shell *shell)
{
  int		i;
  char		*command;

  i = 0;
  command = shell->command;
  while (command[i] != '\0')
    {
      if (command[i] != '|')
        return (0);
      i += 1;
    }
  my_printf("%s", INVALID_NULL);
  shell->exit_value = 1;
  return (1);
}

int		command_verif(t_info_shell *shell)
{
  int		i;
  char		*command;

  i = 0;
  command = shell->command;
  if ((my_strlen(command) == 0) || (pipe_verif(shell) == 1))
    {
      free(command);
      return (1);
    }
  while (command[i] != '\0')
    {
      if (command[i] != ' ' && command[i] != '\t' && command[i] != ';')
        return (0);
      i += 1;
    }
  free(command);
  return (1);
}
