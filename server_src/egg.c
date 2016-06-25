/*
** egg.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 20 16:55:00 2016 Barthelemy Gouby
** Last update Sun Jun 26 00:16:42 2016 Erwan Dupard
*/

#include "server.h"

void		init_egg(t_egg *egg)
{
  egg->id = 0;
  egg->hatched = 0;
  egg->timer = 0;
  egg->x = 0;
  egg->y = 0;
  egg->next = NULL;
}

void		add_egg(t_egg **egg_list, t_egg *new_egg)
{
  t_egg				*iterator;

  if (*egg_list == NULL)
    *egg_list = new_egg;
  else
    {
      iterator = *egg_list;
      while (iterator->next)
	iterator = iterator->next;
      iterator->next = new_egg;
    }
}

t_egg		*remove_egg(t_egg **egg_list, t_egg *egg)
{
  t_egg		*iterator;

  iterator = *egg_list;
  if (!iterator)
    return (NULL);
  if (*egg_list == egg)
    {
      *egg_list = egg->next;
      return (*egg_list);
    }
  while (iterator && iterator->next)
    {
      if (iterator->next == egg)
	iterator->next = egg->next;
      free(egg);
    }
  return (*egg_list);
}

int		number_of_hatched_eggs(t_egg *egg_list)
{
  int		number_of_eggs;

  number_of_eggs = 0;
  while (egg_list)
    {
      if (egg_list->hatched)
	++number_of_eggs;
      egg_list = egg_list->next;
    }
  return (number_of_eggs);
}

t_egg		*retrieve_hatched_egg(t_egg **egg_list)
{
  t_egg		*iterator;
  t_egg		*hatched_egg;

  hatched_egg = NULL;
  if ((*egg_list)->hatched)
    {
      hatched_egg = *egg_list;
      *egg_list = (*egg_list)->next;
    }
  else
    {
      iterator = *egg_list;
      while (iterator->next)
	{
	  if (iterator->next->hatched)
	    {
	      hatched_egg = iterator->next;
	      iterator->next = hatched_egg->next;
	      break;
	    }
	  iterator = iterator->next;
	}
    }
  return (hatched_egg);
}
