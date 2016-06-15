/*
** graphic_commands.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Jun 12 17:17:56 2016 Barthelemy Gouby
** Last update Wed Jun 15 11:55:28 2016 Erwan Dupard
*/

#include "server.h"

int					send_map_size(t_server *server,
						      t_client *client,
						      char *operands __attribute__((unused)))
{
  sprintf(server->buffer, "msz %i %i\n",
	  server->game_data.map.width,
	  server->game_data.map.height);
  write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
  return (RETURN_SUCCESS);
}

int					send_speed(t_server *server,
						   t_client *client,
						   char *operands __attribute__((unused)))
{
  sprintf(server->buffer, "sgt %i\n", server->game_data.speed);
  write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
  return (RETURN_SUCCESS);
}

int					send_case_content(t_server *server,
							  t_client *client,
							  char *operands)
{
  char					*x;
  char					*y;
  t_case				*map_case;

  if (!operands)
    return (RETURN_SUCCESS);
  x = strtok(operands, " ");
  y = strtok(NULL, " ");
  if (x && y)
    {
      map_case = map_get_case_at(atoi(x),
				 atoi(y),
				 &server->game_data.map);
      sprintf(server->buffer, "bct %i %i %i %i %i %i %i %i %i\n",
	      atoi(x), atoi(y),
	      map_case->quantities[FOOD],
	      map_case->quantities[LINEMATE],
	      map_case->quantities[DERAUMERE],
	      map_case->quantities[SIBUR],
	      map_case->quantities[MENDIANE],
	      map_case->quantities[PHIRAS],
	      map_case->quantities[THYSTAME]);
      write_to_buffer(&client->buffer_out, server->buffer,
		      strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}

int					send_map_content(t_server *server,
							 t_client *client,
							 char *operands __attribute__((unused)))
{
  t_u64					i;
  i = 0;

  while (i  < server->game_data.map.width * server->game_data.map.height)
    {
      sprintf(server->buffer, "bct %i %i %i %i %i %i %i %i %i\n",
	      i % server->game_data.map.width,
	      i / server->game_data.map.width,
	      server->game_data.map.cases[i].quantities[FOOD],
	      server->game_data.map.cases[i].quantities[LINEMATE],
	      server->game_data.map.cases[i].quantities[DERAUMERE],
	      server->game_data.map.cases[i].quantities[SIBUR],
	      server->game_data.map.cases[i].quantities[MENDIANE],
	      server->game_data.map.cases[i].quantities[PHIRAS],
	      server->game_data.map.cases[i].quantities[THYSTAME]);
      write_to_buffer(&client->buffer_out,
		      server->buffer,
		      strlen(server->buffer));
      i++;
    }
  return (RETURN_SUCCESS);
}

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
