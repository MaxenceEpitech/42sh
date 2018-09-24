/*
** redi_all.c for minishell2 in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_minishell2/bonus/flags
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Sat Aug 26 09:06:35 2017 jean-baptiste
** Last update Sun Sep  3 22:33:36 2017 jean-baptiste
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"
#include "printf.h"

int		all_redi(char *file_name, t_info_shell *shell)
{
  int		fd;
  pid_t		pid;
  int		statues;

  if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    {
      fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
      dup2(fd, STANDARD_OUTPUT);
      dup2(fd, 2);
      execution_in_chain(shell);
      close(fd);
      exit(0);
    }
  else
    wait(&statues);
  return (0);
}

int		all_chevron(t_info_shell *shell)
{
  int		i;
  char		*file_name;

  i = 0;
  shell->flags_value = 1;
  while (my_strcmp(shell->tab[i], "2>&1") != 0)
    i += 1;
  if (((file_name = my_strdup(shell->tab[i + 1])) == NULL)
      || ((shell->tab = cut_tab(shell->tab, "2>&1")) == NULL)
      || ((all_redi(file_name, shell)) == 84))
    return (84);
  free(file_name);
  return (0);
}

int		error_redi(char *file_name, t_info_shell *shell)
{
  int		fd;
  pid_t		pid;
  int		statues;

  if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    {
      fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
      dup2(fd, 2);
      execution_in_chain(shell);
      close(fd);
      exit(0);
    }
  else
    wait(&statues);
  return (0);
}

int		error_chevron(t_info_shell *shell)
{
  int		i;
  char		*file_name;

  i = 0;
  shell->flags_value = 1;
  while (my_strcmp(shell->tab[i], "2>") != 0)
    i += 1;
  if (((file_name = my_strdup(shell->tab[i + 1])) == NULL)
      || ((shell->tab = cut_tab(shell->tab, "2>")) == NULL)
      || ((error_redi(file_name, shell)) == 84))
    return (84);
  free(file_name);
  return (0);
}
