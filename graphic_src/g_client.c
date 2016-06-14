/*
** g_client.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 14:56:18 2016 Thomas Billot
** Last update Tue Jun 14 13:01:30 2016 Thomas Billot
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

int			handle_command(char *message, t_info *infos)
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
	      if (ftab[i].f(infos) == -1)
		return (-1);
	    }
	}
      free_word_tab(cmd);
    }
  return (0);
}

int		        handle_server_cmd(t_info *infos)
{
  char			buffer[BUFF_SIZE];
  int			size_read;
  char			*next_message;

  size_read = read(infos->sockfd, buffer, BUFF_SIZE);
  buffer[size_read] = 0;
  if (size_read > 0)
    printf("buffer : [%s]\n", buffer);
  write_to_buffer(infos->circular_buffer, buffer, size_read);
  if ((next_message = get_next_message(infos->circular_buffer)))
    {
      if (next_message && next_message[0])
	{
	  printf("message : [%s]\n", next_message);
	  if (handle_command(next_message, infos) == -1)
	    return (-1);
	}
      free(next_message);
    }
  return (0);
}

int			launch_client(t_info *infos)
{  
  while (1)
    {
      if (handle_server_cmd(infos) == -1)
	return (-1);
    }
  return (0);
}
