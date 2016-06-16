/*
** time.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/graphic_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jun 15 14:38:08 2016 Barthelemy Gouby
** Last update Thu Jun 16 17:26:57 2016 Barthelemy Gouby
*/

#define _BSD_SOURCE

#include <sys/time.h>
#include "server.h"

void			initialize_time(t_server *server)
{
  double		length;

  length = 1.0 / server->game_data.speed;
  server->game_data.tick_length.tv_sec = (int) length;
  server->game_data.tick_length.tv_usec = (int)((length - (int) length) * 1000000);
  gettimeofday(&server->game_data.last_tick);
}

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
  return (RETURN_SUCCESS);
}

int			eggs_life_cycle(t_server *server)
{
  (void) server;
  return (RETURN_SUCCESS);
}

int			handle_events(t_server *server)
{
  struct timeval	now;
  struct timeval	interval;

  gettimeofday(&now, NULL);
  timersub(&now, &server->game_data.last_tick, &interval);
  if (!timercmp(&interval, &server->game_data.tick_length, <))
    {
      server->game_data.last_tick = now;
      if (handle_actions(server) == RETURN_FAILURE
	  || player_food_consumption(server) == RETURN_FAILURE
	  || eggs_life_cycle(server) == RETURN_FAILURE)
	return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
