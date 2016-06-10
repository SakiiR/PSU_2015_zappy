/*
** xsocket.c for xsocket in /home/billot_t/TEK2/PSU_2015_myftp
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 10 14:10:35 2016 Thomas Billot
** Last update Fri Jun 10 12:13:54 2016 Thomas Billot
*/

#include "xfunc.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

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