/*
** SDL_ressources.h for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sat Jun 11 01:02:05 2016 Thomas Beaudet
** Last update Wed Jun 15 17:15:08 2016 Thomas Beaudet
*/

#ifndef _SDL_RESSOURCES_H_
# define _SDL_RESSOURCES_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct			s_sdl
{
  int				height;
  int				width;
  SDL_Surface			*screen;
  SDL_Event			event;
  int				action;
}				t_sdl;

int		set_vals(t_sdl *s);
void		init_sdl();
void		SDL_quit(t_sdl *s);
int		run(t_sdl *s);
void		event_sdl(t_sdl *s);

#endif /* !_SDL_RESSOURCES_H_ */
