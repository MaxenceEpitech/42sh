/*
** main.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Fri Jun 16 13:34:54 2017 JeanBaptiste Melet
** Last update Sun Oct  8 14:14:58 2017 jean-baptiste
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
#include "printf.h"

extern char **environ;

void		prompt(void)
{
  char		*dir;
  static int	i = 0;

  dir = getcwd((char *)NULL, 0);
  my_printf("(%s %d)> ", dir, i);
  i += 1;
  free(dir);
}

static int	execute_shell(t_info_shell *shell)
{
  (isatty(0)) ? prompt() : 0;
  shell->alias_tab = get_my_alias();
  while ((shell->command = get_next_line(0)))
    {
      if (command_verif(shell) == 0)
	{
	  if (((shell->command = little_verif(my_epurstr(shell->command))) == NULL)
	      || ((shell->command = command_normed(shell->command, ';')) == NULL)
	      || ((shell->historic =
		   history_add(shell->historic, shell->command)) == NULL)
	      || ((shell->tab = my_str_to_wordtab(shell->command, ' ')) == NULL)
	      || ((shell->tablen = my_tablen(shell->tab)) == -1)
	      || ((execution_in_chain(shell)) == 84))
	    return (84);
	}
      (isatty(0)) ? prompt() : 0;
    }
  return (shell->exit_value);
}

int		main(void)
{
  t_info_shell	shell;

  init_struct(&shell);
  return (execute_shell(&shell));
}
