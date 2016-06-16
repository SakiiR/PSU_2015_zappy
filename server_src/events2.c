/*
** events2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 15:43:26 2016 Erwan Dupard
** Last update Thu Jun 16 18:32:58 2016 Erwan Dupard
*/

#include "server.h"

int					event_player_expulsed(t_server *server, va_list ap)
{
  (void)server;
  (void)ap;
  return (RETURN_SUCCESS);
}

int					event_inventaire(t_server *server, va_list ap)
{
  t_client				*client;
  
  (void)server;
  client = (t_client *) va_arg(ap, void *);
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
  write_to_buffer(client->buffer_out, server->buffer, strlen(server-buffer));
  return (RETURN_SUCCESS);
}
