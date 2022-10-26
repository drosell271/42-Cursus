#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main()
{
	int	fd;
	int counter;

	counter = 0;
	fd = open("test.txt", O_RDONLY);
	while (counter != 2)
	{
		printf("%s\n", get_next_line(fd));
		counter++;
	}
	close(fd);
	return (0);
}
