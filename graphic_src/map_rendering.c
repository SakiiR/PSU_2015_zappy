/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
** Last update Wed Jun 22 16:05:04 2016 Thomas Billot
*/

#include "graphical.h"

int		map_rendering(t_render *render, t_map *map)
{
  int		i;
  int		map_x;
  int		map_y;
  
  i = -1;
  while (++i < (map->x * map->y))
    {
      map_x = i % map->x;
      map_y = i / map->x;
      display_texture(render,
		      &render->tileset[GRASS],
		      CONVERT_X(map_x, map_y) + (WIN_W / 2),
		      CONVERT_Y(map_x, map_y));
    }
  return (RETURN_SUCCESS);
}
