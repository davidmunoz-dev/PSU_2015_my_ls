/*
** my_putnbr_base.c for my_putnbr_base in /home/colett_j/rendu/lib/my
** 
** Made by Jean-baptiste Colette
** Login   <colett_j@epitech.net>
** 
** Started on  Thu Nov 12 10:34:09 2015 Jean-baptiste Colette
** Last update Thu Nov 12 11:23:48 2015 Jean-baptiste Colette
*/

#include "my.h"

int	my_putnbr_base(int i, char *b)
{
  int	res;
  int	div;
  int	length;

  length = my_strlen(b);
  if (i < 0)
    {
      my_putchar('-');
      i = -i;
    }
  div = 1;
  while ((i / div) >= length)
    {
      div = div * length;
    }
  while (div > 0)
    {
      res = (i / div) % length;
      my_putchar(b[res]);
      div = div / length;
    }
}
