/*
** test.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 10:42:41 2016 Thomas Beaudet
** Last update Wed Jun 15 11:58:08 2016 Thomas Beaudet
*/

SDL_Surface		*Load_image(const char *file_img)
{
  SDL_Surface		*final_img;
  SDL_Surface		*img_ram;

  if ((img_ram = SDL_LoadIMG(file_img)) == NULL)
    {
      fprintf(stderr, "Problem ecountered while setting video mode : %s\n",
	      SDL_GetError());
      exit (EXIT_FAILURE);
    }
  file_img = SDL_DisplayFormat(img_ram);
  SDL_FreeSurface(img_ram);
  return (img_ram);
}

void			ChargerMap_tileset(FILE* file,t_mapping *m)
{
  int			tile_num;
  int			i;
  int			j;
  char			buf[CASH_SIZE];
  char			buf2[CASH_SIZE];

  fscanf(file,"%s",buf);
  m->tileset = Load_image(buf);
  fscanf(F,"%d %d",&m->nbtilesX,&m->nbtilesY);
  m->tile_w = m->tileset->w / m->nb_tileX;
  m->tile_h = m->tileset->h / m->nb_tileY;
  m->props = malloc(m->nb_tileX * m->nb_tileY * sizeof(t_proper));
  for(j = 0,tile_num = 0; j < m->nb_tileY; j++)
    {
      for(i = 0; i < m->nb_tileX; i++, numtile++)
	{
	  m->props[tile_num].rect.w = m->tile_w;
	  m->props[tile_num].rect.h = m->tile_h;
	  m->props[tile_num].rect.x = i * m->tile_w;
	  m->props[tile_num].rect.y = j * m->tile_h;
	  fscanf(file,"%s %s", buf, buf2);
	}
    }
}

t_mapping		*Charge_Map(const char* level)
{
  FILE* F;
  Map* m;
  char buf[CACHE_SIZE];

  if ((m = malloc(sizeof(t_mapping))) == NULL)
    {
      printf("Malloc of 'm' failed\n");
      return (NULL);
    }
  do
    {
      fgets(buf,CACHE_SIZE,F);
      if (strstr(buf,"#tileset"))
	ChargerMap_tileset(F,m);
      if (strstr(buf,"#level"))
	ChargerMap_level(F,m);
    } while (strstr(buf,"#fin")==NULL);
  fclose(F);
  return m;
}

int			AfficherMap(t_mapping *m,SDL_Surface* screen)
{
  int			i;
  int			j;
  SDL_Rect		dest_rect;
  int			tile_num;

  for(i = 0; i < m->nb_tiles_world_w; i++)
    {
      for(j = 0; j < m->nb_tiles_world_h; j++)
	{
	  dest_rect.x = i * m->tile_w;
	  dest_rect.y = j * m->tile_h;
	  tile_num = m->schema[i][j];
	  SDL_BlitSurface(m->tileset, &(m->props[tile_num].rect), screen, &dest_rect);
	}
    }
  return 0;
}

int			Free_Map(t_mapping *m)
{
  int			i;

  i = 0;
  SDL_FreeSurface(m->tileset);
  for(i = 0; i < m->nb_tiles_world_h; i++)
    free(m->schema[i]);
  free(m->schema);
  free(m->props);
  free(m);
  return 0;
}
