/*
** my_magic_quote.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_42sh
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Sun Oct  8 14:34:01 2017 jean-baptiste
** Last update Sun Oct  8 15:13:04 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

int		detect_magic_quote(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  if ((str[0] == '`') && (str[i - 1] == '`'))
    return (1);
  return (0);
}

char		*special_strdup(char *str)
{
  int		i;
  int		j;
  char		*new_str;

  if ((new_str = malloc(sizeof(char)
			* (my_strlen(str) - 2) + 1)) == NULL)
    return (NULL);
  i = 1;
  j = 0;
  while (str[i + 1] != '\0')
    {
      new_str[j] = str[i];
      i += 1;
      j += 1;
    }
  new_str[j] = '\0';
  return (new_str);
}

int		check_magic_quote(t_info_shell *shell, char *str)
{
  char		**tab;
  char		**save;

  if ((tab = malloc(sizeof(char *) * 2)) == NULL)
    return (84);
  if ((tab[0] = special_strdup(str)) == NULL)
    return (84);
  tab[1] = NULL;
  save = shell->tab;
  shell->tab = tab;
  if (is_valid_command(shell) == NULL)
    my_printf("%s: %s", tab[0], COMMAND_ERROR);
  shell->tab = save;
  free_all(NULL, tab);
  return (0);
}

int		my_magic_quote(t_info_shell *shell)
{
  int		i;

  i = 0;
  while (shell->tab[i] != NULL)
    {
      if ((detect_magic_quote(shell->tab[i])) == 1)
	if ((check_magic_quote(shell, shell->tab[i])) == 84)
	  return (84);
      i += 1;
    }
  return (0);
}
