/*
** execution_begin.c for 42sh in /home/jean-baptiste/Projets/Semestre2/Systeme-Unix/PSU_2016_42sh/execution
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Wed Sep 20 15:40:46 2017 jean-baptiste
** Last update Thu Oct  5 08:49:22 2017 jean-baptiste
*/

#include <stdlib.h>
#include "minishell.h"
#include "printf.h"

static t_flag	g_flags[9]=
{
  {"|", pipes},
  {"&&", and},
  {"||", or},
  {">", right_chevron},
  {"<", left_chevron},
  {">>", double_right_chevron},
  {"2>", error_chevron},
  {"2>>", double_error_chevron},
  {"2>&1", all_chevron}
};

int		find_flags(t_info_shell *shell)
{
  int		i;
  int		j;

  i = 0;
  while (shell->tab[i] != NULL)
    {
      j = 0;
      while (j < 9)
        {
          if ((my_strcmp(shell->tab[i], g_flags[j].code)) == 0)
            {
              if ((g_flags[j].fc(shell)) == 84)
		return (84);
              return (0);
            }
          j += 1;
        }
      i += 1;
    }
  shell->flags_value = 0;
  return (0);
}
