#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <complex.h>


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_display_options(void)
{
	
}

int	main(void)
{
	void	*mlx;
	void	*win;
	double 	tmp;
	double  Xc;
	double 	Yc;
	int x, y;
	int	color = 0x0000FF00;
	// INIT A WINDOW
	mlx = mlx_init();
	// INIT A WINDOW
	win = mlx_new_window(mlx, 800, 800, "Oussama");

	x = -1;
	while (++x <= 1300)
	{
		int y = -1;
		while (++y <= 1300)
		{
			int	Zr = 0;
			int	Zi = 0;

			Xc = (x - 200) / 100;
			Yc = (y - 200) / 100;
			int	i = -1;
			while (++i < 300)
			{
				tmp = Zr;
				Zr = (Zr * Zr) - (Zi * Zi) + Xc;
				Zi = (2 * tmp * Zi) + Yc;
		//		printf("Zr => %d\n", Zr);
		//		printf("Zi => %d\n", Zi);
//				printf("|z| => %d\n", (Zr * Zr) + (Zi * Zi));
				if ((Zr * Zr) + (Zi * Zi) > 2)
					break;
			}
//			printf("i => %d\n", i);
			if (i == 300)
				mlx_pixel_put(mlx, win, x, y, create_trgb(0, 255, 0, 0));
			else 
				mlx_pixel_put(mlx, win, x, y, create_trgb(0, 255, 0, 255));
		//	Yc += 0.01;
		}
		//Xc += 0.01;
	}
	//	mlx_put_image_to_window(mlx, win, image, 100, 100);
	// TRIANGLE
	/*int	j = -1;
	while (++j <= 100)
	{
		int i = -1;
		while (++i <= 200)
			mlx_pixel_put(mlx, win, i, j, 0x0000FF00);
	}*/
	// CIRCLES
//	int	 i  = 0;
//	while (i <= 1000)
//	{
//		mlx_pixel_put(mlx, img, i, i * sin(i), 0x0000FF00);
//		i++;
//	}
//	i = -1;
//	while (++i <= 180)
//		mlx_pixel_put(mlx, img, i, sin(i) * 30, 0x0000FF00);
	mlx_loop(mlx);
}


// EACH POINT IS A COMPLEX NUMBER : I CHECK EVERY PIXEL USING Zn = Zn+1 ^ 2 + C : IF NOT DEVERGE UNDER ITERATION OF 0 THEN THIS POINT FROM MANDELBROT SET ?
// HOW CAN I GET THE INFORMATION OF EACH PIXEL
//  RADIUS : CHO3A3 OF MANDEL BROT SET IS < 2 : SO IF THE PIXEL IS NOT DEVERGE AND (LMANDAM DYALHA) NOT >= 2 THEN THIS POINT IS A MANDEL BROT SET
//
// FIRST C REPRESENT EACH POINT OF MY PIXEL GRADE => I HAVE TO CHECK EACH PIXEL AND SEE IF DEVERGE OR NOT DEVERGE => THIS PART DETERMINE IF I HAVE TO DRAW THIS POINT OR NOT
