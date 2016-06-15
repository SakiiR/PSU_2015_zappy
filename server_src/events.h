/*
** events.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:06:44 2016 Erwan Dupard
** Last update Wed Jun 15 10:37:36 2016 Erwan Dupard
*/

#ifndef EVENTS_H_
# define EVENTS_H_

# include <stdarg.h>
# include "server.h"

typedef enum
  {
    NEW_PLAYER,
    BROADCAST,
    ETC
  }					e_event_type;

typedef struct				s_event_handler
{
  e_event_type				type;
  int					(*f)(t_server *server, va_list ap); /* Var Args ! */
}					t_event_handler;

int				        trigger_event(t_server *server, e_event_type type, ...);

/*
 * Events Function Pointer
 */
int					event_new_player(t_server *server, va_list ap);

#endif /* ! EVENTS_H_ */
