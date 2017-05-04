#include "fdf.h"

void	pixel_to_img(t_img img_data, int x, int y, t_color color)
{
	int p;

	if (x < 0 || y < 0 || x >= img_data.width || y >= img_data.height)
		return ;
	p = (x * 4) + (y * img_data.size_line);
	img_data.data[p] = color.b;
	img_data.data[++p] = color.g;
	img_data.data[++p] = color.r;
}
