/*
** map2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 15 11:54:05 2016 Erwan Dupard
** Last update Sat Jun 25 15:18:58 2016 Erwan Dupard
*/

#include "server.h"

void					add_character_to_case(t_case *c,
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

int					place_character_at_egg(t_map *map,
							       t_character *character,
							       t_egg **eggs)
{
  int					egg_id;
  t_egg					*hatched_egg;

  hatched_egg = retrieve_hatched_egg(eggs);
  character->current_case = map_get_case_at(hatched_egg->x,
					    hatched_egg->y, map);
  add_character_to_case(character->current_case, character);
  egg_id = hatched_egg->id;
  free(hatched_egg);
  return (egg_id);
}

void					text_display_map(t_map *map)
{
  int					i;

  i = 0;
  while (i < map->width * map->height)
    {
      printf("--------- case at x: %i y: %i\n",
	     i % map->height,
	     i / map->height);
      printf("Food: %i\n", map->cases[i].quantities[NOURRITURE]);
      printf("Linemate: %i\n", map->cases[i].quantities[LINEMATE]);
      printf("Deraumere: %i\n", map->cases[i].quantities[DERAUMERE]);
      printf("Sibur: %i\n", map->cases[i].quantities[SIBUR]);
      printf("Mendiane: %i\n", map->cases[i].quantities[MENDIANE]);
      printf("Phiras: %i\n", map->cases[i].quantities[PHIRAS]);
      printf("Thystame: %i\n", map->cases[i].quantities[THYSTAME]);
      i++;
    }
}
