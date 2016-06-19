/*
** events3.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 16:28:17 2016 Erwan Dupard
** Last update Sun Jun 19 17:50:40 2016 Barthelemy Gouby
*/

#include "server.h"

int					event_take(t_server *server, va_list ap)
{
  t_client			*client;

  client = va_arg(ap, t_client *);
  (void) server;
  (void) client;
  return (RETURN_SUCCESS);
}

int					event_throw(t_server *server, va_list ap)
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
	  "{food %d"
	  ", sibur %d"
	  ", phiras %d"
	  ", linemate %d"
	  ", deraumere %d"
	  ", mendiane %d"
	  ", thystame %d}\n",
	  client->character->quantities[FOOD],
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
