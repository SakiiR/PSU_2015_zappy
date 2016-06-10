/*
** fct_welcome.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 14:10:07 2016 Thomas Billot
** Last update Fri Jun 10 14:25:43 2016 Thomas Billot
*/

#include "graphical.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int		fct_welcome(t_option *options)
{
  if (write(options->sockfd, "GRAPHIC\n", strlen("GRAPHIC\n")) == -1)
    {
      fprintf(stderr, "Error in write(): %s\n", strerror(errno));
      return (-1);
    }
  return (0);
}
