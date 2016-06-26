/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Sun Jun 26 16:19:00 2016 Erwan Dupard
*/

#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graphical.h"
#include "xfunc.h"

bool			is_valid_ip(char *ip)
{
  t_sockaddr		sa;
  int			result;

  result = inet_pton(AF_INET, ip, &(sa.sin_addr));
  return (result != 0);
}

int			check_options(t_option *options, char **argv)
{
  int			i;

  i = 0;
  while (argv[++i])
    {
      if (strcmp(argv[i], "-h") == 0 && argv[i + 1])
	options->ip = argv[i + 1];
      if (strcmp(argv[i], "-p") == 0 && argv[i + 1])
	options->port = atoi(argv[i + 1]);
    }
  return (RETURN_SUCCESS);
}

int			main(int argc, char *argv[])
{
  t_option		options;
  t_server		server;
  t_render		render;

  if (argc != 5 || check_options(&options, argv) == RETURN_FAILURE)
    {
      fprintf(stderr, USAGE);
      return (RETURN_FAILURE);
    }
  if ((server.socket = setup_networking(&options)) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (initialize_buffer(&(server.buffer_in), 4096) == RETURN_FAILURE)
   return (RETURN_FAILURE);
  if (initialize_buffer(&(server.buffer_out), 4096) == RETURN_FAILURE)
   return (RETURN_FAILURE);
  sdl_init();
  sdl_create_win(&render);
  draw_backg(&render);
  if (launch_client(&server, &render) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
