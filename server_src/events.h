/*
** events.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:06:44 2016 Erwan Dupard
** Last update Tue Jun 21 15:27:55 2016 Barthelemy Gouby
*/

#ifndef EVENTS_H_
# define EVENTS_H_

# include <stdarg.h>

typedef enum
  {
    NEW_PLAYER,
    GRAPHIC_BROADCAST,
    BROADCAST,
    END_INCANTATION,
    NEW_INCANTATION,
    LAY_EGG,
    PLAYER_EXPULSED,
    THROW_RESOURCE,
    TAKE_RESOURCE,
    DIE_OF_HUNGER,
    LAYED_EGG,
    EGG_DIE_OF_HUNGER,
    END_OF_GAME,
    SERVER_MESSAGE,
    INVENTORY,
    VOIR,
    TURN,
    ADVANCE,
    INCANTATION,
    EXPULSE
  }					e_event_type;

struct					s_action
{
  e_event_type				type;
  t_client				*origin;
  void					*argument;
  unsigned int				duration;
  struct s_action			*next;
};

void					add_action(t_action **action_list,
						   t_action *new_action);
t_action				*remove_action(t_action **action_list,
						       t_action *action);
void					pop_action(t_action **action_queue);

typedef struct				s_event_handler
{
  e_event_type				type;
  int					(*f)(t_server *server,
					     va_list ap);
}					t_event_handler;

int				        trigger_event(t_server *server,
						      e_event_type type,
						      ...);

/*
 * Events Function Pointer
 */
int					event_new_player(t_server *server, va_list ap);
int					event_broadcast(t_server *server, va_list ap);
int					event_end_incantation(t_server *server, va_list ap);
int					event_new_incantation(t_server *server, va_list ap);
int					event_lay_egg(t_server *server, va_list ap);
int					event_player_expulsed(t_server *server, va_list ap);
int					event_voir(t_server *server, va_list ap);
int					event_inventaire(t_server *server, va_list ap);
int					event_turn(t_server *server, va_list ap);
int					event_advance(t_server *server, va_list ap);
int					event_incantation(t_server *server, va_list ap);
int					event_take_ressource(t_server *server, va_list ap);
int					event_throw_ressource(t_server *server, va_list ap);
int					event_expulse(t_server *server, va_list ap);
int					event_fork(t_server *server, va_list ap);

#endif /* ! EVENTS_H_ */
