/*
** quit_sdl.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 14 12:35:49 2016 Thomas Beaudet
** Last update Wed Jun 15 10:28:20 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "SDL_ressources.h"

void		SDL_quit(t_sdl *s)
{
  TTF_CloseFont(s->font);
  TTF_Quit();
  SDL_Quit();
}
