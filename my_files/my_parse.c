/*
** my_parse.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:06:55 2016 Sumeet Singh
** Last update Sat Dec 17 00:06:56 2016 Sumeet Singh
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./../include/my.h"

int	my_malloc(t_bsq *buffer)
{
  int	a;

  a = 0;
  if ((buffer->tab = malloc(sizeof(char *) * buffer->line_tab)) == NULL)
    return (-1);
  if ((buffer->itab = malloc(sizeof(int *) * buffer->line_tab)) == NULL)
    return (-1);
  while (a < buffer->line_tab)
    {
      if ((buffer->tab[a] = malloc(sizeof(char) *
				 (my_strlen2(buffer->colo_tab) + 1))) == NULL)
	return (-1);
      if ((buffer->itab[a] = malloc(sizeof(int) *
				   (my_strlen2(buffer->colo_tab) + 1))) == NULL)
	return (-1);
      a = a + 1;
    }
  return (0);
}

int	char_to_int__tab(t_bsq *buffer)
{
  int	c;
  int	d;

  c = 0;
  while (c < buffer->line_tab)
    {
      d = 0;
      while (d < my_strlen2(buffer->colo_tab))
	{
	  if (buffer->tab[c][d] == '.')
	    buffer->itab[c][d] = 1;
	  else if (buffer->tab[c][d] == 'o')
	    buffer->itab[c][d] = 0;
	  d = d + 1;
	}
      c = c + 1;
    }
  return (0);
}

int	my_parsing(char *av, t_bsq *buffer)
{
  int	a;
  int	ab;
  char	*temp;

  a = 1;
  if ((ab = open(av, O_RDONLY)) == (-1))
    exit (1);
  buffer->line_tab = my_getnbr(line_next(ab));
  if (buffer->line_tab > 2000)
    exit (1);
  buffer->colo_tab = line_next(ab);
  my_malloc(buffer);
  buffer->tab[0] = buffer->colo_tab;
  while (a < buffer->line_tab)
    {
      temp = line_next(ab);
      buffer->tab[a] = temp;
      a = a + 1;
    }
  char_to_int__tab(buffer);
  return (0);
}
