/*
** client_identification.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 13 12:11:17 2016 Barthelemy Gouby
** Last update Tue Jun 14 16:15:42 2016 Erwan Dupard
*/

#include "server.h"

int					initialize_drone(t_server *server,
							 t_client *client,
							 char *input)
{
  t_u64					i;

  i = 0;
  while (i < server->game_data.nbr_of_teams)
    {
      if (strcmp(input, server->game_data.teams[i].name) == 0)
	{
	  client->type = DRONE;
	  if (!(client->character = malloc(sizeof(*(client->character)))))
	    return (RETURN_FAILURE);
	  client->character->level = 1;
	  memset(client->character->quantities, 0,
		 NUMBER_OF_TYPES * sizeof(t_quantity));
	  client->character->orientation = NORTH;
	  break;
	}
      i++;
    }
  if (i == server->game_data.nbr_of_teams)
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
  else
    write_to_buffer(&client->buffer_out, "ok\n", strlen("ok\n"));
  return (RETURN_SUCCESS);
}

int					define_client_type(t_server *server,
							   t_client *client,
							   char *input)
{
  if (strcmp(input, "GRAPHIC") == 0)
    {
      client->type = GRAPHIC;
      send_map_size(server, client, NULL);
      send_speed(server, client, NULL);
      send_map_content(server, client, NULL);
      send_team_names(server, client, NULL);
    }
  else if (initialize_drone(server, client, input) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
