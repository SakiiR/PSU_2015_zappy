/*
** map2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 11:54:05 2016 Erwan Dupard
** Last update Thu Jun 16 13:48:25 2016 Erwan Dupard
*/

#include "server.h"

void					place_character_randomly(t_map *map,
								 t_character *character)
{
  t_u64					index;
  t_character				*iterator;

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
