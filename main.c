/*
** main.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Wed Dec 14 19:04:22 2016 Sumeet Singh
** Last update Sat Dec 17 00:02:39 2016 Sumeet Singh
*/
#include "./include/my.h"

void	checking_arg(char **av, int ac, t_bsq *arg)
{
  if (ac == 2)
    {
      arg->obs = 'o';
      arg->free = '.';
      arg->sqr = 'x';
    }
  else if (ac == 5)
    {
      arg->obs = av[2][0];
      arg->free = av[3][0];
      arg->sqr = av[4][0];
    }
  else
    error_manager();
}

int	main(int ac, char **av)
{
  t_bsq	*arg;

  if ((arg = malloc(sizeof(t_bsq))) == NULL)
    return (-1);
  checking_arg(av, ac, arg);
  my_parsing(av[1], arg);
  my_algo(arg);
  getting_pos(arg);
  return (0);
}
