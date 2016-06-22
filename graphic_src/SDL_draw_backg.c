/*
** SDL_draw_backg.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:31:27 2016 Thomas Beaudet
** Last update Wed Jun 22 14:36:50 2016 Thomas Billot
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
      fprintf(stderr,
	      "Problem encountered while clearing renderer -> SDL Error : %s\n",
	      SDL_GetError());
      SDL_Quit();
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

void			put_delay(int delay)
{
  SDL_Delay(delay);
}
