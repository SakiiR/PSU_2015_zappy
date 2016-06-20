/*
** events3.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 16:28:17 2016 Erwan Dupard
** Last update Mon Jun 20 13:12:30 2016 Barthelemy Gouby
*/

#include "server.h"

t_ressource_name_correspondance		g_correspondances[7] = {{"nourriture", NOURRITURE},
								{"linemate", LINEMATE},
								{"deraumere", DERAUMERE},
								{"sibur", SIBUR},
								{"mendiane", MENDIANE},
								{"phiras", PHIRAS},
								{"thystame", THYSTAME}};

void					take_ressource(t_server *server,
						       t_client *client,
						       e_ressource_type type)
{
  printf("found ressource type\n");
  if (client->character->current_case->quantities[type] > 0)
    {
      client->character->current_case->quantities[type]--;
      client->character->quantities[type]++;
      sprintf(server->buffer, "pgt %i %i\n",
	      client->character->id,
	      type);
      graphic_broadcast(server, server->buffer);
      write_to_buffer(&client->buffer_out, "ok\n", strlen("ok\n"));
    }
  else
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
}

int					event_take_ressource(t_server *server, va_list ap)
{
  t_client			*client;
  char				*ressource_type;
  int				i;

  i = -1;
  client = va_arg(ap, t_client *);
  ressource_type = va_arg(ap, char *);
  printf("trying to take ressource: %s\n", ressource_type);
  while (++i < 7)
    {
      if (strcmp(ressource_type, g_correspondances[i].name) == 0)
	take_ressource(server, client, g_correspondances[i].type_identifier);
    }
  if (i == 7)
    write_to_buffer(&client->buffer_out, "ko\n", strlen("ko\n"));
  return (RETURN_SUCCESS);
}

int					event_throw_ressource(t_server *server, va_list ap)
{
  t_client			*client;

  (void) client;
  client = va_arg(ap, t_client *);
  (void) server;
  return (RETURN_SUCCESS);
}

int					event_inventaire(t_server *server, va_list ap)
{
  t_client				*client;
  
  (void)server;
  client = va_arg(ap, t_client *);
  printf("client : %p\n", (void *)client);
  sprintf(server->buffer,
	  "{nourriture %d"
	  ", sibur %d"
	  ", phiras %d"
	  ", linemate %d"
	  ", deraumere %d"
	  ", mendiane %d"
	  ", thystame %d}\n",
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

int					event_incantation(t_server *server, va_list ap)
{
  t_client				*client;

  (void)server;
  client = va_arg(ap, t_client *);
  if (try_incantation(client->character->current_case, client->character->level + 1) == RETURN_FAILURE)
    {
      printf("[-] Incantation Fail\n");
      return (RETURN_SUCCESS);
    }
  printf("[+] Incantation Success !\n");
  return (RETURN_SUCCESS);
}