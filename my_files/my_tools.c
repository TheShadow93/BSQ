/*
** my_tools.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:07:04 2016 Sumeet Singh
** Last update Sat Dec 17 00:07:05 2016 Sumeet Singh
*/
#include <unistd.h>
#include "./../include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  return (i);
}

int	my_strlen2(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
