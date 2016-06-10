/*
** network.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 11:07:28 2016 Thomas Billot
** Last update Fri Jun 10 14:11:40 2016 Thomas Billot
*/

#ifndef NETWORK_H_
# define NETWORK_H_

#define SOCKET_ERROR -1

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct in_addr IN_ADDR;
typedef struct protoent PROTOCOL;

int		setup_networking(int port);

#endif /* !NETWORK_H_ */
