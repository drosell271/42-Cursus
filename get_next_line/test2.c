#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main()
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
