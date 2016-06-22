/*
** SDL_window.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:23:26 2016 Thomas Beaudet
** Last update Wed Jun 22 14:37:39 2016 Thomas Billot
*/

#include <stdio.h>
#include "graphical.h"

int			sdl_create_win(t_render *ress)
{
  SDL_CreateWindowAndRenderer(WIN_W, WIN_H, 0, &ress->screen, &ress->rend);
  if (!ress->screen || !ress->rend)
    {
      fprintf(stderr,
	      "Problem encountered while creating windows -> SDL Error : %s\n",
	      SDL_GetError());
      SDL_Quit();
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
