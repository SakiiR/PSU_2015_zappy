/*
** action.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 10:53:45 2016 Barthelemy Gouby
** Last update Mon Jun 20 15:28:07 2016 Barthelemy Gouby
*/

#include "server.h"

void		add_action(t_action **action_queue, t_action *new_action)
{
  t_action	*iterator;

  if (*action_queue == NULL)
    {
      *action_queue = new_action;
      printf("null add\n");
    }
  else
    {
      iterator = *action_queue;
      while (iterator && iterator->next)
	iterator = iterator->next;
      iterator->next = new_action;
    }
}

void		pop_action(t_action **action_queue)
{
  t_action	*action;

  if (*action_queue)
    {
      action = *action_queue;
      *action_queue = (*action_queue)->next;
      free(action);
    }
}

t_action	*remove_action(t_action **action_queue, t_action *action)
{
  t_action	*iterator;
  t_action	*next_action;

  if (action == *action_queue)
    {
      *action_queue = action->next;
      next_action = action->next;
    }
  else
    {
      iterator = *action_queue;
      while (iterator)
	{
	  if (iterator->next == action)
	    {
	      iterator->next = action->next;
	      next_action = action->next;
	      break;
	    }
	  iterator = iterator->next;
	}
    }
  free(action);
  return (next_action);
}
