/*
** action.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 10:53:45 2016 Barthelemy Gouby
** Last update Mon Jun 20 15:33:33 2016 Erwan Dupard
*/

#include "server.h"

void					add_action(t_action **action_list, t_action *new_action)
{
  t_action				*iterator;

  if (*action_list == NULL)
    {
      *action_list = new_action;
      printf("null add\n");
    }
  else
    {
      iterator = *action_list;
      while (iterator && iterator->next)
	iterator = iterator->next;
      iterator->next = new_action;
    }
}

t_action				*remove_action(t_action **action_list, t_action *action)
{
  t_action				*iterator;
  t_action				*next_action;

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
  free(action);
  return (next_action);
}
