/*
** events3.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 16:28:17 2016 Erwan Dupard
** Last update Fri Jun 17 16:32:23 2016 Erwan Dupard
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
