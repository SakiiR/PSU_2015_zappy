/*
** xaccept.c for xaccept in /home/billot_t/TEK2/PSU_2015_myftp
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 10 14:10:13 2016 Thomas Billot
** Last update Wed Jun 15 17:12:25 2016 Erwan Dupard
*/

#include "xfunc.h"

int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int		fd;

  if ((fd = accept(sockfd, addr, addrlen)) == -1)
    {
      fprintf(stderr, "Error in xaccept(): %s\n", strerror(errno));
      return  (-1);
    }
  return (fd);
}
