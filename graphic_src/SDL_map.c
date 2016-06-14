/*
** SDL_map.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sun Jun 12 11:17:17 2016 Thomas Beaudet
** Last update Mon Jun 13 18:45:54 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "SDL_map.h"

int		set_vals(t_sdl *s)
{
  s->color.r = 51;
  s->color.g = 255;
  s->color.b = 51;
  s->font = NULL;
  s->action = 1;
  s->win = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
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

void		drawLine(SDL_Surface *screen, int x0, int y0, int x1,
			 int y1, Uint32 pixel)
{
  int		i;
  double	x;
  double	y;

  i = 0;
  x = x1 - x0;
  y = y1 - y0;

  double	length = sqrt(x*x + y*y);
  double	addx = x / length;
  double	addy = y / length;

  x = x0;
  y = y0;
  for (i = 0; i < length; i++)
    {
      putpixel(screen, x, y, pixel);
      x += addx;
      y += addy;
    }
}

void		sdlEvent(t_sdl *s)
{
  while (SDL_PollEvent(&s->event))
    if (s->event.type == SDL_QUIT)
      s->action = 0;
    else if (s->event.type == SDL_QUIT)
      if (s->event.key.keysym.sym == SDLK_ESCAPE)
	s->action = 0;
}

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
	drawLine(s->win, 1931+(i*10), 100, 100, 100, s->pix);
      SDL_Flip(s->win);
      /* SDL_Delay(4000); */
      /*      s->pos.x = 50;
	      s->pos.y = 50;
	      SDL_BlitSurface(s->backg, NULL, s->win, &s->pos);
	      s->pos.x = WIDTH;
	      s->pos.y = HEIGHT;
	      SDL_BlitSurface(s->text, NULL, s->win, &s->pos);
	      SDL_Flip(s->win);*/
    }
}

void		SDL_quit(t_sdl *s)
{
  TTF_CloseFont(s->font);
  TTF_Quit();
  SDL_Quit();
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
