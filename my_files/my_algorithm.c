/*
** my_algorithm.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:05:23 2016 Sumeet Singh
** Last update Sat Dec 17 00:05:24 2016 Sumeet Singh
*/
#include "./../include/my.h"

int	my_int_cmp(int a, int z, int e)
{
  if (a <= z && a <= e)
    return (a);
  else if (z <= a && z <= e)
    return (z);
  else if (e <= a && e <= z)
    return (e);
  return (0);
}

int	my_algo(t_bsq *buffer)
{
  int	w;
  int	a;
  int	az;
  int	qs;
  int	wx;

  w = 1;
  a = 1;
  while (w < buffer->line_tab)
    {
      a = 1;
      while (a < my_strlen2(buffer->colo_tab))
	{
	  if (buffer->itab[w][a] != 0)
	    {
	      az = buffer->itab[w - 1][a - 1];
	      qs = buffer->itab[w - 1][a];
	      wx = buffer->itab[w][a - 1];
	      buffer->itab[w][a] = buffer->itab[w][a] + my_int_cmp(az, qs, wx);
	    }
	  a = a + 1;
	}
      w = w + 1;
    }
  return (0);
}
