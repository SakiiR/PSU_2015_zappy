/*
** events2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 15:43:26 2016 Erwan Dupard
** Last update Thu Jun 16 17:05:43 2016 Erwan Dupard
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
  return (RETURN_SUCCESS);
}
