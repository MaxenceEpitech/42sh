/*
** pipes.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/flags
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Mon Aug 14 16:44:49 2017 JeanBaptiste Melet
** Last update Sun Oct  8 14:14:44 2017 jean-baptiste
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include "printf.h"

char		**cut_pipe(char **tab, char  ***new_tab)
{
  int		i;
  int		j;
  int		marker;
  char		**tmp;

  i = 0;
  j = 0;
  if ((tmp = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (my_strcmp(tab[i], "|") != 0)
    i += 1;
  marker = i;
  i += 1;
  while (tab[i] != NULL)
    {
      tmp[j] = my_strdup(tab[i]);
      free(tab[i]);
      i += 1;
      j += 1;
    }
  tab[marker] = NULL;
  tmp[j] = NULL;
  *new_tab = tmp;
  return (tab);
}

void		pipe_return_value(t_info_shell *shell, char **new_tab)
{
  if (shell->exit_value == 1)
    my_printf("%s: %s", shell->tab[0], COMMAND_ERROR);
  shell->tab = new_tab;
  if (((is_valid_command(shell) == NULL)))
    shell->exit_value = 1;
}

int		verif_tabs(t_info_shell *shell, char **new_tab)
{
  if ((shell->tab[0] == NULL) || (new_tab[0] == NULL))
    {
      my_printf("Invalid null command.\n");
      shell->exit_value = 1;
      return (-1);
    }
  return (0);
}

int		my_pipes(t_info_shell *shell,
			 char **new_tab, char **save)
{
  int		pfd[2];
  pid_t		pid;

  if (((pipe(pfd)) == -1) || ((pid = fork()) == -1))
    return (84);
  if (pid == 0)
    {
      close(pfd[FD_ENTRY]);
      dup2(pfd[FD_EXIT], 0);
      close(pfd[FD_EXIT]);
      shell->tab = new_tab;
      parsing(shell);
      exit(shell->exit_value);
    }
  else
    {
      close(pfd[FD_EXIT]);
      dup2(pfd[FD_ENTRY], 1);
      close(pfd[FD_ENTRY]);
      shell->tab = save;
      parsing(shell);
    }
  return (shell->exit_value);
}

int		pipes(t_info_shell *shell)
{
  char		**new_tab;
  char		**save;
  int		status;
  pid_t		pid;

  new_tab = NULL;
  if ((shell->tab = cut_pipe(shell->tab, &new_tab)) == NULL)
    return (84);
  save = shell->tab;
  shell->flags_value = 1;
  if ((verif_tabs(shell, new_tab)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    exit(my_pipes(shell, new_tab, save));
  else
    {
      waitpid(pid, &status, WUNTRACED);
      shell->exit_value = WEXITSTATUS(status);
      pipe_return_value(shell, new_tab);
    }
  free_all(NULL, new_tab);
  free_all(NULL, save);
  return (0);
}
