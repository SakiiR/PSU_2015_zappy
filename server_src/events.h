/*
** events.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:06:44 2016 Erwan Dupard
** Last update Thu Jun 16 18:20:47 2016 Erwan Dupard
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
    ETC
  }					e_event_type;

struct					s_action
{
  e_event_type				type;
  t_client				*origin;
  char					*argument;
  unsigned int				duration;
  struct s_action			*next;
};

void					add_action(t_action **action_list,
						   t_action *new_action);
t_action				*remove_action(t_action **action_list,
						       t_action *action);

typedef struct				s_event_handler
{
  e_event_type				type;
  int					(*f)(t_server *server,
					     va_list ap);
}					t_event_handler;

int				        trigger_event(t_server *server,
						      e_event_type type,
						      ...);

int					handle_events(t_server *server);

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

#endif /* ! EVENTS_H_ */
