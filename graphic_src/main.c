/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Mon Jun 13 18:53:05 2016 Thomas Billot
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

int			check_options(t_option *options, char *ip, char *port)
{
  int			i;

  if (!(ip || port))
    return (RETURN_FAILURE);
  i = 0;
  while (port[++i] != '\0')
    {
      if (is_number(port[i]))
	return (RETURN_FAILURE);
    }
  if (!(is_valid_ip(ip)))
    return (RETURN_FAILURE);
  options->ip = ip;
  options->port = atoi(port);
  return (RETURN_SUCESS);
}

int			main(int argc, char *argv[])
{
  t_option		options;
  t_info		infos;
  t_circular_buffer	*circular_buffer;
  
  if (argc != 3)
    {
      fprintf(stderr, "Usage: ./console -h [ipaddress] -p [port]\n");
      return (RETURN_FAILURE);
    }
  if (check_options(&options, argv[1], argv[2]) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if ((infos.sockfd = setup_networking(&options)) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if ((circular_buffer = malloc(sizeof(*circular_buffer))) == NULL)
    return (RETURN_FAILURE);
  infos.circular_buffer = circular_buffer;
  if (initialize_buffer(infos.circular_buffer, 4096) == RETURN_FAILURE)
   return (RETURN_FAILURE);
  if (launch_client(&infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (0);
}
