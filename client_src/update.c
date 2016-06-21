/*
** handle.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 16:56:28 2016 Gabriel Goude
** Last update Tue Jun 21 16:30:25 2016 Gabriel Goude
*/

#include "resources.h"

int				update(t_infos *infos)
{
  char				*msg;

  while ((msg = read_buf(infos)) != NULL)
  {
    printf("msg received : %s", msg);
  }
  return (RETURN_SUCCESS);
}

int				send_update(t_infos *infos)
{
  char				*msg;
  int				retval;

  fill_set(infos);
  while ((retval = select(infos->socket + 1, NULL, &(infos->select.wfds), NULL, &(infos->select.tv))) < 0)
    fill_set(infos);
  if (FD_ISSET(infos->socket, &(infos->select.wfds)))
  {
    while ((msg = get_next_message(&(infos->buffer))) && msg[0])
      {
	write(infos->socket, msg, strlen(msg));
	free(msg);
      }
  }
  return (RETURN_SUCCESS);
}
