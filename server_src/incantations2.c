/*
** incantations2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 23 15:09:55 2016 Erwan Dupard
** Last update Thu Jun 23 18:55:24 2016 Erwan Dupard
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
  while (players && players[++i])
    {
      printf("player : %d\n", players[i]->id);
      sprintf(buf, " %d", players[i]->id);
      strcat(server->buffer, buf);
    }
  strcat(server->buffer, "\n");
  printf("[^] Sending : %s\n", server->buffer);
  graphic_broadcast(server, server->buffer);
  return (RETURN_SUCCESS);
}

int					incantation_broadcast_e(t_server *server,
								t_client *client,
								t_character **players)
{
  int					i;
  
  sprintf(server->buffer, "pie %d %d 1\n",
	  client->character->current_case->x,
	  client->character->current_case->y);
  graphic_broadcast(server, server->buffer);
  i = -1;
  while (players[++i])
    {
      sprintf(server->buffer, "plv %d %d\n",
	      players[i]->id,
	      players[i]->level);
      graphic_broadcast(server, server->buffer);
    }
  i = -1;
  while (server->clients[++i].host_name)
    {
      if (server->clients[i].type == GRAPHIC)
	send_map_content(server, &server->clients[i], NULL);
    }
  return (RETURN_SUCCESS);
}
