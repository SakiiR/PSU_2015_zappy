/*
** animation.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 23 15:25:48 2016 Thomas Beaudet
** Last update Sat Jun 25 15:23:37 2016 Thomas Beaudet
*/

#include "graphical.h"

int			Charge_data(t_charset *charset,
				    const char *file, int nb_x,
				    int nb_y, Uint8 R,
				    Uint8 G, Uint8 B)
{
  SDL_Surface		*tmp;

  if ((tmp = SDL_LoadBMP(file)) == NULL)
    {
      fprintf(stderr,
              "Problem encountered while loading bmp file -> SDL Error : %s\n",
              SDL_GetError());
      SDL_Quit();
      return (RETURN_FAILURE);
    }
  charset->charset_ = SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);
  SDL_SetColorKey(charset->charset_,
		  SDL_SRCCOLORKEY,
		  SDLMapRGB(charset->charset_->format, R, G, B));
  charset->nbX = nb_x;
  charset->nbY = nb_y;
  charset->w = charset->charset_->w / nb_x;
  charset->h = charset->charset_->h / nb_y;
  return (0);
}

void			free_charset(t_charset *charset)
{
  SDL_FreeSurface(charset->charset_);
}

void			get_src_charset(t_charset *charset,
					SDL_Rect *src, int frame)
{
  src->w = (Uint16)charset->w;
  src->h = (Uint16)charset->h;
  src->x = (Sint16)((frame % charset->nbX) * charset->w);
  src->y = (Sint16)((frame / charset->nbY) * charset->h);
}

void			set_anim(t_anim *anim, int beg_frame,
				 int frames_nb, int delay)
{
  anim->begin_frame = beg_frame;
  anim->nb_frames = frames_nb;
  anim->delay = delay;
}
