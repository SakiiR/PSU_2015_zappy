/*
** process2.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jun 24 16:44:11 2016 Barthelemy Gouby
** Last update Sun Jun 26 17:13:08 2016 Karine Aknin
*/

#include "server.h"

static void			adding_sockets(t_server *server,
					       fd_set *set_in,
					       fd_set *set_out,
					       int *max)
{
  int				i;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket > 0)
	{
	  FD_SET(server->clients[i].socket, set_in);
	  FD_SET(server->clients[i].socket, set_out);
	}
	if (server->clients[i].socket > *max)
	  *max = server->clients[i].socket;
    }
}

int				select_sockets(t_server *server, fd_set *si, fd_set *so)
{
  struct timeval		tv;
  int				max_socket;

  max_socket = 0;
  tv.tv_usec = 50;
  tv.tv_sec = 0;
  FD_ZERO(si);
  FD_ZERO(so);
  FD_SET(server->socket, si);
  max_socket = server->socket;
  adding_sockets(server, si, so, &max_socket);
  if (select(max_socket + 1, si, so, NULL, &tv) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
