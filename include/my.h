/*
** my.h for  in /home/sumeet.singh/delivery/CPE_2016_BSQ/include
**
** Made by Sumeet Singh
** Login   <sumeet.singh@epitech.net>
**
** Started on  Sat Dec 17 00:03:36 2016 Sumeet Singh
** Last update Sat Dec 17 00:04:11 2016 Sumeet Singh
*/
#ifndef HEADER_H_
# define HEADER_H_
# define BUFFER_SIZE 10000000

#include <stdlib.h>

typedef struct		s_bsq
{
  int			**itab;
  char			**tab;
  char			*data;
  int			line_tab;
  char			*colo_tab;
  int			pos_x;
  int			pos_y;
  int			size;
  char			obs;
  char			free;
  char			sqr;
}			t_bsq;

int			my_int_cmp(int a, int z, int e);

int			my_algo(t_bsq *buffer);

char			*line_next(const int az);

int			pos_writer(t_bsq *buffer);

int			tab_show(t_bsq *buffer);

void			my_putchar(char c);

int			my_putstr(char *str);

int			my_strlen(char *str);

int			my_strlen2(char *str);

int			sign_checker(char *str);

int			cleaner(char a);

int			my_getnbr(char *str);

int			my_malloc(t_bsq *buffer);

int			char_to_int__tab(t_bsq *buffer);

int			my_parsing(char *av, t_bsq *buffer);

void			arg_gest(char **av, int ac, t_bsq *arg);

int			getting_pos(t_bsq *buffer);

void			error_manager(void);

#endif			/* !HEADER_H_ */
