#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int	fd = open("d.txt", O_RDWR | O_CREAT, 0777);
	printf("sonuc : %s",get_next_line(0));
	return (0);
}
