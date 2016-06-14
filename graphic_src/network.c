/*
** network.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 16:59:16 2016 Thomas Billot
** Last update Mon Jun 13 18:52:15 2016 Thomas Billot
*/

#include "network.h"
#include "xfunc.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int			setup_networking(t_option *options)
{
  t_sockaddr		sin;
  t_socket		sock;
  t_protocol		*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      fprintf(stderr, "Error in getprotobyname(): %s\n", strerror(errno));
      return (SOCKET_ERROR);
    }
  if ((sock = xsocket(AF_INET, SOCK_STREAM, pe->p_proto)) == SOCKET_ERROR)
    return (SOCKET_ERROR);
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(options->ip);
  sin.sin_port = htons(options->port);
  if (xconnect(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    {
      if (xclose(sock) == -1)
	return (SOCKET_ERROR);
      return (SOCKET_ERROR);
    }    
  return (sock);
}
