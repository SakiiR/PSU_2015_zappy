/*
** graphic_commands3.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sat Jun 25 15:04:18 2016 Erwan Dupard
** Last update Sat Jun 25 15:05:02 2016 Erwan Dupard
*/

#include "server.h"

int					send_team_names(t_server *server,
							t_client *client,
							char *operands __attribute__((unused)))
{
  t_u64					i;

  i = 0;
  while (i < server->game_data.nbr_of_teams)
    {
      sprintf(server->buffer, "tna %s\n", server->game_data.teams[i++].name);
      write_to_buffer(&client->buffer_out,
		      server->buffer,
		      strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}

void					write_inventory_string(t_server *server,
							       t_character *character)
{
  sprintf(server->buffer,
	  "pin %i %i %i %i %i %i %i %i %i %i\n",
	  character->id,
	  character->current_case->x,
	  character->current_case->y,
	  character->quantities[NOURRITURE],
	  character->quantities[LINEMATE],
	  character->quantities[DERAUMERE],
	  character->quantities[SIBUR],
	  character->quantities[MENDIANE],
	  character->quantities[PHIRAS],
	  character->quantities[THYSTAME]);
}
