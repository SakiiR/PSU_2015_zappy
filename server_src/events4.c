/*
** events4.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 22 14:57:17 2016 Erwan Dupard
** Last update Sun Jun 26 17:26:53 2016 Erwan Dupard
*/

#include "server.h"

static int				check_incantation_event(t_character **characters,
								t_client *client,
								t_incantation *incantation,
								t_server *server)
{
  if (check_characters_incase(client->character->current_case,
			      characters) == RETURN_FAILURE)
    {
      incantation_failed(server, client);
      return (RETURN_FAILURE);
    }
  if (check_resources(client->character->current_case,
		      incantation) == RETURN_FAILURE)
    {
      incantation_failed(server, client);
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

int					event_incantation(t_server *server, va_list ap)
{
  t_client				*client;
  t_character				**characters;
  t_incantation				*incantation;

  client = va_arg(ap, t_client *);
  characters = va_arg(ap, t_character **);
  incantation = get_incantation_by_level(client->character->level + 1);
  printf("[+] Incantation !\n");
  if (check_incantation_event(characters,
			      client,
			      incantation,
			      server) == RETURN_FAILURE)
    {
      printf("[-] Incantation Failure :(\n");
      return (RETURN_FAILURE);
    }
  do_incantation(client->character->current_case, incantation);
  incantation_broadcast_e(server, client, characters);
  free(characters);
  sprintf(server->buffer, "niveau actuel : %d\n", client->character->level);
  write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
  if (incantation->level >= 8)
    return (end_game(server, client));
  return (RETURN_SUCCESS);
}

int					event_expulse(t_server *server,
						      va_list ap)
{
  t_client				*client;
  t_case				*c;
  t_character				*iterator;

  client = va_arg(ap, t_client *);
  c = client->character->current_case;
  iterator = c->characters;
  printf("[^] Expulse.\n");
  while (iterator)
    {
      if (iterator->id != client->character->id)
	expulse_player(&server->game_data.map,
		       iterator,
		       client->character->orientation);
      iterator = iterator->next_in_case;
    }
  return (RETURN_SUCCESS);
}

int					event_lay_egg(t_server *server
						      __attribute__((unused)),
						      va_list ap)
{
  t_client				*client;
  t_egg					*new_egg;

  client = va_arg(ap, t_client *);
  printf("[^] Lay egg.\n");
  if ((new_egg = malloc(sizeof(*new_egg))) == NULL)
    return (RETURN_FAILURE);
  init_egg(new_egg);
  new_egg->id = server->game_data.next_egg_id++;
  new_egg->hatched = 0;
  new_egg->timer = 600;
  new_egg->x = client->character->current_case->x;
  new_egg->y = client->character->current_case->y;
  new_egg->next = NULL;
  add_egg(&client->character->team->eggs, new_egg);
  write_to_buffer(&client->buffer_out, "ok\n", 3);
  sprintf(server->buffer, "enw %i %i %i %i\n", new_egg->id,
	  client->character->id,
	  new_egg->x,
	  new_egg->y);
  graphic_broadcast(server, server->buffer);
  return (RETURN_SUCCESS);
}
