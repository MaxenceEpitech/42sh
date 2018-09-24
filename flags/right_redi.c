/*
** right_redi.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Thu Aug 10 19:56:41 2017 JeanBaptiste Melet
** Last update Sat Aug 26 09:09:07 2017 jean-baptiste
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"
#include "printf.h"

char		**cut_tab(char **tab, char *sep)
{
  int		i;
  int		j;
  char		**new_tab;

  i = 0;
  j = 0;
  if ((new_tab = malloc(sizeof(char *) * my_tablen(tab) + 1)) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], sep) == 0)
	i += 2;
      if (tab[i] == NULL)
	break ;
      new_tab[j] = my_strdup(tab[i]);
      i += 1;
      j += 1;
    }
  new_tab[j] = NULL;
  free_all(NULL, tab);
  return (new_tab);
}

int		right_redi(char *file_name, t_info_shell *shell)
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
      execution_in_chain(shell);
      close(fd);
      exit(0);
    }
  else
    wait(&statues);
  return (0);
}

int		right_chevron(t_info_shell *shell)
{
  int		i;
  char		*file_name;

  i = 0;
  shell->flags_value = 1;
  while (my_strcmp(shell->tab[i], ">") != 0)
    i += 1;
  if (((file_name = my_strdup(shell->tab[i + 1])) == NULL)
      || ((shell->tab = cut_tab(shell->tab, ">")) == NULL)
      || ((right_redi(file_name, shell)) == 84))
    return (84);
  free(file_name);
  return (0);
}
