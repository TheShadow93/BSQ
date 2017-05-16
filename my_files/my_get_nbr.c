/*
** my_get_nbr.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:06:18 2016 Sumeet Singh
** Last update Sat Dec 17 00:06:19 2016 Sumeet Singh
*/
#include "./../include/my.h"

int	sign_checker(char *str)
{
  int	a;
  int	b;

  a = 1;
  b = 0;
  while (str[b] == '-' || str[b] == '+')
    {
      if (str[b] == '+')
	b = b + 1;
      if (str[b] == '-')
	{
	  a *= -1;
	  b = b + 1;
	}
    }
  return (a);
}

int	cleaner(char a)
{
  if (a >= '0' && a <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int  	compteur;
  int	a;

  a = 0;
  compteur = 0;
  while (cleaner(str[compteur]) == 0)
    {
      if (str[compteur] != '+' && str[compteur] != '-')
	return (0);
      else
	compteur++;
    }
  while (cleaner(str[compteur]) == 1)
    {
      a = a * 10;
      a = a + (str[compteur] - '0');
      compteur++;
    }
  if (sign_checker(str) == -1)
    a = a * -1;
  return (a);
}
