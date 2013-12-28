
#ifndef		WOLF_H
# define	WOLF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "SDL.h"
# include "libft/libft.h"

int	getMap(char (*tab)[10][10]);
void	SDL_loop(SDL_Window *window);

#endif		/*!WOLH_H*/
