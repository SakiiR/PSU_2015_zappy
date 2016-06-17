/*
** buf.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 14:32:57 2016 Gabriel Goude
** Last update Fri Jun 17 14:56:05 2016 Gabriel Goude
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
  while ((retval = select(infos->socket + 1, &(infos->select.rfds), NULL, NULL, &(infos->select.tv))) < 0)
    fill_set(infos);
  if (FD_ISSET(infos->socket, &(infos->select.rfds)))
    i = read(infos->socket, s, 4096);
  if (i > 0)
    write_to_buffer(&(infos->buffer), s, i);
  return (msg = get_next_message(&(infos->buffer)));
}

int				write_buf(t_infos *infos, char *str)
{
  char				*msg;
  int				retval;

  write_to_buffer(&(infos->buffer), str, strlen(str));
  write_to_buffer(&(infos->buffer), "\n", 1);
  msg = get_next_message(&(infos->buffer));
  fill_set(infos);
  while ((retval = select(infos->socket + 1, NULL, &(infos->select.wfds), NULL, &(infos->select.tv))) < 0)
    fill_set(infos);
  if (FD_ISSET(infos->socket, &(infos->select.rfds)))
    write(infos->socket, msg, strlen(msg));
  free(msg);
  return (RETURN_SUCCESS);
}
