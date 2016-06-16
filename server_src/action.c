/*
** action.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 10:53:45 2016 Barthelemy Gouby
** Last update Thu Jun 16 15:07:04 2016 Barthelemy Gouby
*/

#include "server.h"

void		add_action(t_action **action_list, t_action *new_action)
{
  t_action	*iterator;

  if (!*action_list)
    *action_list = new_action;
  else
    {
      iterator = *action_list;
      while (iterator->next)
	iterator = iterator->next;
      iterator->next = new_action;
    }
}

t_action	*remove_action(t_action **action_list, t_action *action)
{
  t_action	*iterator;
  t_action	*next_action;

  if (action == *action_list)
    {
      *action_list = action->next;
      next_action = action->next;
    }
  else
    {
      iterator = *action_list;
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
  return (next_action);
}