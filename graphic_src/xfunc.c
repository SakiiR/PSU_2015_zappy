/*
** xfunc.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Wed Jun 22 14:29:48 2016 Thomas Billot
** Last update Wed Jun 22 14:32:14 2016 Thomas Billot
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "xfunc.h"

int		xsocket(int domain, int type, int protocol)
{
  int		sockfd;

  if ((sockfd = socket(domain, type, protocol)) == -1)
    {
      fprintf(stderr, "Error in xsocket(): %s\n", strerror(errno));
      return (-1);
    }
  return (sockfd);
}

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

int		xclose(int fd)
{
  if (close(fd) == -1)
    {
      perror("close");
      return (-1);
    }
  return (0);
}
