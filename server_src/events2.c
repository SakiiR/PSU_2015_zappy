/*
** events2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 15:43:26 2016 Erwan Dupard
** Last update Fri Jun 17 12:48:16 2016 Barthelemy Gouby
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

int					event_turn(t_server *server, va_list ap)
{
  t_client				*client;
  e_turn				turn;

  printf("executing turn\n");
  client = va_arg(ap, t_client *);
  turn = va_arg(ap, e_turn);
  if (turn == RIGHT)
    client->character->orientation++;
  else if (turn == LEFT)
    client->character->orientation--;
  if (client->character->orientation > 4)
    client->character->orientation = 1;
  else if (client->character->orientation < 1)
    client->character->orientation = 4;
  sprintf(server->buffer, "ppo %i %i %i %i\n",
	  client->character->id, 
	  client->character->current_case->x,
	  client->character->current_case->y,
	  client->character->orientation);
  graphic_broadcast(server, server->buffer);
  return (RETURN_SUCCESS);
}

int				event_advance(t_server *server, va_list ap)
{
  t_client
}
