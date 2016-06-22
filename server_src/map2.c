/*
** map2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 11:54:05 2016 Erwan Dupard
** Last update Wed Jun 22 15:02:36 2016 Erwan Dupard
*/

#include "server.h"

void					add_character_to_case(
							      t_case *c,
							      t_character *character)
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

void					remove_character_from_case(t_case *c,
								   t_character *character)
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
	    {
	      iterator->next_in_case = character->next_in_case;
	      break;
	    }
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

void					place_character_at_egg(t_map *map,
							       t_character *character,
							       t_egg **eggs)
{
  t_egg					*hatched_egg;

  hatched_egg = retrieve_hatched_egg(eggs);
  character->current_case = map_get_case_at(hatched_egg->x,
					    hatched_egg->y, map);
  add_character_to_case(character->current_case, character);
  free(hatched_egg);
}
