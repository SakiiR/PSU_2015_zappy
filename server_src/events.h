/*
** events.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:06:44 2016 Erwan Dupard
** Last update Wed Jun 15 16:53:49 2016 Erwan Dupard
*/

#ifndef EVENTS_H_
# define EVENTS_H_

# include <stdarg.h>

/*
 * Events Functions
 */
int					event_new_player(t_server *server, va_list ap);
int					event_broadcast(t_server *server, va_list ap);
int					event_end_incantation(t_server *server, va_list ap);
int					event_new_incantation(t_server *server, va_list ap);
int					event_lay_egg(t_server *server, va_list ap);
int					event_graphic_broadcast(t_server *server, va_list ap);
int					event_player_expulsed(t_server *server, va_list ap);

#endif /* ! EVENTS_H_ */
