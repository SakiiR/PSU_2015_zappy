/*
** map.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:52:50 2016 Barthelemy Gouby
** Last update Tue Jun  7 17:31:37 2016 Barthelemy Gouby
*/

#include <stdlib.h>
#include "server.h"

t_map 		*initialize_map(const unsigned int width, const unsigned int height)
{
  t_map		*map;
  t_case	*cases;
  unsigned int	i;

  i = 0;
  if (!(map = malloc(sizeof(*map))))
    return (NULL);
  if (!(cases = malloc(sizeof(*cases) * width * height)))
    return (NULL);
  while (i < width * height)
    {
      cases[i].quantities[FOOD] = 0;
      cases[i].quantities[LINEMATE] = 0;
      cases[i].quantities[DERAUMERE] = 0;
      cases[i].quantities[SIBUR] = 0;
      cases[i].quantities[MENDIANE] = 0;
      cases[i].quantities[PHIRAS] = 0;
      cases[i].quantities[THYSTAME] = 0;
      i++;
    }
  map->cases = cases;
  map->width = width;
  map->height = height;
  return (map);
}

t_case		*map_get_case_at(const unsigned int x, const unsigned int y, const t_map *map)
{
  unsigned int	index;

  index = y * map->width + x;
  if (index > map->height * map->width)
    return (NULL);
  return (&map->cases[index]);
}
