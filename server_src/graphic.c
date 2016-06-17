/*
** graphic.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 13:03:12 2016 Barthelemy Gouby
** Last update Thu Jun 16 18:45:09 2016 Barthelemy Gouby
*/

#include "server.h"

int				        graphic_broadcast(t_server *server, char *message)
{
  int					i;
  i = -1;

  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket != 0 && server->clients[i].type == GRAPHIC)
	write_to_buffer(&server->clients[i].buffer_out, message, strlen(message));
    }
  return (RETURN_SUCCESS);
}
