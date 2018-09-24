/*
** execution_in_chain.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Wed Aug  9 18:33:37 2017 JeanBaptiste Melet
** Last update Sun Oct  8 16:31:52 2017 jean-baptiste
*/

#include <stdlib.h>
#include <unistd.h>
#include <wordexp.h>
#include "minishell.h"
#include "printf.h"

int		change_command(t_info_shell *shell)
{
  t_count	ct;
  char		*tmp;

  (1 == 1) ? (ct.i = 0, ct.j = 0, ct.k = 0) : 1;
  if ((tmp = malloc(sizeof(char) * (my_strlen(shell->command)))) == NULL)
    return (84);
  if ((shell->mem = malloc(sizeof(char)
			   * (my_strlen(shell->command)))) == NULL)
    return (84);
  while (shell->command[ct.i] != ';')
    {
      if (shell->command[ct.i] == '\0')
	return (free_tmp(shell, tmp));
      tmp[ct.j++] = shell->command[ct.i++];
    }
  tmp[ct.j] = '\0';
  while (shell->command[++ct.i] != '\0')
    shell->mem[ct.k++] = shell->command[ct.i];
  shell->mem[ct.k] = '\0';
  shell->command = my_strdup(tmp);
  free(tmp);
  return (0);
}

int		change_tab(t_info_shell *shell)
{
  t_count	ct;
  char		**tmp;

  ct.i = 0;
  ct.j = 0;
  ct.k = 0;
  if (((tmp = malloc(sizeof(char *) * (shell->tablen + 1))) == NULL)
      || ((shell->tab_mem = malloc(sizeof(char *) * shell->tablen)) == NULL))
    return (84);
  while (my_strcmp(shell->tab[ct.i], ";") != 0)
    {
      if (shell->tab[ct.i] == NULL)
	{
	  shell->tab_mem[0] = NULL;
	  return (0);
	}
      tmp[ct.j++] = shell->tab[ct.i++];
    }
  tmp[ct.j] = NULL;
  while (shell->tab[++ct.i] != NULL)
    shell->tab_mem[ct.k++] = my_strdup(shell->tab[ct.i]);
  shell->tab_mem[ct.k] = NULL;
  shell->tab = tmp;
  return (0);
}

int		execution_in_chain(t_info_shell *shell)
{
  wordexp_t     p;
  char          **wordextab;

  shell->mem = BOOL;
  while (shell->mem != NULL)
    {
      if (((change_command(shell)) == 84)
	  || ((change_tab(shell)) == 84)
	  || ((my_magic_quote(shell)) == 84))
	return (84);
      if ((wordexp(shell->command, &p, 0)) == 0)
	{
	  wordextab = p.we_wordv;
	  shell->tab = copy_my_tab(wordextab);
	  wordfree(&p);
	}
      if (((my_alias(shell)) == 84) || ((parsing(shell)) == 84))
	return (84);
      shell->command = shell->mem;
      shell->tab = shell->tab_mem;
    }
  return (shell->exit_value);
}
