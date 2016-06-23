/*
** broadcast.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jun 22 15:52:03 2016 Barthelemy Gouby
** Last update Thu Jun 23 17:02:20 2016 Barthelemy Gouby
*/

#include "server.h"

void		get_starting_coordinates(t_character *character,
					 int *x,
					 int *y)
{
  *x = (int) character->current_case->x;
  *y = (int) character->current_case->y;
  if (character->orientation == NORTH)
    (*y)--;
  else if (character->orientation == SOUTH)
    (*y)++;
  if (character->orientation == WEST)
    (*x)--;
  else if (character->orientation == EAST)
    (*x)++;
}



t_case		**get_surrounding_cases(t_map *map, t_character *character)
{
  t_case	**cases;
  int		i;
  int		x;
  int		y;

  if (!(cases = malloc(8 * sizeof(*cases))))
    return (NULL);
  i = 0;
  get_starting_coordinates(character, &x, &y);
  printf("character case x: %i y: %i\n",
	 character->current_case->x,
	 character->current_case->y);
  printf("starting case coordinates: x: %i y: %i\n", x, y);
  while (i < 8)
    {
      printf(" x: %i    y: %i\n", x, y);
      cases[i++] = map_get_case_circular(x, y, map);
      if (y < (int) character->current_case->y && 
	  x <= (int) character->current_case->x)
	x++;
      else if (x > (int) character->current_case->x && 
	       y <= (int) character->current_case->y)
	y++;
      else if (y > (int) character->current_case->y && 
	       x >= (int) character->current_case->x)
	x--;
      else if (x < (int) character->current_case->x && 
	       y >= (int) character->current_case->y)
	y--;
    }
  i = 0;
  printf("surrouding cases:\n");
  while (i < 8)
    {
      printf("--- case %i --- x: %i y: %i\n", i, cases[i]->x, cases[i]->y);
      i++;
    }
  return (cases);
}

double		calculate_spheric_distance(t_case *case_1, t_case *case_2, t_map *map)
{
  double	distance;
  double	spheric_right_distance;
  double	spheric_left_distance;
  double	spheric_down_distance;
  double	spheric_up_distance;

  distance = hypot((int) case_1->x - (int) case_2->x, (int) case_1->y - (int) case_2->y);
  printf("basic distance: %f ", distance);
  spheric_right_distance = hypot(((int) case_1->x + (int) map->width) - (int) case_2->x,
				 (int) case_1->y - (int) case_2->y);
  if (spheric_right_distance < distance)
    distance = spheric_right_distance;
  spheric_left_distance = hypot(((int) case_1->x - (int) map->width) - (int) case_2->x,
				(int) case_1->y - (int) case_2->y);
  if (spheric_left_distance < distance)
    distance = spheric_left_distance;
  spheric_down_distance = hypot((int) case_1->x - (int) case_2->x,
				((int) case_1->y + (int) map->width) - (int) case_2->y);
  if (spheric_down_distance < distance)
    distance = spheric_down_distance;
  spheric_up_distance = hypot((int) case_1->x - (int) case_2->x,
			      ((int) case_1->y - (int) map->width) - (int) case_2->y);
  if (spheric_up_distance < distance)
    distance = spheric_up_distance;
  printf("left %f right %f down %f up %f\n",
	 spheric_left_distance,
	 spheric_right_distance,
	 spheric_down_distance,
	 spheric_up_distance);
  return (distance);
}

int		get_closest_case(t_map *map, t_character *sender, t_character *receiver)
{
  t_case	**surrouding_cases;
  int		closest_case;
  int		i;
  double	distance;
  double	shortest_distance;

  if (!(surrouding_cases = get_surrounding_cases(map, receiver)))
    return (RETURN_FAILURE);
  i = -1;
  shortest_distance = -1;
  while (++i < 8)
    {
      distance = calculate_spheric_distance(surrouding_cases[i],
					    sender->current_case,
					    map);
      printf("distance from case %i: %f\n", i + 1, distance);
      if (distance < shortest_distance || shortest_distance < 0)
	{
	  shortest_distance = distance;
	  closest_case = i + 1;
	}
    }
  printf("shortest_distance: %f --- closest_case: %i\n",
	 shortest_distance,
	 closest_case);
  return (closest_case);
}

int		send_broadcast_to_drone(t_server *server,
					t_client *sender,
					t_client *receiver,
					char *message)
{
  int		closest_case;

  (void) message;
  if (sender->character->current_case == receiver->character->current_case)
    closest_case = 0;
  else if ((closest_case = get_closest_case(&server->game_data.map,
					    sender->character,
					    receiver->character))
	   == RETURN_FAILURE)
    return (RETURN_FAILURE);
  sprintf(server->buffer, "message %i\n", closest_case);
  write_to_buffer(&receiver->buffer_out, server->buffer, strlen(server->buffer));
  return (RETURN_SUCCESS);
}
