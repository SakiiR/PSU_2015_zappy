/*
** network.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 16:59:16 2016 Thomas Billot
** Last update Sun Jun 26 16:36:54 2016 Erwan Dupard
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "graphical.h"
#include "xfunc.h"

int			setup_networking(t_option *options)
{
  t_sockaddr		sin;
  t_socket		sock;
  t_protocol		*pe;
  struct hostent	*host;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      fprintf(stderr, "Error in getprotobyname(): %s\n", strerror(errno));
      return (SOCKET_ERROR);
    }
  if ((sock = xsocket(AF_INET, SOCK_STREAM, pe->p_proto)) == SOCKET_ERROR)
    return (SOCKET_ERROR);
  if ((host = gethostbyname(options->ip)) == NULL)
    return (SOCKET_ERROR);
  sin.sin_family = AF_INET;
  bcopy(host->h_addr_list[0], &(sin.sin_addr.s_addr), host->h_length);
  sin.sin_port = htons(options->port);
  if (xconnect(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    {
      if (xclose(sock) == -1)
	return (SOCKET_ERROR);
      return (SOCKET_ERROR);
    }
  return (sock);
}
