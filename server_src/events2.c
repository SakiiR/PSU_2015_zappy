/*
** events2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 15:43:26 2016 Erwan Dupard
** Last update Fri Jun 17 14:21:39 2016 Barthelemy Gouby
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

void					change_coordinate(unsigned int *coordinate,
							  int change,
							  unsigned int max_value)
{
  
  if (*coordinate == 0 && change == -1)
    *coordinate = max_value - 1;
  else if (*coordinate + change >= max_value)
    *coordinate = 0;
  else
    *coordinate += change;
}

int					event_advance(t_server *server, va_list ap)
{
  t_client			*client;
  unsigned int			x;
  unsigned int			y;

  client = va_arg(ap, t_client *);
  x = client->character->current_case->x;
  y = client->character->current_case->y;
  /* if (client->character->orientation == NORTH) */
  /*   { */
  /*     if (y == 0) */
  /* 	y = server->game_data.map.height - 1; */
  /*     else */
  /* 	y--; */
  /*   } */
  /* if (client->character->orientation == SOUTH) */
  /*   { */
  /*     if (y + 1 >= server->game_data.map.height) */
  /* 	y = 0; */
  /*     else */
  /* 	y++; */
  /*   } */
  /* if (client->character->orientation == WEST) */
  /*   { */
  /*     if (x == 0) */
  /* 	x = server->game_data.map.width - 1; */
  /*     else */
  /* 	x--; */
  /*   } */
  /* if (client->character->orientation == EAST) */
  /*   { */
  /*     if (x + 1 >= server->game_data.map.width) */
  /* 	x = 0; */
  /*     else */
  /* 	x++; */
  /*   } */
  if (client->character->orientation == NORTH)
    change_coordinate(&y, -1, server->game_data.map.height);
  else if (client->character->orientation == SOUTH)
    change_coordinate(&y, 1, server->game_data.map.height);    
  else if (client->character->orientation == WEST)
    change_coordinate(&x, -1, server->game_data.map.width);
  else if (client->character->orientation == EAST)
    change_coordinate(&x, 1, server->game_data.map.width);
  remove_character_from_case(client->character->current_case,
			     client->character);
  client->character->current_case =
    map_get_case_at(x, y, &server->game_data.map);
  add_character_to_case(client->character->current_case, client->character);
  sprintf(server->buffer, "ppo %i %i %i %i\n",
	  client->character->id,
	  client->character->current_case->x,
	  client->character->current_case->y,
	  client->character->orientation);
  graphic_broadcast(server, server->buffer);
  return (RETURN_SUCCESS);
}
