/*
** client_identification.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 13 12:11:17 2016 Barthelemy Gouby
** Last update Tue Jun 21 12:07:59 2016 Barthelemy Gouby
*/

#include "server.h"

int					initialize_character(t_server *server,
							     t_client *client,
							     t_team *team)
{
  client->type = DRONE;
  if (!(client->character = malloc(sizeof(*(client->character)))))
    return (RETURN_FAILURE);
  client->character->level = 1;
  memset(client->character->quantities, 0,
	 NUMBER_OF_TYPES * sizeof(t_quantity));
  client->character->quantities[NOURRITURE] = 10;
  client->character->hunger_timer = 0;
  client->character->action_queue = NULL;
  client->character->orientation = NORTH;
  client->character->id = server->game_data.next_drone_id++;
  client->character->team = team;
  client->character->next_in_case = NULL;
  if (number_of_hatched_eggs(team->eggs) == 0)
    {
      place_character_randomly(&server->game_data.map, client->character);
      client->character->base_member = 1;
      team->base_members++;
    }
  else
    {
      place_character_at_egg(&server->game_data.map, client->character, &team->eggs);
      client->character->base_member = 0;
    }
  return (RETURN_SUCCESS);
}

int					add_character_if_possible(t_server *server,
								  t_client *client,
								  t_team *team)
{
  if (team->base_members >=
      team->max_members && number_of_hatched_eggs(team->eggs) == 0)
    write_to_buffer(&client->buffer_out, "0\n", strlen("0\n"));
  else
    {
      if (initialize_character(server,
			       client,
			       team) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      sprintf(server->buffer, "%i\n%i %i\n",
	      team->max_members - team->base_members + number_of_hatched_eggs(team->eggs),
	      server->game_data.map.width,
	      server->game_data.map.height);
      write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
      sprintf(server->buffer, "pnw %i %i %i %i %i %s\n",
	      client->character->id,
	      client->character->current_case->x,
	      client->character->current_case->y,
	      client->character->orientation,
	      client->character->level,
	      client->character->team->name);
      graphic_broadcast(server, server->buffer);
    }
  return (RETURN_SUCCESS);
}

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
	  if (add_character_if_possible(server,
					client,
					&server->game_data.teams[i])
	      == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	  break;
	}
      i++;
    }
  if (i == server->game_data.nbr_of_teams)
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
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
