#include <stdio.h>

int	ft_swap(unsigned char a);
int	main(void)
{
	int	a = 15;
	int	tmp1, tmp2;
// the most important part over here is :
// a >> 4 it's a new value can be taken from another variable 
// && it doesn't effect a
	printf("a => %d\n", a);
	printf("rev a => %d\n", ft_swap(a));
	return (0);
}

int	ft_swap(unsigned char a)
{
	return (a >> 4 | a << 4);
}
