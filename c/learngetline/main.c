#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	unsigned int	i;
	char			*s;	
	int				pos;
	char			*part;
	char			*multilines;

	s = strdup("* module rest");
	strncpy(part, s + 2, 6);
	printf("s:%s\npart:%s\n", s, part);
	free(s);
	multilines = strdup("* t\n* g");
	printf("multilines:\n%s\n", multilines);
	pos = strchr(multilines, '*') - multilines;
	printf("pos:%d\n", pos);
	free(multilines);
	return (0);
}
