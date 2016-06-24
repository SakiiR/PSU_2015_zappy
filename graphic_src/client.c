/*
** g_client.c for PSU_2015_zappy in /home/mikaz3
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Fri Jun 10 14:56:18 2016 Thomas Billot
** Last update Fri Jun 24 14:00:11 2016 Thomas Beaudet
*/

#include <sys/select.h>
#include "graphical.h"
#include "xfunc.h"

/* DEBUGGING */
void		aff_map_info(t_map *map);
/**/

static t_ptr	g_ftab[] =
  {
    {MSZ, fct_msz},
    {BCT, fct_bct},
    {TNA, fct_tna},
    {PNW, fct_pnw},
    {PPO, fct_ppo},
    {PLV, fct_plv},
    {PEX, fct_pex},
    {PBC, fct_pbc},
    {PIC, fct_pic},
    {PIE, fct_pie},
    {PFK, fct_pfk},
    {PDR, fct_pdr},
    {PGT, fct_pgt},
    {PDI, fct_pdi},
    {ENW, fct_enw},
    {EHT, fct_eht},
    {EBO, fct_ebo},
    {EBI, fct_ebi},
    {SGT, fct_sgt},
    {SEG, fct_seg},
    {SMG, fct_smg},
    {SUC, fct_suc},
    {SBP, fct_sbp},
    {BIENVENUE, fct_welcome},
    {NULL, NULL}
  };

int			handle_command(t_map *map,
				       t_server *server,
				       char *message)
{
  char			**cmd;
  int			i;

  if ((cmd = my_str_to_wordtab(message, " \n")) != NULL && cmd[0] != NULL)
    {
      i = -1;
      while (g_ftab[++i].id != NULL)
	{
	  if (strcmp(cmd[0], g_ftab[i].id) == RETURN_SUCCESS
	      && g_ftab[i].f != NULL)
	    {
	      if (g_ftab[i].f(map, server, cmd) == RETURN_FAILURE)
		return (RETURN_FAILURE);
	    }
	}
      free_word_tab(cmd);
    }
  return (RETURN_SUCCESS);
}

int		        handle_server_input(t_map *map,
					    t_server *server,
					    fd_set *si)
{
  char			buffer[BUFF_SIZE];
  int			size_read;
  char			*next_message;

  if (FD_ISSET(server->socket, si))
    {
      size_read = read(server->socket, buffer, BUFF_SIZE);
      buffer[size_read] = 0;
      write_to_buffer(&(server->buffer_in), buffer, size_read);
      while ((next_message = get_next_message(&(server->buffer_in)))
	     && strlen(next_message) > 0)
	{
	  if (handle_command(map, server, next_message) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	  free(next_message);
	}
      if (next_message)
	free(next_message);
    }
  return (RETURN_SUCCESS);
}

int			handle_server_output(t_map *map,
					     t_server *server,
					     fd_set *so)
{
  char			*next_message;
  char			*data;

  (void)map;
  if (FD_ISSET(server->socket, so))
    {
      data = read_data_from_buffer(&(server->buffer_out));
      free(data);
      next_message = get_next_message(&(server->buffer_out));
      if (next_message && next_message[0])
	write(server->socket, next_message, strlen(next_message));
      free(next_message);
    }
  return (RETURN_SUCCESS);
}

void			init_struct(t_map *map, struct timeval *tv)
{
  map->x = 0;
  map->y = 0;
  map->tiles = NULL;
  tv->tv_sec = 0;
  tv->tv_usec = 50;
}

int			launch_client(t_server *server, t_render *render)
{
  t_map			map;
  struct timeval	tv;
  fd_set		si;
  fd_set		so;
  int			max_socket;

  init_struct(&map, &tv);
  preload_textures(render);
  while (SDL_PollEvent(&render->event) || 1)
    {
      FD_ZERO(&si);
      FD_ZERO(&so);
      FD_SET(server->socket, &si);
      FD_SET(server->socket, &so);
      max_socket = server->socket;
      if (select(max_socket + 1, &si, &so, NULL, &tv) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      if (handle_server_input(&map, server, &si) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      if (handle_server_output(&map, server, &so) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      map_rendering(render, &map);
      SDL_RenderPresent(render->rend);
      clear_surface(render);
      if (sdl_event(render) == RETURN_FAILURE)
	return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
