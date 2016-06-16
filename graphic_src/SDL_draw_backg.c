/*
** SDL_draw_backg.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:31:27 2016 Thomas Beaudet
** Last update Thu Jun 16 16:50:12 2016 Thomas Beaudet
*/

#include <stdio.h>
#include "graphical.h"

void			draw_backg(t_res *ress)
{
  SDL_SetRenderDrawColor(ress->rend, 0, 204, 0, 255);
  SDL_RenderClear(ress->rend);
  SDL_RenderPresent(ress->rend);
}

void			put_delay(int delay)
{
  SDL_Delay(delay);
}
