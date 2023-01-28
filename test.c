#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	int color = 1;

	color = create_trgb(1 , 2 , 3, 4);
	printf("color => %d\n", color);
	return (0);
}
