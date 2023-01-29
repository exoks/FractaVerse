#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <complex.h>
#include <curses.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	double 	tmp;
	double  Xc;
	double 	Yc;
	double x, y;
	int	color = 0x0000FF00;
	// INIT A WINDOW
	 mlx = mlx_init();
	// INIT A WINDOW
	win = mlx_new_window(mlx, 400, 400, "Oussama");

	y = 0;
	while (y <= 400)
	{
		Yc = 2 - (y / 100);
		x = 0;
		while (x <= 400)
		{
			Xc = -2 + (x / 100);
			//printf(">>>>>>>>>>>> (%f, %f)\n", Xc, Yc);
			double	Zr = 0;
			double	Zi = 0;

			int	i = -1;
			while (++i < 1000)
			{
				tmp = Zr;
				Zr = (Zr * Zr) - (Zi * Zi) + Xc;
				Zi = (2 * tmp * Zi) + Yc;
				if ((Zr * Zr) + (Zi * Zi) > 4)
					break;
			}
	//		printf("i => %d\n", i);
			if (i == 1000)
				mlx_pixel_put(mlx, win, x, y, color);
			x += 1;
		}
		printf("\n");
		y += 1;
	}
	mlx_loop(mlx);
	//	mlx_put_image_to_window(mlx, win, image, 100, 100);
}


// EACH POINT IS A COMPLEX NUMBER : I CHECK EVERY PIXEL USING Zn = Zn+1 ^ 2 + C : IF NOT DEVERGE UNDER ITERATION OF 0 THEN THIS POINT FROM MANDELBROT SET ?
// HOW CAN I GET THE INFORMATION OF EACH PIXEL
//  RADIUS : CHO3A3 OF MANDEL BROT SET IS < 2 : SO IF THE PIXEL IS NOT DEVERGE AND (LMANDAM DYALHA) NOT >= 2 THEN THIS POINT IS A MANDEL BROT SET
//
// FIRST C REPRESENT EACH POINT OF MY PIXEL GRADE => I HAVE TO CHECK EACH PIXEL AND SEE IF DEVERGE OR NOT DEVERGE => THIS PART DETERMINE IF I HAVE TO DRAW THIS POINT OR NOT
