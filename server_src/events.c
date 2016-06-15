/*
** events.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:04:49 2016 Erwan Dupard
** Last update Wed Jun 15 10:46:13 2016 Erwan Dupard
*/

#include "events.h"

int					event_new_player(t_server *server, va_list ap)
{
  int					i;

  i = -1;
  /*
   * Good way to iterate over clients ?
   */
  while (server->clients[++i].host_name)
    {
      if (server->clients[i].type == GRAPHIC)
	{
	  /* Send new player payload : "ppo #n X Y O\n" */
	}
    }
  (void)ap;
  return (RETURN_SUCCESS);
}
