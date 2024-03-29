/*
** action.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 10:53:45 2016 Barthelemy Gouby
** Last update Sun Jun 26 17:41:16 2016 Erwan Dupard
*/

#include "server.h"

int			number_of_actions(t_action *action_queue)
{
  int			number_of_actions;

  number_of_actions = -1;
  while (++number_of_actions && action_queue)
    action_queue = action_queue->next;
  return (number_of_actions);
}

void			add_action(t_action **action_queue,
				   t_action *new_action)
{
  t_action		*iterator;

  if (number_of_actions(*action_queue) < 10)
    {
      if (*action_queue == NULL)
	*action_queue = new_action;
      else
	{
	  iterator = *action_queue;
	  while (iterator && iterator->next)
	    iterator = iterator->next;
	  iterator->next = new_action;
	}
    }
}

void			pop_action(t_action **action_queue)
{
  t_action		*action;

  if (*action_queue)
    {
      action = *action_queue;
      *action_queue = (*action_queue)->next;
      free(action);
    }
}
