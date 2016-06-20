/*
** events4.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 20 14:13:49 2016 Barthelemy Gouby
** Last update Mon Jun 20 15:26:08 2016 Barthelemy Gouby
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

int					event_fork(t_server *server, va_list ap)
{
 t_client				*client;

  (void)server;
  client = va_arg(ap, t_client *);
  (void)client;
  return (RETURN_SUCCESS);
}
