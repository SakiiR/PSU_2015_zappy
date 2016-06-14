/*
** map2.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun  9 19:15:32 2016 Barthelemy Gouby
** Last update Mon Jun 13 14:25:51 2016 Barthelemy Gouby
*/

#include "server.h"

void		place_character_randomly(t_map *map, t_character *character)
{
  unsigned int	index;
  t_character	*iterator;

  index = rand() % (map->width * map->height);
  character->current_case = &map->cases[index];
  iterator = character->current_case->characters;
  if (!iterator)
    character->current_case->characters = character;
  else
    {
      while (iterator->next_in_case)
	iterator = iterator->next_in_case;
      iterator->next_in_case = character;
    }
}
