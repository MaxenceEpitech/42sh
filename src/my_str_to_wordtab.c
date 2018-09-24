/*
** my_str_to_wordtab.c for str_to_wordtab in /home/JB.Melet/Projets/Graphical/wireframe
**
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
**
** Started on  Sun May  7 13:03:31 2017 JeanBaptiste Melet
** Last update Fri Sep 29 12:36:38 2017 jean-baptiste
*/

#include <stdlib.h>

int		count_words(const char *str, char sep)
{
  int		words;
  int		i;

  i = 0;
  words = 1;
  while (str[0] == sep)
    str = str + 1;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	{
	  while (str[i] == sep)
	    i = i + 1;
	  words = words + 1;
	}
      if (str[i] != '\0')
	i = i + 1;
    }
  if (i != 0 && str[i - 1] == sep)
    words = words - 1;
  return (words);
}

char		*alloc_line(const char *str, char sep, int *i)
{
  char		*line;
  int		tmp;
  int		len;

  tmp = *i;
  len = 0;
  while (str[*i] != '\0' && str[*i] != sep)
    {
      *i = *i + 1;
      len = len + 1;
    }
  if ((line = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  len = 0;
  while (tmp < *i)
    line[len++] = str[tmp++];
  line[len] = '\0';
  if (str[*i] != '\0')
    *i = *i + 1;
  return (line);
}

char		**my_str_to_wordtab(const char *str, char sep)
{
  char		**tab;
  int		words;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str == NULL)
    return (NULL);
  words = count_words(str, sep);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  while (i < words)
    {
      while (str[j] == sep)
	j = j + 1;
      if ((tab[i] = alloc_line(str, sep, &j)) == NULL)
	return (NULL);
      i = i + 1;
    }
  tab[i] = NULL;
  return (tab);
}
