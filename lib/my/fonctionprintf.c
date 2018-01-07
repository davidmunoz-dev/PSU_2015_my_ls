/*
** fonctionprintf.c for fonctionf in /home/colett_j/rendu/PSU_2015_my_printf
** 
** Made by Jean-baptiste Colette
** Login   <colett_j@epitech.net>
** 
** Started on  Thu Nov 12 18:21:11 2015 Jean-baptiste Colette
** Last update Mon Nov 16 16:12:36 2015 Jean-baptiste Colette
*/

#include <stdarg.h>
#include "my.h"

typedef		int (*flag)(va_list);

int	string(va_list list)
{
  char	*str;
  str = va_arg(list, char *);
  my_putstr(str);
}

int	character(va_list list)
{
  char	c;
  c = va_arg(list, int);
  my_putchar(c);
}

int	number(va_list list)
{
  int	nb;
  nb = va_arg(list, int);
  my_put_nbr(nb);
}

int	stringoctal(va_list list)
{
  char	*fmt;
  char	*base;
  int	i;

  fmt = va_arg(list, char *);
  i = 0;
  base = "01234567";
  while (fmt[i])
    {
      if (fmt[i] < 7)
        {
          my_putstr("\\00");
          my_putnbr_base(fmt[i], base);
        }
      else if ((fmt[i] > 7 && fmt[i] < 32) || fmt[i] >= 127)
        {
          my_putstr("\\0");
          my_putnbr_base(fmt[i], base);
        }
      else
        my_putchar(fmt[i]);
      i = i + 1;
    }
}

int	exaupper(va_list list)
{
  int           nb;
  unsigned int  nb2;
  char          *base;

  nb = va_arg(list, int);
  base = "0123456789ABCDEF";
  nb2 = nb;
  my_putnbr_base(nb2, base);
}
