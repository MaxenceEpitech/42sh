/*
** find_str.c for minishell2 in /home/JB.Melet/Projets/Semestre2/Système_Unix/PSU_2016_minishell2/src
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Sat Aug 19 19:31:29 2017 JeanBaptiste Melet
** Last update Sat Aug 19 19:31:40 2017 JeanBaptiste Melet
*/

#include <stdlib.h>

int	my_find_str(char *str, char *to_find)
{
  int	i;
  char	*ptr_one;
  char	*ptr_two;

  i = 0;
  while (str[i++] != '\0')
    {
      ptr_one = str;
      ptr_two = to_find;
      while (*ptr_one == *ptr_two)
	{
	  ptr_one++;
	  ptr_two++;
	  if (*ptr_two == 0)
	    return (1);
	}
    }
  return (0);
}
