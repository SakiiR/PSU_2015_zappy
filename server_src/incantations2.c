/*
** incantations2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 23 15:09:55 2016 Erwan Dupard
** Last update Thu Jun 23 15:18:24 2016 Erwan Dupard
*/

#include "server.h"

int					incantation_broadcast_b(t_server *server,
								t_client *client,
								t_incantation *incantation,
								t_character **players)
{
  int					i;
  char					buf[128];

  sprintf(server->buffer, "pic %d %d %d",
	  client->character->current_case->x,
	  client->character->current_case->y,
	  incantation->level);
  i = -1;
  while (players[++i])
    {
      sprintf(buf, " %d", players[i]->id);
      strcat(server->buffer, buf);
    }
  i = -1;
  while (server->clients[++i].host_name)
    {
      if (server->clients[i].type == GRAPHIC)
	write_to_buffer(&server->clients[i].buffer_out,
			server->buffer,
			strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}
