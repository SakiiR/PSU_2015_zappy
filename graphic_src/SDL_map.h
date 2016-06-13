/*
** SDL_map.h for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sat Jun 11 01:02:05 2016 Thomas Beaudet
** Last update Mon Jun 13 18:43:04 2016 Thomas Beaudet
*/

#ifndef _SDL_MAP_H_
# define _SDL_MAP_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define WIDTH 1920
#define HEIGHT 1010
#define LINEMATE 1
#define DERAUMERE 2
#define PHIRAS 3
#define MENDIANE 4
#define FOOD 5
#define EGG 6
#define SIBUR 7
#define THYSTAME 8

typedef struct			s_sdl
{
  int				height;
  int				width;
  SDL_Rect			pos;
  SDL_Surface			*win;
  SDL_Event			event;
  TTF_Font			*font;
  int				action;
  SDL_Color			color;
  int				bpp;
  Uint32			pix;
  Uint8				*p;
}				t_sdl;

typedef struct	s_container
{
  int		height;
  int		weight;
  int		linemate;
  int		deraumere;
  int		phiras;
  int		mendiane;
  int		food;
  int		egg;
  int		sibur;
  int		thystame;
}		t_contain;

int		set_vals(t_sdl *s);
void		init_sdl();
void		init_ttf();
void		putpixel(SDL_Surface *screen, int x, int y, Uint32 pixel);
void		drawLine(SDL_Surface *screen, int x0, int y0, int x1,
			 int y1, Uint32 pixel);
void		SDL_quit(t_sdl *s);
int		run(t_sdl *s);

#endif /* !_SDL_MAP_H_ */
