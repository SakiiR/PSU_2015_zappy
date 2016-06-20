/*
** xconnect.c for xfunc in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 12:03:28 2016 Thomas Billot
** Last update Mon Jun 20 13:59:11 2016 Thomas Billot
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "xfunc.h"

int		xconnect(int sockfd,
			 const struct sockaddr *adress,
			 socklen_t socklen)
{
  if (connect(sockfd, adress, socklen) == -1)
    {
      fprintf(stderr, "Error in connect(): %s\n", strerror(errno));
      return (-1);
    }
  return (0);
}
