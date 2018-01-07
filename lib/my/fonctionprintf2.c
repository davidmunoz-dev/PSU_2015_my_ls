/*
** fonctionprintf2.c for fonctionprintf2 in /home/colett_j/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Jean-baptiste Colette
** Login   <colett_j@epitech.net>
** 
** Started on  Mon Nov 16 14:45:15 2015 Jean-baptiste Colette
** Last update Mon Nov 16 16:11:48 2015 Jean-baptiste Colette
*/

#include <stdarg.h>
#include "my.h"

typedef         int (*flag)(va_list);

int     exalower(va_list list)
{
  unsigned int  nb;
  int           nb2;
  char          *base;

  nb2 = va_arg(list, int);
  base = "0123456789abcdef";
  nb = nb2;
  my_putnbr_base(nb, base);
}

int     binary(va_list list)
{
  unsigned int  nb;
  char          *base;

  nb = va_arg(list, unsigned int);
  base = "01";
  my_putnbr_base(nb, base);
}

int     octadec(va_list list)
{
  unsigned int  nb;
  char          *base;

  nb = va_arg(list, unsigned int);
  base = "01234567";
  my_putnbr_base(nb, base);
}

int     dec(va_list list)
{
  unsigned int  nb;
  char          *base;

  nb = va_arg(list, unsigned int);
  my_put_nbr(nb);
}

int     pointerexa(va_list list)
{
  void  *fmt;
  char  *base;

  base = "0123456789abcdef";
  fmt = va_arg(list, int *);
  my_putstr("0x");
  my_putnbr_base(fmt, base);
}
