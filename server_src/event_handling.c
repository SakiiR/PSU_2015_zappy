/*
** time.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/graphic_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jun 15 14:38:08 2016 Barthelemy Gouby
** Last update Sun Jun 26 17:43:03 2016 Erwan Dupard
*/

#include "server.h"

void			set_time_speed(t_server *server)
{
  double		length;

  length = 1.0 / server->game_data.speed;
  server->game_data.tick_length.tv_sec = (int) length;
  server->game_data.tick_length.tv_usec =
    (int)((length - (int) length) * 1000000);
  gettimeofday(&server->game_data.last_tick, NULL);
}

int			handle_actions(t_server *server)
{
  int			i;
  t_action		*next_action;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket != 0
	  && server->clients[i].type == DRONE
	  && server->clients[i].character->action_queue)
	{
	  next_action = server->clients[i].character->action_queue;
	  if (next_action->duration <= 0)
	    {
	      if (trigger_event(server,
				next_action->type,
				next_action->origin,
				next_action->argument) == RETURN_FAILURE)
		return (RETURN_FAILURE);
	      pop_action(&server->clients[i].character->action_queue);
	    }
	  else
	    next_action->duration--;
	}
    }
  return (RETURN_SUCCESS);
}

int			eggs_life_cycle(t_server *server)
{
  unsigned int		i;
  t_egg			*iterator;

  i = -1;
  while (++i < server->game_data.nbr_of_teams)
    {
      iterator = server->game_data.teams[i].eggs;
      while (iterator)
      	{
      	  if (!iterator->hatched)
      	    {
      	      if (iterator->timer <= 0)
		{
		  iterator->hatched = 1;
		  sprintf(server->buffer, "eht %i\n", iterator->id);
		  graphic_broadcast(server, server->buffer);
		}
      	      else
      		--iterator->timer;
      	    }
	  iterator = iterator->next;
      	}
    }
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
