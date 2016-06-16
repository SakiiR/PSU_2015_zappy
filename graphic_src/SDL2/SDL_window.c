/*
** SDL_window.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:23:26 2016 Thomas Beaudet
** Last update Thu Jun 16 16:51:28 2016 Thomas Beaudet
*/

#include <stdio.h>
#include "graphical.h"

int			sdl_create_win(t_res *ress, t_map *map)
{
  SDL_CreateWindowAndRenderer(x, y, 0, &ress->screen, &ress->rend);
  if (!ress->screen || !ress->rend)
    {
      fprintf(stderr,
	      "Problem encountered while creating windows -> SDL Error : %s\n",
	      SDL_GetError());
      SDL_Quit();
      return (-1);
    }
  return (0);
}
