/*
** run_sdl.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 14 12:41:33 2016 Thomas Beaudet
** Last update Wed Jun 15 12:09:55 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "SDL_ressources.h"

int		run(t_sdl *s)
{
  int		i;
  int		x1;
  int		y1;
  int		x2;
  int		y2;

  i = 0;
  x1 = 300;
  y1 = 300;
  x2 = 100;
  y2 = 100;
  init_sdl();
  init_ttf();
  s->pix = 0x000000;
  while (s->action)
    {
      sdlEvent(s);
      SDL_FillRect(s->win, NULL, SDL_MapRGB(s->win->format, 102, 204, 0));
      for (int i = 0; i < 10; ++i)
	drawLine(s->win, 1931 + (i * 10), 100, 100, 100, s->pix);
      SDL_Flip(s->win);
    }
}
