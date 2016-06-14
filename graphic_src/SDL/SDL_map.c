/*
** SDL_map.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sun Jun 12 11:17:17 2016 Thomas Beaudet
** Last update Tue Jun 14 12:43:43 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "SDL_ressources.h"

int		set_vals(t_sdl *s)
{
  s->color.r = 51;
  s->color.g = 255;
  s->color.b = 51;
  s->font = NULL;
  s->player[] = NULL;
  s->action = 1;
  s->lines[] = NULL;
  s->win = SDL_SetVideoMode(S_WIDTH, S_HEIGHT, 32, SDL_HWSURFACE |
			    SDL_RESIZABLE | SDL_DOUBLEBUF);
  if (s->win == NULL)
    {
      fprintf(stderr, "Problem ecountered while setting video mode : %s\n",
	      SDL_GetError());
      exit (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("ZAPPY UNITED", NULL);
  s->font = TTF_OpenFont("FONTS/Arial.ttf", 200);
}

void		putpixel(SDL_Surface *screen, int x, int y, Uint32 pixel)
{
  int		bpp;
  Uint8		*p;

  bpp = screen->format->BytesPerPixel;
  p = (Uint8*)screen->pixels + y * screen->pitch + x * bpp;
  *(Uint32 *)p = pixel;
}

void		drawLine(t_sdl *s)
{
  int		i;

  i = 0;
  for (i = 0; i < 8; i++)
    {
    }
}

int		main()
{
  t_sdl		world;

  memset(&world, 0, sizeof(t_sdl));
  printf("memset : ok\n");
  set_vals(&world);
  printf("set_vals : ok\n");
  run(&world);
  printf("run : ok\n");
  SDL_quit(&world);
  printf("sdl_quit : ok\n");
  return (0);
}
