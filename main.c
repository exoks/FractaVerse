#include <mlx.h>
#include <stdio.h>
typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}t_image;

void	put(t_image img, int x, int y, int color)
{
	int *pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*pixel = color;
}
int	main(void)
{
	void	*mlx;
	t_image	img;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "Oussama");
	img.img = mlx_new_image(mlx, 400, 400);

	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	int	xm, ym;
	int	x = -1;
	while (++x < 400)
	{
		int	y = -1;
		while (++y < 400)
			put(img, x, y, 0x00FF0000);
	}
	printf("ex : 32\nbits_per_pixel => %d\n", img.bpp);
	printf("ex : 400\nline len => %d\n", img.line_len);
	printf("ex :False\nendian => %d\n", img.endian);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
