/*
** g_client.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 14:56:18 2016 Thomas Billot
** Last update Mon Jun 13 15:46:19 2016 Thomas Billot
*/

#include "graphical.h"
#include "network.h"
#include "xfunc.h"

static t_ptr	ftab[] =
  {
    {MSZ, NULL},
    {BCT, NULL},
    {TNA, NULL},
    {PNW, NULL},
    {PPO, NULL},
    {PLV, NULL},
    {PEX, NULL},
    {PBC, NULL},
    {PIC, NULL},
    {PIE, NULL},
    {PFK, NULL},
    {PDR, NULL},
    {PGT, NULL},
    {PDI, NULL},
    {ENW, NULL},
    {EHT, NULL},
    {EBO, NULL},
    {EBI, NULL},
    {SGT, NULL},
    {SEG, NULL},
    {SMG, NULL},
    {SUC, NULL},
    {SBP, NULL},
    {BIENVENUE, fct_welcome},
    {NULL, NULL}
  };

int			handle_command(char *message, t_option *options)
{
  char			**cmd;
  int			i;
  
  if ((cmd = my_str_to_wordtab(message, " \n")) != NULL && cmd[0] != NULL) 
    {
      i = -1;
      while (ftab[++i].id != NULL)
	{
	  if (strcmp(cmd[0], ftab[i].id) == 0 && ftab[i].f != NULL)
	    {
	      printf("Command found: %s\n", ftab[i].id);
	      if (ftab[i].f(options) == -1)
		return (-1);
	    }
	}
      free_word_tab(cmd);
    }
  return (0);
}

int		        handle_server_cmd(t_option *options)
{
  char			buffer[BUFF_SIZE];
  int			size_read;
  char			*next_message;

  size_read = read(options->sockfd, buffer, BUFF_SIZE);
  buffer[size_read] = 0;
  /*  if (size_read > 0)
      printf("buffer : %s\n", buffer); */
  write_to_buffer(options->circular_buffer, buffer, size_read);
  if ((next_message = get_next_message(options->circular_buffer)))
    {
      if (strlen(next_message) > 0)
	{
	  printf("message : [%s]\n", next_message);
	  if (handle_command(next_message, options) == -1)
	    return (0);
	}
      free(next_message);
    }
  return (0);
}

int			launch_client(t_option *options)
{  
  while (1)
    {
      if (handle_server_cmd(options) == -1)
	return (-1);
    }
  return (0);
}
