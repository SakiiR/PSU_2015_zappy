/*
** xfunc.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Wed Jun 22 14:29:48 2016 Thomas Billot
** Last update Sun Jun 26 19:00:37 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
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

int		random_number(int min, int max)
{
  int		result;
  int		max_gen;
  int		min_gen;

  result = 0;
  max_gen = 0;
  min_gen = 0;
  if (min < max)
    {
      min_gen = min;
      max_gen = max + 1;
    }
  else
    {
      min_gen = max;
      max_gen = min + 1;
    }
  srand(time(NULL));
  result = (rand() % (max_gen - min_gen - min_gen)) + min_gen;
  return (result);
}
