/*
** buf.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 14:32:57 2016 Gabriel Goude
** Last update Wed Jun 22 16:11:17 2016 Erwan Dupard
*/

#include <sys/select.h>
#include "resources.h"

char				*read_buf(t_infos *infos)
{
  char				s[4096];
  int				i;
  int				retval;
  char				*msg;

  fill_set(infos);
  while ((retval = select(infos->socket + 1,
			  &(infos->select.rfds),
			  NULL,
			  NULL,
			  &(infos->select.tv))) < 0)
    fill_set(infos);
  if (FD_ISSET(infos->socket, &(infos->select.rfds)))
  {
    i = read(infos->socket, s, 4096);
    if (i > 0)
      write_to_buffer(&(infos->buffer), s, i);
  }
  msg = get_next_message(&(infos->buffer));
  if (msg && msg[0])
    return (msg);
  if (msg)
    free(msg);
  return (NULL);
}

int				write_buf(t_infos *infos, char *str)
{
  write_to_buffer(&(infos->buffer), str, strlen(str));
  write_to_buffer(&(infos->buffer), "\n", 1);
  return (RETURN_SUCCESS);
}

void				fill_set(t_infos *infos)
{
  infos->select.tv.tv_usec = 0;
  infos->select.tv.tv_sec = 10;
  FD_ZERO(&(infos->select.rfds));
  FD_ZERO(&(infos->select.wfds));
  FD_SET(infos->socket, &(infos->select.rfds));
  FD_SET(infos->socket, &(infos->select.wfds));
}
