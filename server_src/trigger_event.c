/*
** trigger_event.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 10:32:53 2016 Erwan Dupard
** Last update Sun Jun 26 17:20:13 2016 Karine Aknin
*/

#include "server.h"

static const t_event_handler		g_events[] = {
  {BROADCAST, &event_broadcast},
  {LAY_EGG, &event_lay_egg},
  {PLAYER_EXPULSED, &event_player_expulsed},
  {TAKE_RESOURCE, &event_take_ressource},
  {THROW_RESOURCE, &event_throw_ressource},
  {INVENTORY, &event_inventaire},
  {TURN, &event_turn},
  {ADVANCE, &event_advance},
  {INCANTATION, &event_incantation},
  {EXPULSE, &event_expulse},
  {VOIR, &event_voir},
  {END_GAME, &event_endgame},
  {0, NULL}
};

int					trigger_event(t_server *server,
						      e_event_type type,
						      ...)
{
  va_list				argp;
  int					i;

  va_start(argp, type);
  i = -1;
  while (g_events[++i].f)
    {
      if (type == g_events[i].type)
	{
	  if (g_events[i].f(server, argp) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
    }
  va_end(argp);
  return (RETURN_SUCCESS);
}
