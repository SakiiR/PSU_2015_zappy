/*
** graphic_commands.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Jun 12 17:17:56 2016 Barthelemy Gouby
** Last update Sat Jun 25 15:04:36 2016 Erwan Dupard
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

void					write_case_content_string(t_server *server,
								  int x,
								  int y)
{
  t_case				*map_case;

  map_case = map_get_case_at(x,
			     y,
			     &server->game_data.map);
  sprintf(server->buffer, "bct %i %i %i %i %i %i %i %i %i\n",
	  x, y,
	  map_case->quantities[NOURRITURE],
	  map_case->quantities[LINEMATE],
	  map_case->quantities[DERAUMERE],
	  map_case->quantities[SIBUR],
	  map_case->quantities[MENDIANE],
	  map_case->quantities[PHIRAS],
	  map_case->quantities[THYSTAME]);
}

int					send_case_content(t_server *server,
							  t_client *client,
							  char *operands)
{
  char					*x;
  char					*y;

  if (!operands)
    return (RETURN_SUCCESS);
  x = strtok(operands, " ");
  y = strtok(NULL, " ");
  if (x && y)
    {
      write_case_content_string(server, atoi(x), atoi(y));
      write_to_buffer(&client->buffer_out, server->buffer,
		      strlen(server->buffer));
    }
  return (RETURN_SUCCESS);
}

int					send_map_content(t_server *server,
							 t_client *client,
							 char *operands __attribute__((unused)))
{
  int					i;

  i = 0;
  while (i  < server->game_data.map.width * server->game_data.map.height)
    {
      sprintf(server->buffer, "bct %i %i %i %i %i %i %i %i %i\n",
	      i % server->game_data.map.width,
	      i / server->game_data.map.width,
	      server->game_data.map.cases[i].quantities[NOURRITURE],
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
