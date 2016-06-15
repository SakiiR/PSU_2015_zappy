/*
** events.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:06:44 2016 Erwan Dupard
** Last update Wed Jun 15 13:35:52 2016 Barthelemy Gouby
*/

#ifndef EVENTS_H_
# define EVENTS_H_

# include <stdarg.h>

struct s_server;
typedef struct s_server t_server;

# include "server.h"

typedef enum
  {
    NEW_PLAYER,
    GRAPHIC_BROADCAST,
    BROADCAST,
    END_INCANTATION,
    NEW_INCANTATION,
    LAY_EGG,
    ETC
  }					e_event_type;

typedef struct				s_event_handler
{
  e_event_type				type;
  int					(*f)(t_server *server,
					     va_list ap); /* Var Args ! */
}					t_event_handler;

int				        trigger_event(t_server *server,
						      e_event_type type,
						      ...);

/*
 * Events Function Pointer
 */
int					event_new_player(struct s_server *server, va_list ap);
int					event_broadcast(struct s_server *server, va_list ap);
int					event_end_incantation(struct s_server *server, va_list ap);
int					event_new_incantation(struct s_server *server, va_list ap);
int					event_lay_egg(struct s_server *server, va_list ap);
int					event_graphic_broadcast(struct s_server *server, va_list ap);

#endif /* ! EVENTS_H_ */
