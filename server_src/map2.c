/*
** map2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 11:54:05 2016 Erwan Dupard
** Last update Fri Jun 17 13:23:31 2016 Barthelemy Gouby
*/

#include "server.h"

void					add_character_to_case(t_case *c, t_character *character)
{
  t_character				*iterator;

  iterator = c->characters;
  if (!iterator)
    c->characters = character;
  else
    {
      while (iterator->next_in_case)
 	iterator = iterator->next_in_case;
      iterator->next_in_case = character;
    }
}

void					remove_character_from_case(t_case *c, t_character *character)
{
  t_character				*iterator;

  if (character == c->characters)
    c->characters = character->next_in_case;
  else
    {
      iterator = c->characters;
      while (iterator->next_in_case)
	{
	  if (iterator->next_in_case  == character)
	    iterator->next_in_case = character->next_in_case;
	  iterator = iterator->next_in_case;
	}
    }
  character->next_in_case = NULL;
}

void					place_character_randomly(t_map *map,
								 t_character *character)
{
  t_u64					index;

  index = rand() % (map->width * map->height);
  character->current_case = &map->cases[index];
  add_character_to_case(character->current_case, character);
}
