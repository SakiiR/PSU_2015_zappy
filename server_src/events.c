/*
** events.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:04:49 2016 Erwan Dupard
** Last update Wed Jun 15 16:33:09 2016 Erwan Dupard
*/

#include "server.h"

int					event_graphic_broadcast(t_server *server, va_list ap)
{
  int					i;
  char					*message;
  i = -1;

  message = va_arg(ap, char*);
  printf("broadcasting to graphic clients\n");
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket != 0 && server->clients[i].type == GRAPHIC)
	write_to_buffer(&server->clients[i].buffer_out, message, strlen(message));
    }
  return (RETURN_SUCCESS);
}

int					event_new_player(t_server *server, va_list ap)
{
  int					i;

  i = -1;
  /*
   * Good way to iterate over clients ?
   */
  while (server->clients[++i].host_name)
    {
      if (server->clients[i].type == GRAPHIC)
	{
	  /* Send new player payload : "ppo #n X Y O\n" */
	}
    }
  (void)ap;
  return (RETURN_SUCCESS);
}

int					event_broadcast(t_server *server, va_list ap)
{
  (void)server;
  (void)ap;
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

int					event_lay_egg(t_server *server, va_list ap)
{
  (void)server;
  (void)ap;
  return (RETURN_SUCCESS);
}
