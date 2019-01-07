#include "../../includes/ft_printf.h"

uint8_t ft_ibase(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return 10;
	else if (c == 'o' || c == 'O')
		return 8;
	else if (c == 'x' || c == 'X')
		return 16;
	return 10;
}

char *ft_init_char(char c)
{
	if (c == 'X')
		return GRAND_X;
	else if (c == 'x')
		return PETIT_X;
	return GRAND_X;
}

void ft_all_bases(t_param *param)
{
	uint64_t tab[2];

	tab[0] = param->data;
	tab[1] = 0;
	ft_all_base(ft_init_char(param->spec), tab, ft_ibase(param->spec), param);
}
