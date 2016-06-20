/*
** events4.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 20 14:13:49 2016 Barthelemy Gouby
** Last update Mon Jun 20 16:05:53 2016 Erwan Dupard
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

int					event_expulse(t_server *server, va_list ap)
{
  t_client				*client;
  t_case				*c;
  t_character				*iterator;

  client = va_arg(ap, t_client *);
  c = client->character->current_case;
  iterator = c->characters;
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

int					event_fork(t_server *server, va_list ap)
{
 t_client				*client;

  (void)server;
  client = va_arg(ap, t_client *);
  (void)client;
  return (RETURN_SUCCESS);
}
