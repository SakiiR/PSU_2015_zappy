/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Tue Jun 14 14:58:33 2016 Thomas Billot
*/

#include "graphical.h"
#include "network.h"
#include "xfunc.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			is_number(char c)
{
  if (c <= '0' || c >= '9')
    return (RETURN_FAILURE);
  return (RETURN_SUCESS);
}

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

  if (strcmp(argv[1], "-h") || !(is_valid_ip(argv[2])))
    return (RETURN_FAILURE);
  i = -1;
  while (argv[4][++i] != '\0')
    {
      if (is_number(argv[4][i]))
	return (RETURN_FAILURE);
    }
  if (strcmp(argv[3], "-p"))
    return (RETURN_FAILURE);
  options->ip = argv[2];
  options->port = atoi(argv[4]);
  return (RETURN_SUCESS);
}

int			main(int argc, char *argv[])
{
  t_option		options;
  t_server		server;
  
  if (argc != 5 || check_options(&options, argv) == RETURN_FAILURE)
    {
      fprintf(stderr, "Usage: ./console -h [ipaddress] -p [port]\n");
      return (RETURN_FAILURE);
    }
  if ((server.socket = setup_networking(&options)) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (initialize_buffer(&(server.buffer_in), 4096) == RETURN_FAILURE)
   return (RETURN_FAILURE);
  if (initialize_buffer(&(server.buffer_out), 4096) == RETURN_FAILURE)
   return (RETURN_FAILURE);
  if (launch_client(&server) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (0);
}
