/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Mon Jun 13 18:07:28 2016 Thomas Billot
*/

#include "graphical.h"
#include "network.h"
#include "xfunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			main(int argc, char *argv[])
{
  t_info		infos;
  t_circular_buffer	*circular_buffer;
  
  if (argc != 2)
    {
      fprintf(stderr, "Usage: ./bin/console [port]\n");
      return (-1);
    }
  if ((infos.sockfd = setup_networking(atoi(argv[1]))) == -1)
    return (-1);
  if ((circular_buffer = malloc(sizeof(*circular_buffer))) == NULL)
    return (-1);
  infos.circular_buffer = circular_buffer;
  if (initialize_buffer(infos.circular_buffer, 4096) == -1)
    return (-1);
  if (launch_client(&infos) == -1)
    return (-1);
  return (0);
}
