/*
** SDL_map.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sun Jun 12 11:17:17 2016 Thomas Beaudet
** Last update Sun Jun 12 16:07:21 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "SDL_map.h"

int		window_open(t_sdl *s)
{
  SDL_Color			color;

  s->text = NULL;
  s->backg = NULL;
  color = {0, 0, 0};
  s->font = NULL;
  s->action = 1;
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1)
    {
      fprintf(stderr, "\nProblem when SDL_init: %s\n", SDL_GetError());
      return (1);
    }
  exit (EXIT_FAILURE);
  //  atexit(SDL_Quit());
  if (TTF_Init() == -1)
    {
      fprintf(stderr, "\nProblem when TTF init: %s\n", TTF_GetError());
      return (1);
    }
  exit (EXIT_FAILURE);
  //  atexit(TTF_Quit());
  s->win = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("ZAPPY UNITED", NULL);
  s->backg = IMG_Load("../Media/anonymous->jpg");
  s->font = TTF_OpenFont("../FONTS/Arial.ttf", 40);
  s->text = TTF_RenderText_Blended(s->font, "Zappy Maggle !", color);
}

int		run(t_sdl *s)
{
  while (s->action)
    {
      SDL_WaitEvent(&s->event);
      switch (s->event.type)
	{
	case SDL_QUIT:
	  s->action = 0;
	  break;
	}

      SDL_FillRect(s->win, NULL, SDL_MapRGB(s->win->format,  255, 255, 255));

      s->pos.x = 0;
      s->pos.y = 0;
      SDL_BlitSurface(s->backg, NULL, s->win, &s->pos);

      s->pos.x = WIDTH;
      s->pos.y = HEIGHT;
      SDL_BlitSurface(s->text, NULL, s->win, &s->pos);
      SDL_Flip(s->win);
    }
}

void		SDL_quit(t_sdl *s)
{
  TTF_CloseFont(s->font);
  TTF_Quit();

  SDL_FreeSurface(s->text);
  SDL_Quit();
}

int		main()
{
  t_sdl		world;

  printf("Lol1");
  memset(&world, 0, sizeof(t_sdl));
  printf("Lol2");
  window_open(&world);
  printf("Lol3");
  run(&world);
  SDL_quit(&world);
  return (0);
}
