/*
** circular_buffer2.c for circular_buffer in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun  3 11:54:36 2016 Erwan Dupard
** Last update Sun Jun 26 01:11:40 2016 Erwan Dupard
*/

#include "circular_buffer.h"

static int				circular_write(unsigned int data_size,
						       t_circular_buffer *buffer,
						       char *data)
{
  unsigned int				remaining_data_size;

  remaining_data_size = data_size -
    (buffer->size - buffer->valid_data_end);
  if (buffer->valid_data_start < buffer->valid_data_end
      && remaining_data_size > buffer->valid_data_start)
    {
      printf("error: buffer overflow\n");
      return (-1);
    }
  strncpy(&buffer->memory[buffer->valid_data_end],
	  data,
	  buffer->size - buffer->valid_data_end);
  if (!((remaining_data_size + (buffer->size - buffer->valid_data_end)) > buffer->size))
    {
      strncpy(buffer->memory,
	      &(data[buffer->size - buffer->valid_data_end]),
	      remaining_data_size);
    }
  buffer->valid_data_end = remaining_data_size;
  return (0);
}

int					write_to_buffer(t_circular_buffer *buffer,
							char *data,
							unsigned int data_size)
{
  if (buffer->valid_data_end < buffer->valid_data_start
      && buffer->valid_data_end + data_size > buffer->valid_data_start)
    {
      printf("error: buffer overflow\n");
      return (-1);
    }
  else if (buffer->size - buffer->valid_data_end < data_size)
    {
      if (circular_write(data_size, buffer, data) == -1)
	return (-1);
    }
  else
    {
      strncpy(&(buffer->memory[buffer->valid_data_end]), data, data_size);
      buffer->valid_data_end += data_size;
    }
  return (0);
}

static char				*circular_read(char *data,
						       unsigned int *data_size,
						       t_circular_buffer *buffer)
{
  *data_size = buffer->size -
    buffer->valid_data_start + buffer->valid_data_end;
  if (!(data = malloc(*data_size + 1)))
    return (NULL);
  strncpy(data, &(buffer->memory[buffer->valid_data_start]),
	  buffer->size - buffer->valid_data_start);
  strncpy(&(data[buffer->size - buffer->valid_data_start]),
	  buffer->memory, buffer->valid_data_end);
  return (data);
}

char		*read_data_from_buffer(t_circular_buffer *buffer)
{
  char		*data;
  unsigned int	data_size;

  data = NULL;
  if (buffer->valid_data_end == buffer->valid_data_start)
    {
      data_size = 0;
      if (!(data = malloc(data_size + 1)))
	return (NULL);
    }
  else if (buffer->valid_data_end > buffer->valid_data_start)
    {
      data_size = buffer->valid_data_end - buffer->valid_data_start;
      if (!(data = malloc(data_size + 1)))
	return (NULL);
      strncpy(data, &(buffer->memory[buffer->valid_data_start]), data_size);
    }
  else
    {
      if ((data = circular_read(data, &data_size, buffer)) == NULL)
	return (NULL);
    }
  data[data_size] = 0;
  return (data);
}
