/*
** exec.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/minishel
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Fri Jun 16 15:37:08 2017 JeanBaptiste Melet
** Last update Mon Sep  4 00:35:56 2017 jean-baptiste
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include "printf.h"

extern char	**environ;

static int	get_signals(int status)
{
  if (WTERMSIG(status) == SIGSEGV)
    {
      if (WCOREDUMP(status))
	my_printf(SEGFAULT_DUMPED);
      else
	my_printf(SEGFAULT);
      return (EXIT_SEG);
    }
  else if (WTERMSIG(status) == SIGFPE)
    {
      if (WCOREDUMP(status))
	my_printf(FLOAT_EXCEPTION_DUMPED);
      else
	my_printf(FLOAT_EXCEPTION);
      return (EXIT_EXCEPTION);
    }
  return (WEXITSTATUS(status));
}

static int	handle_error(char *command)
{
  if (errno == ENOEXEC)
    my_printf("%s: %s %s\n", command, EXEC_ERROR, BINARY_ERROR);
  if (errno == EACCES)
    my_printf("%s: %s", command, PERM_ERROR);
  return (EXIT_ERROR);
}

int		exec(t_info_shell *shell, char *valid_path)
{
  pid_t		pid;
  int		status;

  pid = fork();
  if (pid == -1)
    return (84);
  if (pid == 0)
    {
      if (valid_path == NULL)
	{
	  my_printf("%s: %s", shell->tab[0], COMMAND_ERROR);
	  exit(EXIT_ERROR);
	}
      execve(valid_path, shell->tab, environ);
      exit(handle_error(valid_path));
    }
  else
    {
      waitpid(pid, &status, WUNTRACED);
      return (get_signals(status));
    }
  return (EXIT_ERROR);
}
