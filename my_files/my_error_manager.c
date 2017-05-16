/*
** my_error_manager.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:05:30 2016 Sumeet Singh
** Last update Sat Dec 17 00:12:42 2016 Sumeet Singh
*/
#include "./../include/my.h"

void	error_manager()
{
  my_putstr("Usage : ./bsq [map]\n");
  exit (1);
}

void	error_manager_2(int a, char *str)
{
  if (a == 0 || str == NULL)
    {
      my_putstr("Error: no square found\n");
      exit (1);
    }
}
