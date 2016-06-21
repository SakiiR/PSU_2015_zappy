/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
** Last update Tue Jun 21 13:17:13 2016 Thomas Billot
*/

#include "graphical.h"

int		map_rendering(t_map *map)
{
  int		i;
  int		x;
  int		y;

  i = -1;
  while (++i < (map->x * map->y))
    {
      x = (i % map->x);
      y = (i / map->x);
    }
  (void)x;
  (void)y;
  (void)map;
  return (0);
}

int			draw(t_map *map)
{
  (void)map;
  return (0);
}
