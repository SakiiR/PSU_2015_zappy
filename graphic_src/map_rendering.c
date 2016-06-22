/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
** Last update Wed Jun 22 14:16:19 2016 Erwan Dupard
*/

#include "graphical.h"

/*
 * à mettre dans graphical.h
 */
# define CONVERT_X(x, y) ((x - y) * (TILE_W / 2))
# define CONVERT_Y(x, y) ((x + y) * (TILE_H / 2))

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
		      CONVERT_X(map_x, map_y),
		      CONVERT_Y(map_x, map_y));
    }
  return (0);
}

int			draw(t_map *map)
{
  (void)map;
  return (0);
}
