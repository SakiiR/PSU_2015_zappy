/*
** graphic_commands2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Jun 13 18:43:41 2016 Erwan Dupard
** Last update Sun Jun 26 17:43:54 2016 Erwan Dupard
*/

#include "server.h"

int					change_time_unit(t_server *server,
							 t_client *client,
							 char *operands)
{
  int					new_speed;

  if (operands && (new_speed = atoi(operands)) > 0)
    {
      server->game_data.speed = new_speed;
      set_time_speed(server);
    }
  send_speed(server, client, NULL);
  return (RETURN_SUCCESS);
}

t_client				*get_client_by_character_id(t_server *server,
								    unsigned int id)
{
  int					i;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket != 0 &&
	  server->clients[i].type == DRONE &&
	  server->clients[i].character->id == id)
	return (&server->clients[i]);
    }
  return (NULL);
}

int				        send_player_level(t_server *server,
							 t_client *client,
							 char *operands)
{
  t_client				*client_of_character;

  if (!operands ||
      !(client_of_character = get_client_by_character_id(server,
							 atoi(operands))))
    write_to_buffer(&client->buffer_out, "sbp\n", strlen("sbp\n"));
  else
    {
      sprintf(server->buffer, "plv %i %i\n",
	      client_of_character->character->id,
	      client_of_character->character->level);
      write_to_buffer(&client->buffer_out,
		      server->buffer,
		      strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}

int					send_player_inventory(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)))
{
  t_client				*client_of_character;

  if (!operands ||
      !(client_of_character = get_client_by_character_id(server,
							 atoi(operands))))
    write_to_buffer(&client->buffer_out, "sbp\n", strlen("sbp\n"));
  else
    {
      write_inventory_string(server, client->character);
      write_to_buffer(&client->buffer_out,
		      server->buffer,
		      strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}

int					send_player_position(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)))
{
  t_client				*client_of_character;

  if (!operands ||
      !(client_of_character = get_client_by_character_id(server,
							 atoi(operands))))
    write_to_buffer(&client->buffer_out, "sbp\n", strlen("sbp\n"));
  else
    {
      sprintf(server->buffer, "ppo %i %i %i %i\n",
	      client_of_character->character->id,
	      client_of_character->character->current_case->x,
	      client_of_character->character->current_case->y,
	      client_of_character->character->orientation + 1);
      write_to_buffer(&client->buffer_out,
		      server->buffer,
		      strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}
