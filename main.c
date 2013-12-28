#include <stdio.h>
#include "wolf.h"

int	getMap(char (*tab)[10][10])
{
	char		*line;
	int		fd;
	int		pos[2];
	char		*tok;

	pos[0] = 0;
	pos[1] = 0;
	fd = open("Map/map.txt", O_RDONLY);
	if (!fd)
		return (0);
	while (get_next_line(fd, &line))
	{
		tok = ft_strtok(line, ' ');
		while (tok)
		{
			(*tab)[pos[0]][pos[1]] = ft_atoi(tok);
			tok = ft_strtok(NULL, ' ');
			pos[1]++;
		}
		pos[0]++;
		free(line);
	}
	close(fd);
	return (1);
}

void	SDL_loop(SDL_Window *window)
{
	SDL_Event	event;
	int		work;

	work = 1;
	while (work)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				work = 0;
		}
	}
}

int	main(int argc, char* argv[])
{
	SDL_Window	*window;
	char		map[10][10];

	if (!getMap(&map))
	{
		printf("Can't open map's file\n");
		return (-1);
	}
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
			"Wolf3D - by Alexandre Brault",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_OPENGL
			);
	if (window == NULL)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		return (1);
	}
	SDL_loop(window);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
