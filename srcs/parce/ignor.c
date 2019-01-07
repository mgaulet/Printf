#include "../../includes/ft_printf.h"

void	ft_ignor(t_param *param, int nb, int nb2)
{
	int x;
	int y;

	y = -1;
	x = 0;

	while(param->tab[x] != 0)
	{
		if (param->tab[x] == nb)
		{
			while (param->tab[++y] != 0)
				if (param->tab[y] == nb2)
					param->tab[y] = 9;
			y = -1;
		}
		x++;
	}
}

void	ft_ignor2(t_param *param, char c, int flags)
{
	int x;

	x = 0;
	while(param->tab[x] != 0)
	{
		if (c == 'u' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		{
			if (param->tab[x] == flags)
				param->tab[x] = 9;
			break;
		}
		x++;
	}
}

void	ft_ignor3(t_param *param)
{
	int x;

	x = 0;
	while(param->tab[x] != 0)
	{
		if (param->tab[x] != 1 && param->tab[x] != 8 && param->tab[x] != 4)
			param->tab[x] = 9;
		x++;
	}

}
