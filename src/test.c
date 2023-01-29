#include "mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "Hello world");
	
	int 	i= -1;
	while (++i <= 400)
		mlx_pixel_put(mlx, win, i, i, 0x0000FF00);
	mlx_loop(mlx);
	return (0);
}
