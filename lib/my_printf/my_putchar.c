/*
** my_putchar.c for my_putchar in /home/JB.Melet/CPool_Day03
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Wed Mar  8 08:52:14 2017 JeanBaptiste Melet
** Last update Mon Apr 10 00:07:39 2017 JeanBaptiste Melet
*/

#include <unistd.h>
#include <stdarg.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	put_modulo(va_list ap)
{
  (void)ap;
  my_putchar('%');
  return (0);
}
