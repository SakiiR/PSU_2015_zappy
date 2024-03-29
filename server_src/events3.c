/*
** events3.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 16:28:17 2016 Erwan Dupard
** Last update Sun Jun 26 17:42:56 2016 Erwan Dupard
*/

#include "server.h"

t_ressource_name_c			g_correspondances[] = {
  {"nourriture", NOURRITURE},
  {"linemate", LINEMATE},
  {"deraumere", DERAUMERE},
  {"sibur", SIBUR},
  {"mendiane", MENDIANE},
  {"phiras", PHIRAS},
  {"thystame", THYSTAME},
  {NULL, 10}
};

void				take_ressource(t_server *server,
					       t_client *client,
					       e_ressource_type type)
{
  if (client->character->current_case->quantities[type] > 0)
    {
      client->character->current_case->quantities[type]--;
      client->character->quantities[type]++;
      sprintf(server->buffer,
	      "pgt %i %i\n",
	      client->character->id,
	      type);
      graphic_broadcast(server, server->buffer);
      write_inventory_string(server, client->character);
      graphic_broadcast(server, server->buffer);
      write_case_content_string(server,
				client->character->current_case->x,
				client->character->current_case->y);
      graphic_broadcast(server, server->buffer);
      write_to_buffer(&client->buffer_out, "ok\n", strlen("ok\n"));
    }
  else
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
}

int				event_take_ressource(t_server *server, va_list ap)
{
  t_client			*client;
  char				*ressource_type;
  int				i;

  i = -1;
  printf("[^] Take resource.\n");
  client = va_arg(ap, t_client *);
  ressource_type = va_arg(ap, char *);
  while (++i < 7)
    {
      if (strcmp(ressource_type, g_correspondances[i].name) == 0)
	{
	  take_ressource(server, client, g_correspondances[i].type_identifier);
	  break;
	}
    }
  if (i == 7)
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
  return (RETURN_SUCCESS);
}

void				throw_ressource(t_server *server,
						t_client *client,
						e_ressource_type type)
{
  if (client->character->quantities[type] > 0)
    {
      client->character->quantities[type]--;
      client->character->current_case->quantities[type]++;
      sprintf(server->buffer, "pdr %i %i\n",
	      client->character->id,
	      type);
      graphic_broadcast(server, server->buffer);
      write_inventory_string(server, client->character);
      graphic_broadcast(server, server->buffer);
      write_case_content_string(server,
				client->character->current_case->x,
				client->character->current_case->y);
      graphic_broadcast(server, server->buffer);
      write_to_buffer(&client->buffer_out, "ok\n", strlen("ok\n"));
    }
  else
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
}

int				event_throw_ressource(t_server *server, va_list ap)
{
  t_client			*client;
  char				*ressource_type;
  int				i;

  i = -1;
  client = va_arg(ap, t_client *);
  ressource_type = va_arg(ap, char *);
  printf("[^] Throwing resource.\n");
  while (++i < 7)
    {
      if (strcmp(ressource_type, g_correspondances[i].name) == 0)
	{
	  throw_ressource(server, client, g_correspondances[i].type_identifier);
	  break;
	}
    }
  if (i == 7)
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
  return (RETURN_SUCCESS);
}

int				event_inventaire(t_server *server, va_list ap)
{
  t_client			*client;

  (void)server;
  printf("[^] Inventory.\n");
  client = va_arg(ap, t_client *);
  sprintf(server->buffer,
	  "{nourriture %d"
	  ",sibur %d"
	  ",phiras %d"
	  ",linemate %d"
	  ",deraumere %d"
	  ",mendiane %d"
	  ",thystame %d}\n",
	  client->character->quantities[NOURRITURE],
	  client->character->quantities[SIBUR],
	  client->character->quantities[PHIRAS],
	  client->character->quantities[LINEMATE],
	  client->character->quantities[DERAUMERE],
	  client->character->quantities[MENDIANE],
	  client->character->quantities[THYSTAME]
	  );
  write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
  return (RETURN_SUCCESS);
}
