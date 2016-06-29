/*
** circular_buffer.h for myirc in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_myirc/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon May 30 18:55:33 2016 Barthelemy Gouby
** Last update Wed Jun 29 15:01:37 2016 Barthelemy Gouby
*/

#ifndef _CIRCULAR_BUFFER_H_
# define _CIRCULAR_BUFFER_H_

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_circular_buffer
{
  char		*memory;
  unsigned int	valid_data_start;
  unsigned int	valid_data_end;
  unsigned int	size;
}		t_circular_buffer;

int		initialize_buffer(t_circular_buffer *buffer, int size);
int		write_to_buffer(t_circular_buffer *buffer,
				char *to_write,
				unsigned int size_to_write);
char		*read_data_from_buffer(t_circular_buffer *buffer);
char		*get_next_message(t_circular_buffer *buffer);
int		get_if_message(t_circular_buffer *buffer);

#endif /* !_CIRCULAR_BUFFER_H_ */
