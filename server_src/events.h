/*
** events.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:06:44 2016 Erwan Dupard
** Last update Tue Jun 14 17:12:15 2016 Erwan Dupard
*/

#include "server.h"

#ifndef EVENTS_H_
# define EVENTS_H_

typedef enum
  {
    NEW_PLAYER,
    BROADCAST,
    ETC
  }					e_event_type;

typedef struct				s_event_handler
{
  e_event_type				type;
  int					(*f)(...); /* Var Args ! */
}					t_event_handler;

int					handle_event(e_event_type type, ...);

#endif /* ! EVENTS_H_ */
