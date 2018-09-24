/*
** left_redi.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Aug 12 17:58:29 2017 JeanBaptiste Melet
** Last update Sat Aug 19 18:52:28 2017 JeanBaptiste Melet
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"
#include "printf.h"

int		left_redi(char *file_name, t_info_shell *shell)
{
  int		fd;
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    return (84);
  else if (pid == 0)
    {
      if ((fd = open(file_name, O_RDONLY)) == -1)
	{
	  my_printf("%s:%s", file_name, NO_SUCH_FILE);
	  exit(84);
	}
      dup2(fd, 0);
      execution_in_chain(shell);
      close(fd);
      exit(0);
    }
  else
    wait(&status);
  return (0);
}

int		left_chevron(t_info_shell *shell)
{
  int		i;
  char		*file_name;

  i = 0;
  shell->flags_value = 1;
  while (my_strcmp(shell->tab[i], "<") != 0)
    i += 1;
  if (((file_name = my_strdup(shell->tab[i + 1])) == NULL)
      || ((shell->tab = cut_tab(shell->tab, "<")) == NULL)
      || ((left_redi(file_name, shell)) == 84))
    return (84);
  free(file_name);
  return (0);
}
