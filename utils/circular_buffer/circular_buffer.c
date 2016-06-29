/*
** circular_buffer.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon May 30 14:55:52 2016 Barthelemy Gouby
** Last update Wed Jun 29 15:38:22 2016 Barthelemy Gouby
*/

#include "circular_buffer.h"

int		initialize_buffer(t_circular_buffer *buffer, int size)
{
  if (!(buffer->memory = malloc(sizeof(*buffer->memory) * (size + 1))))
    return (-1);
  buffer->memory = memset(buffer->memory, 0, size);
  buffer->valid_data_start = 0;
  buffer->valid_data_end = 0;
  buffer->size = size;
  return (0);
}

char		*get_next_message(t_circular_buffer *buffer)
{
  char		*data;
  char		*end_of_line;
  int		message_size;

  if (!(data = read_data_from_buffer(buffer)))
    return (NULL);
  if (!(end_of_line = strstr(data, "\n")))
    data[0] = 0;
  else
    {
      message_size = end_of_line - data + 1;
      data[message_size] = 0;
      if (buffer->valid_data_start + message_size > buffer->size)
	buffer->valid_data_start = message_size -
	  (buffer->size - buffer->valid_data_start);
      else
	buffer->valid_data_start += message_size;
    }
  return (data);
}

int		get_if_message(t_circular_buffer *buffer)
{
  if (buffer->valid_data_start != buffer->valid_data_end)
    {
      printf("message to write\n");
      return (1);
    }
  return (0);
}
