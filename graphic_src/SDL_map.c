/*
** SDL_map.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sun Jun 12 11:17:17 2016 Thomas Beaudet
** Last update Mon Jun 13 13:18:22 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "SDL_map.h"

int		set_vals(t_sdl *s)
{
  printf("window 1\n");
  s->color.r = 255;
  s->color.g = 255;
  s->color.b = 255;
  s->text = NULL;
  s->backg = NULL;
  s->font = NULL;
  s->action = 1;
  s->backg = IMG_Load("../Media/anonymous->jpg");
  s->win = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  printf("window 2\n");
  printf("window 3\n");
  SDL_WM_SetCaption("ZAPPY UNITED", NULL);
  s->font = TTF_OpenFont("../FONTS/Arial.ttf", 40);
  s->text = TTF_RenderText_Blended(s->font, "Zappy Maggle !", s->color);
}

int		init_sdl()
{
  printf("window if\n");
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      printf("window if1\n");
      fprintf(stderr, "\nProblem when SDL_init: %s\n", SDL_GetError());
      return (1);
    }
  exit (EXIT_FAILURE);
  //atexit(&SDL_Quit);
}

int		init_ttf()
{
  if (TTF_Init() == -1)
    {
      fprintf(stderr, "\nProblem when TTF init: %s\n", TTF_GetError());
      return (1);
    }
  exit (EXIT_FAILURE);
  //atexit(TTF_Quit);

}

int		run(t_sdl *s)
{
  init_sdl();
  init_ttf();
  printf("run 1\n");
  while (s->action)
    {
      printf("run while\n");
      SDL_WaitEvent(&s->event);
      switch (s->event.type)
	{
	case SDL_QUIT:
	  s->action = 0;
	  break;
	}
      printf("run 2\n");
      SDL_FillRect(s->win, NULL, SDL_MapRGB(s->win->format,  255, 255, 255));

      s->pos.x = 0;
      s->pos.y = 0;
      SDL_BlitSurface(s->backg, NULL, s->win, &s->pos);
      printf("run 3\n");
      s->pos.x = WIDTH;
      s->pos.y = HEIGHT;
      SDL_BlitSurface(s->text, NULL, s->win, &s->pos);
      SDL_Flip(s->win);
      printf("run 4\n");
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

  memset(&world, 0, sizeof(t_sdl));
  printf("1\n");
  // init();
  set_vals(&world);
  printf("2\n");
  run(&world);
  printf("3\n");
  SDL_quit(&world);
  printf("4\n");
  return (0);
}
