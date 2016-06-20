/*
** get_player_by_id.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Mon Jun 20 14:58:21 2016 Thomas Billot
** Last update Mon Jun 20 15:02:58 2016 Thomas Billot
*/

#include "graphical.h"

t_character		*get_player_by_id(t_map *map, t_u64 id)
{
  int			i;

  i = -1;
  while (i <= (map->x * map->y))
    {
      if (map->tiles[i].characters->id == id)
	return (map->tiles[i].characters);
    }
  return (NULL);
}
