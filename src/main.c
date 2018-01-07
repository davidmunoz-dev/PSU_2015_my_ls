/*
** arguments.c for l in /home/munoz_d/Epitech/rendu/rendu_Systeme_Unix/PSU_2015_my_ls/src
** 
** Made by Munoz David
** Login   <munoz_d@epitech.net>
** 
** Started on  Sun Nov 29 13:16:17 2015 Munoz David
** Last update Sun Nov 29 20:48:38 2015 Munoz David
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include "../include/my.h"


int	list(int(*flag[7])(va_list ap))
{/*
  flag[0] = xx;
  flag[1] = xx;
  flag[2] = xx;
  flag[3] = xx;
  flag[4] = xx;
  flag[5] = xx;
  flag[6] = xx;
 */
  return (0);
}

int	ls_dir(int ac, char **av, DIR **dirp, struct dirent **entry)
{
  int (*flag[5])(va_list ap);
  va_list       ap;
  char  *list_flag;
  int   a;
  int   b;
  int   c;
  c = 0;
  a = 0;
  list_flag = "adlsrRt";
  list(flag);
  while (av[a] != NULL)
    {
      c = 0;
      if (av[a][0] == '-')
        {
          b = 0;
          while (list_flag[b] && av[a][c++] != list_flag[b])
            b++;
          if (list_flag[b])
            flag[b](ap);
        }
      a++;
    }
  argument(ac, av, &dirp, &entry);
  return (0);
}

int     main(int ac, char **av, DIR *dirp, struct dirent *entry)
{
  ls_dir(ac, av, &dirp, &entry);
  my_printf("\n");
  return (0);
}
