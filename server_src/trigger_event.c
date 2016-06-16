/*
** trigger_event.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 10:32:53 2016 Erwan Dupard
** Last update Thu Jun 16 12:56:20 2016 Barthelemy Gouby
*/

#include "server.h"

static const t_event_handler		g_events[] = {
  {NEW_PLAYER, &event_new_player},
  {BROADCAST, &event_broadcast},
  {END_INCANTATION, &event_end_incantation},
  {NEW_INCANTATION, &event_new_incantation},
  {LAY_EGG, &event_lay_egg},
  {PLAYER_EXPULSED, &event_player_expulsed},
  {0, NULL}
};

int				        trigger_event(t_server *server,
						      e_event_type type,
						      ...)
{
  va_list			        argp;
  int					i;

  va_start(argp, type);
  i = -1;
  while (g_events[++i].f)
    {
      if (type == g_events[i].type)
	{
	  g_events[i].f(server, argp);
	}
    }
  va_end(argp);
  return (RETURN_SUCCESS);
}
