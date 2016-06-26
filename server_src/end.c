/*
** end.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sat Jun 25 19:14:57 2016 Erwan Dupard
** Last update Sun Jun 26 17:42:36 2016 Erwan Dupard
*/

#include "server.h"

int		end_game(t_server *server, t_client *emetter)
{
  end_command(emetter);
  sprintf(server->buffer, "seg %s\n", emetter->character->team->name);
  graphic_broadcast(server, server->buffer);
  return (RETURN_SUCCESS);
}

int		event_endgame(t_server *server, va_list ap)
{
  (void)server;
  (void)ap;
  exit(RETURN_SUCCESS);
  return (RETURN_SUCCESS);
}
