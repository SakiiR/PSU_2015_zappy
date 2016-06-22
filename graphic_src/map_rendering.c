/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
** Last update Tue Jun 21 18:28:26 2016 Thomas Billot
*/

#include "graphical.h"

int		convert_x(int x, int y)
{
  int		screen_x;

  screen_x = (x - y) * (TILE_W / 2);
  return (screen_x);
}

int		convert_y(int x, int y)
{
  int		screen_y;

  screen_y = (x + y) * (TILE_H / 2);
  return (screen_y);
}

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
		      convert_x(map_x, map_y),
		      convert_y(map_x, map_y));
    }
  return (0);
}

int			draw(t_map *map)
{
  (void)map;
  return (0);
}
