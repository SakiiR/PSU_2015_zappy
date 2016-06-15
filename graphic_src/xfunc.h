/*
** xfunc.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 16:31:56 2016 Thomas Billot
** Last update Wed Jun 15 17:14:27 2016 Erwan Dupard
*/

#ifndef XFUNC_H_
# define XFUNC_H_

# define BUFF_SIZE (1024)
# define IS_NUMBER(c) ((c >= '0' && c <= '9'))

#include <sys/socket.h>

char		*get_next_line(const int fd);
char		**my_str_to_wordtab(const char *str, const char *forbidden);
void		free_word_tab(char **tab);
int		xconnect(int sockfd,
			 const struct sockaddr *adress,
			 socklen_t socklen);
int		xsocket(int domain, int type, int protocol);
int		xclose(int fd);

#endif /* !XFUNC_H_ */
