/*
** xsocket.c for xsocket in /home/billot_t/TEK2/PSU_2015_myftp
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 10 14:10:35 2016 Thomas Billot
** Last update Wed Jun 22 14:22:14 2016 Erwan Dupard
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
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
