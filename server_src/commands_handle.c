/*
** commands_handle.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed May 18 16:39:43 2016 Erwan Dupard
** Last update Sun Jun 12 19:21:51 2016 Erwan Dupard
*/

#include "server.h"

const static t_command			g_commands[] = {
  {NULL, NULL, 0}
};

int					define_client_type(t_server *server,
							   t_client *client,
							   char *input)
{
  unsigned int				i;

  i = 0;
  if (strcmp(input, "GRAPHIC") == 0)
    {
      client->type = GRAPHIC;
      send_map_size(server, client, NULL);
      send_speed(server, client, NULL);
      send_map_content(server, client, NULL);
      send_team_names(server, client, NULL);
    }
  else
    {
      while (i < server->game_data.nbr_of_teams)
	{
	  if (strcmp(input, server->game_data.teams[i].name) == 0)
	    {
	      client->type = DRONE;
	      if (!(client->character = malloc(sizeof(*(client->character)))))
		return (RETURN_FAILURE);
	      client->character->level = 1;
	      memset(client->character->quantities, 0,
		     NUMBER_OF_TYPES * sizeof(quantity));
	      client->character->orientation = UP;
	      break;
	    }
	  i++;
	}
      if (i == server->game_data.nbr_of_teams)
	write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
      else
	write_to_buffer(&client->buffer_out, "ok\n", strlen("ok\n"));
    }
  return (RETURN_SUCCESS);
}

int					handle_command(char *input,
						       t_server *server,
						       t_client *client)
{
  int					i;
  char					*command_name;
  char					*operands;

  if (strlen(input) > 1)
      input[strlen(input) - 1] = 0;
  if (client->type == UNSPECIFIED)
    define_client_type(server, client, input);
  else
    {
      command_name = strtok(input, " ");
      operands = strtok(NULL, "\n");
      while (g_commands[++i].command != NULL)
	{
	  if (strcmp(g_commands[i].command, command_name) == RETURN_SUCCESS)
	    {
	      return (g_commands[i].f(operands, server, client));
	    }
	}
    }
  return (RETURN_SUCCESS);
}
