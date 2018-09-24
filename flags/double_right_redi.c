/*
** double_right_redi.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/flags
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Tue Aug 15 11:57:41 2017 JeanBaptiste Melet
** Last update Thu Oct  5 14:50:27 2017 jean-baptiste
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"
#include "printf.h"

int		double_right_redi(char *file_name, t_info_shell *shell)
{
  int		fd;
  pid_t		pid;
  int		statues;

  if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    {
      if ((fd = open(file_name, O_RDWR | O_APPEND, 0644)) == -1)
	fd = open(file_name, O_RDWR | O_CREAT, 0644);
      dup2(fd, STANDARD_OUTPUT);
      execute_command(shell);
      close(fd);
      exit(shell->exit_value);
    }
  else
    {
      wait(&statues);
      shell->exit_value = WEXITSTATUS(statues);
    }
  return (0);
}

int		double_right_chevron(t_info_shell *shell)
{
  int		i;
  char		*file_name;

  i = 0;
  shell->flags_value = 1;
  while (my_strcmp(shell->tab[i], ">>") != 0)
    i += 1;
  if (((file_name = my_strdup(shell->tab[i + 1])) == NULL)
      || ((shell->tab = cut_tab(shell->tab, ">>")) == NULL)
      || ((double_right_redi(file_name, shell)) == 84))
    return (84);
  free(file_name);
  return (0);
}

int		double_error_redi(char *file_name, t_info_shell *shell)
{
  int		fd;
  pid_t		pid;
  int		statues;

  if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    {
      if ((fd = open(file_name, O_RDWR | O_APPEND, 0644)) == -1)
	fd = open(file_name, O_RDWR | O_CREAT, 0644);
      dup2(fd, 2);
      execute_command(shell);
      close(fd);
      exit(0);
    }
  else
    wait(&statues);
  return (0);
}

int		double_error_chevron(t_info_shell *shell)
{
  int		i;
  char		*file_name;

  i = 0;
  shell->flags_value = 1;
  while (my_strcmp(shell->tab[i], "2>>") != 0)
    i += 1;
  if (((file_name = my_strdup(shell->tab[i + 1])) == NULL)
      || ((shell->tab = cut_tab(shell->tab, "2>>")) == NULL)
      || ((double_error_redi(file_name, shell)) == 84))
    return (84);
  free(file_name);
  return (0);
}
