/*
** events.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:04:49 2016 Erwan Dupard
** Last update Thu Jun 23 17:11:19 2016 Barthelemy Gouby
*/

#include "server.h"

int					event_new_player(t_server *server, va_list ap)
{
  int					i;

  i = -1;
  while (server->clients[++i].host_name)
    {
      if (server->clients[i].type == GRAPHIC)
	{
	}
    }
  (void)ap;
  return (RETURN_SUCCESS);
}



int					event_broadcast(t_server *server, va_list ap)
{
  int					i;
  t_client				*sender;
  i = -1;
  sender = va_arg(ap, t_client *);
  
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket != 0 &&
	  server->clients[i].type == DRONE &&
	  &server->clients[i] != sender)
	{
	  if (send_broadcast_to_drone(server,
				      sender,
				      &server->clients[i],
				      "") == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
    }
  return (RETURN_SUCCESS);
}

int					event_end_incantation(t_server *server, va_list ap)
{
  (void)server;
  (void)ap;
  return (RETURN_SUCCESS);
}

int					event_new_incantation(t_server *server, va_list ap)
{
  (void)server;
  (void)ap;
  return (RETURN_SUCCESS);
}
