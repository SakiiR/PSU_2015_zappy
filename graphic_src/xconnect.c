/*
** xconnect.c for xfunc in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 12:03:28 2016 Thomas Billot
** Last update Fri Jun 10 12:06:23 2016 Thomas Billot
*/

#include "xfunc.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

int		xconnect(int sockfd, const struct sockaddr *adress, socklen_t socklen)
{
  if (connect(sockfd, adress, socklen) == -1)
    {
      fprintf(stderr, "Error in connect(): %s", strerror(errno));
      return (-1);
    }
  return (0);
}
