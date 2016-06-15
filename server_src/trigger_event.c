/*
** trigger_event.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 10:32:53 2016 Erwan Dupard
** Last update Wed Jun 15 10:38:05 2016 Erwan Dupard
*/

#include "events.h"

static const t_event_handler		g_events[] = {
  {NEW_PLAYER, &event_new_player},
  {0, NULL}
};

int				        trigger_event(t_server *server, e_event_type type, ...)
{
  va_list			        argp;
  int					i;

  va_start(argp, type);
  i = -1;
  while (g_events[++i].f)
    {
      if (type == g_events[i].type)
	g_events[i].f(server, argp);
    }
  va_end(argp);
  return (RETURN_SUCCESS);
}
