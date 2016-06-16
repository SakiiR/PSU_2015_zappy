/*
** time.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/graphic_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jun 15 14:38:08 2016 Barthelemy Gouby
** Last update Thu Jun 16 16:07:05 2016 Barthelemy Gouby
*/

#define _BSD_SOURCE

#include <sys/time.h>
#include "server.h"

int			handle_actions(t_server *server)
{
  t_action		*iterator;
  struct timeval	now;
  struct timeval	interval;

  gettimeofday(&now, NULL);
  iterator = server->game_data.pending_actions;
  while (iterator)
    {
      timersub(&now, &iterator->start_of_action, &interval);
      if (!timercmp(&interval, &iterator->length_of_action, <))
	{
	  /* if (trigger_event(server, */
	  /* 		    iterator->type, */
	  /* 		    iterator->origin, */
	  /* 		    iterator->argument) == RETURN_FAILURE); */
	  printf("action executed\n");
	  iterator = remove_action(&server->game_data.pending_actions, iterator);
	}
      else
	iterator = iterator->next;
    }
  return (RETURN_SUCCESS);
}

int			player_food_consumption(t_server *server)
{
  (void) server;
  return (RETURN_SUCCESS);
}

int			eggs_life_cycle(t_server *server)
{
  (void) server;
  return (RETURN_SUCCESS);
}

int			handle_events(t_server *server)
{
  handle_actions(server);
  player_food_consumption(server);
  eggs_life_cycle(server);
  return (RETURN_SUCCESS);
}
