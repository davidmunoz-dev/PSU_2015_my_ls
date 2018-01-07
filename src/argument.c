/*
** main.c for h in /Epitech/rendu/rendu_Systeme_Unix/PSU_2015_my_ls/src
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Nov 24 14:49:52 2015 munoz david
** Last update Sun Nov 29 20:51:21 2015 Munoz David
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include "../include/my.h"

int	cerr(char *msg, int status)
{
  write(2, msg, my_strlen(msg));
  return (status);
}

int	read_arg(int ac, char **av, DIR *dirp, struct dirent **entry)
{
  while ((*entry = readdir(dirp)) != NULL)
    {
      if ((*entry)->d_name[0] != '.')
	my_printf("%s  ", (*entry)->d_name);
    }
  closedir(dirp);
  return (0);
}

int	argument_sup(int ac, char **av, DIR **dirp, struct dirent **entry)
{
  int	i;

  i = 1;
  if (ac > 2)
    {
      while (i < ac)
	{
	  if (av[i][0] != '-')
	    {
	      my_printf("%s: \n", av[i]);
	      if ((*dirp = opendir(av[i])) == NULL)
		return (cerr("[ERROR]: opendir problem\n", -1));
	      read_arg(ac, av, *dirp, entry);
	      if (i < ac - 1)
		my_printf("\n\n");
	    }
	  i++;
	}
    }
  return (0);
}

int	argument(int ac, char **av, DIR **dirp, struct dirent **entry)
{
  if (ac > 2)
      argument_sup(ac, av, dirp, entry);
  else if (ac == 2 && av[1][0] == '/')
    {
      if ((*dirp = opendir(av[1])) == NULL)
        return (cerr("[ERROR]: opendir problem\n", -1));
      read_arg(ac, av, *dirp, entry);
    }
  else if (ac == 1)
    {
      if ((*dirp = opendir("./")) == NULL)
	return (cerr("[ERROR]: opendir problem\n", -1));
      read_arg(ac, av, *dirp, entry);
    }
  return (0);
}
