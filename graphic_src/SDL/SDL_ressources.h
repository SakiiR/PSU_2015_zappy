/*
** SDL_ressources.h for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sat Jun 11 01:02:05 2016 Thomas Beaudet
** Last update Tue Jun 14 12:43:29 2016 Thomas Beaudet
*/

#ifndef _SDL_RESSOURCES_H_
# define _SDL_RESSOURCES_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define NB_BLOC_WIDTH 10
#define NB_BLOC_HEIGHT 10
#define BLOC_SIZE 40
#define S_WIDTH BLOC_SIZE * NB_BLOC_WIDTH
#define S_HEIGHT BLOC_SIZE * NB_BLOC_HEIGHT

typedef struct			s_sdl
{
  int				height;
  int				width;
  SDL_Rect			pos;
  SDL_Rect			posPlayer;
  SDL_Surface			*win;
  SDL_Surface			*lines[8];
  SDL_Surface			*player[4];
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

#endif /* !_SDL_RESSOURCES_H_ */
