/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Fri Jun 10 15:07:44 2016 Thomas Billot
*/

#include "graphical.h"
#include "network.h"
#include "xfunc.h"
#include "circular_buffer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			main(int argc, char *argv[])
{
  t_option		options;
  t_circular_buffer	*circular_buffer;
  
  if (argc != 2)
    {
      fprintf(stderr, "Usage: ./bin/console [port]\n");
      return (-1);
    }
  if ((options.sockfd = setup_networking(atoi(argv[1]))) == -1)
    return (-1);
  if ((circular_buffer = malloc(sizeof(*circular_buffer))) == NULL)
    return (-1);
  options.circular_buffer = circular_buffer;
  if (initialize_buffer(options.circular_buffer, 4096) == -1)
    return (-1);
  if (launch_client(&options) == -1)
    return (-1);
  return (0);
}
