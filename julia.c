#include <stdio.h>

int	main(void)
{
	double Zr;
	double Zi;
	double Xc, Yc;
	double x, y;
	int	i;
	double Cr, Ci;

	Cr = 0;
	Ci = 0;
	y = -1;
	while (++y < 40)
	{
		Yc = -2 + (y / 10);
		x = -1;
		while (++x < 40)
		{
			Xc = 2 + (x / 10);
			Zr = Yc;
			Zi = Xc;
			i = -1;
			while (++i < 10 && (Zr * Zr) + (Zi * Zi) < 4)
			{
				double tmp = Zr;
				Zr = (Zr * Zr) - (Zi * Zi) + Cr;
				Zi = 2 * tmp * Zi + Ci;
			}
//			printf("Zr => %f\nZi => %f\n", Zr, Zi);
			if (i == 10)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return (0);
}
