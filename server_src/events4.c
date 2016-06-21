/*
** events4.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 20 14:13:49 2016 Barthelemy Gouby
** Last update Mon Jun 20 18:49:10 2016 Barthelemy Gouby
*/

#include "server.h"

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

int					event_lay_egg(t_server *server, va_list ap)
{
  t_client				*client;
  t_egg					*new_egg;

  (void)server;
  printf("egg hatched\n");
  client = va_arg(ap, t_client *);
  if (!(new_egg = malloc(sizeof(*new_egg))))
    return (RETURN_FAILURE);
  new_egg->id = server->game_data.next_egg_id++;
  new_egg->hatched = 0;
  new_egg->timer = 600;
  new_egg->x = client->character->current_case->x;
  new_egg->y = client->character->current_case->y;
  new_egg->next = NULL;
  add_egg(&client->character->team->eggs, new_egg);
  sprintf(server->buffer, "enw %i %i %i %i\n", new_egg->id, client->character->id, new_egg->x, new_egg->y);
  graphic_broadcast(server, server->buffer);
  printf("finished hatching\n");
  return (RETURN_SUCCESS);
}
