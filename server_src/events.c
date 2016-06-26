/*
** events.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:04:49 2016 Erwan Dupard
** Last update Sun Jun 26 17:42:39 2016 Erwan Dupard
*/

#include "server.h"

int			event_broadcast(t_server *server, va_list ap)
{
  int			i;
  t_client		*sender;
  char			*message;

  i = -1;
  sender = va_arg(ap, t_client *);
  message = va_arg(ap, char *);
  printf("[^] Broadcasting from %d : %s\n", sender->character->id, message);
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket != 0 &&
	  server->clients[i].type == DRONE &&
	  &server->clients[i] != sender)
	{
	  if (send_broadcast_to_drone(server,
				      sender,
				      &server->clients[i],
				      message) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
    }
  write_to_buffer(&sender->buffer_out, "ok\n", 3);
  sprintf(server->buffer, "pbc %i %s\n", sender->character->id, message);
  graphic_broadcast(server, server->buffer);
  return (RETURN_SUCCESS);
}
