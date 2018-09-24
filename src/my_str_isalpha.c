/*
** my_strisalpha.c for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/src
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Tue Jun 20 15:18:42 2017 JeanBaptiste Melet
** Last update Thu Jun 22 15:10:55 2017 JeanBaptiste Melet
*/

int		my_str_isalpha(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9')
	  && (str[i] < 'A' || str[i] > 'Z')
	  && (str[i] < 'a' || str[i] > 'z'))
	return (1);
      i += 1;
    }
  return (0);
}

int		verif_first_letter(char *str)
{
  if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z'))
    return (1);
  return (0);
}
