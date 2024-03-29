/*
** incantations2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 23 15:09:55 2016 Erwan Dupard
** Last update Sun Jun 26 17:44:03 2016 Erwan Dupard
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
      sprintf(buf, " %d", players[i]->id);
      strcat(server->buffer, buf);
    }
  strcat(server->buffer, "\n");
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

void					incantation_failed(t_server *server,
							   t_client *client)
{
  sprintf(server->buffer, "pie %d %d 0\n",
	  client->character->current_case->x,
	  client->character->current_case->y);
  graphic_broadcast(server, server->buffer);
  strcpy(server->buffer, "ko\n");
  write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
}

t_character				**get_incantation_players(int count,
								  t_character *all)
{
  t_character				**players;
  t_character				*iterator;
  int					i;

  if ((players = malloc(sizeof(*players) * (count + 1))) == NULL)
    return (NULL);
  iterator = all;
  i = 0;
  while (iterator)
    {
      players[i++] = iterator;
      iterator = iterator->next_in_case;
    }
  players[i] = NULL;
  return (players);
}
