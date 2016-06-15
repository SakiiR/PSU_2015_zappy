/*
** fct_welcome.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 14:10:07 2016 Thomas Billot
** Last update Wed Jun 15 15:24:19 2016 Thomas Billot
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "graphical.h"

int		fct_welcome(t_map *map,
			    t_server *server,
			    char **cmd)
{
  (void)map;
  (void)cmd;
  if (write_to_buffer(&(server->buffer_out),
		      "GRAPHIC\n",
		      strlen("GRAPHIC\n")) == -1)
    return (-1);
  return (0);
}
