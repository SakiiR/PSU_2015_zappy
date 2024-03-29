/*
** food.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jun 17 16:48:16 2016 Barthelemy Gouby
** Last update Wed Jun 29 15:59:08 2016 Barthelemy Gouby
*/

#include "server.h"

void			consume_food(t_server *server, t_client *client)
{
  if (client->character->hunger_timer <= 0)
    {
      if (client->character->quantities[NOURRITURE] > 0)
	{
	  --client->character->quantities[NOURRITURE];
	  client->character->hunger_timer = 126;
	}
      else
	{
	  write_to_buffer(&client->buffer_out, "mort\n", strlen("mort\n"));
	  sprintf(server->buffer, "pdi %i\n", client->character->id);
	  graphic_broadcast(server, server->buffer);
	  if (client->character->base_member)
	    --client->character->team->base_members;
	  remove_character_from_case(client->character->current_case,
				     client->character);
	  close(client->socket);
	  client->socket = 0;
	  client->type = UNSPECIFIED;
	}
    }
  else
    --client->character->hunger_timer;
}

int			player_food_consumption(t_server *server)
{
  int			i;

  i = -1;
  while (++i < server->client_pool_size)
    {
      if (server->clients[i].socket != 0 && server->clients[i].type == DRONE)
	consume_food(server, &server->clients[i]);
    }
  return (RETURN_SUCCESS);
}
