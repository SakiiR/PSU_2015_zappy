/*
** xbind.c for xbind in /home/billot_t/TEK2/PSU_2015_myftp
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 10 14:15:01 2016 Thomas Billot
** Last update Wed Jun 22 14:21:30 2016 Erwan Dupard
*/

#include "myftp.h"

int		xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    {
      fprintf(stderr, "Error in socket(): %s\n", strerror(errno));
      return (-1);
    }
  return (0);
}
