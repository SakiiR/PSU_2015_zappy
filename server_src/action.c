/*
** action.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 10:53:45 2016 Barthelemy Gouby
** Last update Mon Jun 20 16:56:33 2016 Barthelemy Gouby
*/

#include "server.h"

void		add_action(t_action **action_queue, t_action *new_action)
{
  t_action				*iterator;

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
