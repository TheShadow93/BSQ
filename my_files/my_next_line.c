/*
** my_next_line.c for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/my_files
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:06:47 2016 Sumeet Singh
** Last update Sat Dec 17 00:06:48 2016 Sumeet Singh
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./../include/my.h"

void	*remalloc(unsigned int size)
{
  void	*a;

  if ((a = malloc(size)) == 0)
    exit(EXIT_FAILURE + 0 * write (2, "Unable to malloc\n", 17));
  return (a);
}

static char	*my_strncpy(char *a, char *b, int c)
{
  int	d;

  d = 0;
  while (*b != '\0' && c > 0)
    {
      a[d] = b[d];
      c = c - 1;
      d = d + 1;
    }
  if (d == 0 || c == 0)
    a[d] = '\0';
  return (a);
}

static char	*line_add(char *pos, int abc, char *buffer, int *begin)
{
  char	*new_elem;
  int	old_len;

  old_len = (pos) ? my_strlen(pos) : 0;
  new_elem = remalloc((old_len + abc + 1) * sizeof(*new_elem));
  my_strncpy(new_elem, pos ? pos : "", old_len);
  my_strncpy(new_elem + old_len, buffer + *begin, abc);
  new_elem[old_len + abc] = 0;
  if (pos)
    free(pos);
  *begin += abc + 1;
  return (new_elem);
}

char	*line_next(const int az)
{
  static char	buffer[BUFFER_SIZE + 1];
  static int	in_buffer = 0;
  static int	begin;
  int	abc;
  char	*pos;

  pos = 0;
  abc = 0;
  while (1)
    {
      if (begin >= in_buffer)
	{
	  begin = 0;
	  if (!(in_buffer = read(az, buffer, BUFFER_SIZE)))
	    return (pos);
	  if (in_buffer == -1)
	    exit(EXIT_FAILURE + 0 * write (2, "Cannot read\n", 15));
	  abc = 0;
	}
      if (buffer[begin + abc] == '\n')
	return (pos = line_add(pos, abc, buffer, &begin));
      if (begin + abc == in_buffer - 1)
	pos = line_add(pos, abc + 1, buffer, &begin);
      abc++;
    }
}
