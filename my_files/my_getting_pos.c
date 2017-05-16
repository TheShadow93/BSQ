/*
** my_getting_pos.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:06:35 2016 Sumeet Singh
** Last update Sat Dec 17 00:06:36 2016 Sumeet Singh
*/
#include "./../include/my.h"

int	tab_show(t_bsq *buffer)
{
  int	c;
  int	d;

  c = 0;
  while (c < buffer->line_tab)
    {
      d = 0;
      while (d < my_strlen2(buffer->colo_tab))
	{
	  if (buffer->tab[c][d] == 'x')
	    my_putchar(buffer->sqr);
	  else if (buffer->tab[c][d] == 'o')
	    my_putchar(buffer->obs);
	  else if (buffer->tab[c][d] == '.')
	    my_putchar(buffer->free);
	  d = d + 1;
	}
      my_putchar('\n');
      c = c + 1;
    }
  return (0);
}

int	pos_writer(t_bsq *buffer)
{
  int	c;
  int	d;
  int	x;
  int	y;

  c = buffer->pos_x;
  x = 0;
  while (x < buffer->size)
    {
      d = buffer->pos_y;
      y = 0;
      while (y < buffer->size)
	{
	  buffer->tab[c][d] = 'x';
	  d = d - 1;
	  y = y + 1;
	}
      x = x + 1;
      c = c - 1;
    }
  tab_show(buffer);
  return (0);
}

int	getting_pos(t_bsq *buffer)
{
  int	c;
  int	d;

  c = 0;
  d = 0;
  buffer->size = buffer->itab[c][d];
  buffer->pos_x = 0;
  buffer->pos_y = 0;
  while (c < buffer->line_tab)
    {
      d = 0;
      while (d < my_strlen2(buffer->colo_tab))
	{
	  if (buffer->itab[c][d] > buffer->size)
	    {
	      buffer->size = buffer->itab[c][d];
	      buffer->pos_x = c;
	      buffer->pos_y = d;
	    }
	  d = d + 1;
	}
      c = c + 1;
    }
  pos_writer(buffer);
  return (0);
}
