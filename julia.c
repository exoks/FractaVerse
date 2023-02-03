#include <stdio.h>
#include <mlx.h>

int	main(void)
{
	double Zr;
	double Zi;
	double Xc, Yc;
	double x, y;
	int	i;
	double Cr, Ci;
	double tmp;

	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 800, "oussama");
	Cr = 0.3;
	Ci = 0.5;
	x = -1;
	while (++x < 800)
	{
		Xc = -2 + (x / 200);
		y = -1;
		while (++y < 800)
		{
			Yc = 2 - (y / 200);
			Zr = Xc;
			Zi = Yc;
			i = -1;
			printf("x => %.1f\ny => %.1f\n", Xc, Yc);
			while (++i < 100 && (Zr * Zr) + (Zi * Zi) < 4)
			{
				tmp = Zr;
				Zr = (Zr * Zr) - (Zi * Zi) + Cr;
				Zi = 2 * tmp * Zi + Ci;
			}
			//printf("Zr => %f\nZi => %f\n", Zr, Zi);
			if (i == 100)
				mlx_pixel_put(mlx, win, x, y, 0x00FF0000);		
		}
	}
	mlx_loop(mlx);
	return (0);
}
