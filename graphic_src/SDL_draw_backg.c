/*
** SDL_draw_backg.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:31:27 2016 Thomas Beaudet
** Last update Tue Jun 21 18:14:19 2016 Thomas Beaudet
*/

#include <stdio.h>
#include "graphical.h"

void			draw_backg(t_render *ress)
{
  SDL_SetRenderDrawColor(ress->rend, 0, 204, 0, 255);
  SDL_RenderClear(ress->rend);
  SDL_RenderPresent(ress->rend);
}

int			clear_surface(t_render *ress)
{
  if ((SDL_RenderClear(ress->rend)) < 0)
    {
      fprintf(stderr, "Problem encountered while clearing renderer -> SDL Error : %s\n",
	      SDL_GetError());
      SDL_Quit();
      return (-1);
    }
  return (0);
}

void			put_delay(int delay)
{
  SDL_Delay(delay);
}

void			draw_loop(/*t_render *ress,*/ t_map *map)
{
  int			i;
  int			j;
  int			map_size;
  int			t_map_size;

  i = 0;
  map_size = map->x * map->y;
  t_map_size = map->x;
  while (i < map_size)
    {
      j = t_map_size;
      while (j >= 0)
	{
	  j--;
	}
      i++;
    }
}
