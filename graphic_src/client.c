/*
** g_client.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 14:56:18 2016 Thomas Billot
** Last update Thu Jun 16 13:32:55 2016 Thomas Billot
*/

#include <sys/select.h>
#include "graphical.h"
#include "xfunc.h"

static t_ptr	g_ftab[] =
  {
    {MSZ, NULL},
    {BCT, NULL},
    {TNA, NULL},
    {PNW, NULL},
    {PPO, NULL},
    {PLV, NULL},
    {PEX, NULL},
    {PBC, NULL},
    {PIC, NULL},
    {PIE, NULL},
    {PFK, NULL},
    {PDR, NULL},
    {PGT, NULL},
    {PDI, NULL},
    {ENW, NULL},
    {EHT, NULL},
    {EBO, NULL},
    {EBI, NULL},
    {SGT, NULL},
    {SEG, NULL},
    {SMG, NULL},
    {SUC, NULL},
    {SBP, NULL},
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
	  if (strcmp(cmd[0], g_ftab[i].id) == RETURN_SUCESS
	      && g_ftab[i].f != NULL)
	    {
	      printf("Command found: %s\n", g_ftab[i].id);
	      if (g_ftab[i].f(map, server, cmd) == RETURN_FAILURE)
		return (RETURN_FAILURE);
	    }
	}
      free_word_tab(cmd);
    }
  return (RETURN_SUCESS);
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
	  printf("message : [%s]\n", next_message);
	  if (handle_command(map, server, next_message) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	  free(next_message);
	}
      if (next_message)
	free(next_message);
    }
  return (RETURN_SUCESS);
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
  return (RETURN_SUCESS);
}

int			launch_client(t_server *server)
{
  t_map			map;
  struct timeval	tv;
  fd_set		si;
  fd_set		so;
  int			max_socket;

  tv.tv_usec = 50;
  tv.tv_sec = 0;
  max_socket = 0;
  while (1)
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
    }
  return (RETURN_SUCESS);
}
