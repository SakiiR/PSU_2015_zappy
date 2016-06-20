/*
** SDL_window.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:23:26 2016 Thomas Beaudet
** Last update Fri Jun 17 16:32:20 2016 Thomas Beaudet
*/

#include <stdio.h>
#include "../graphical.h"

int			sdl_create_win(t_res *ress, t_map *map)
{
  SDL_CreateWindowAndRenderer(map->x, map->y, 0, &ress->screen, &ress->rend);
  if (!ress->screen || !ress->rend)
    {
      fprintf(stderr,
	      "Problem encountered while creating windows -> SDL Error : %s\n",
	      SDL_GetError());
      SDL_Quit();
      return (-1);
    }
  ress->texture = SDL_CreateTexture(ress->rend,
				    SDL_PIXELFORMAT_ARGB8888,
				    SDL_TEXTUREACCESS_STATIC,
				    map->X, map->y);
  ress->pixels = [map->x * map->y];
  memset(ress->pixels, 255, map->x * map->y * sizeof(Uint32));
  return (0);
}
