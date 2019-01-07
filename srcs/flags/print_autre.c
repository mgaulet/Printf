#include "../../includes/ft_printf.h"

void ft_modulo(t_param *param)
{
	char c;
	int x;

	x = 0;
	c = (ft_cherche_tab(param->tab, 4) ? '0' : ' ');
	if (ft_cherche_tab(param->tab, 1))
		c = ' ';
	param->mini_champ -= 1;
	if (param->mini_champ < 0)
		param->mini_champ = 0;

	if (ft_cherche_tab(param->tab, 8))
		while (param->mini_champ-- > 0)
			ft_print_len(&c, param, 1);
	ft_print_len("%", param, 1);
	if (ft_cherche_tab(param->tab, 1))
		while (param->mini_champ-- > 0)
			ft_print_len(&c, param, 1);
}

void	ft_precision(t_param *param)
{
	int i;

	if (param->moinsOuPas == true)
		ft_print_len("-", param, 1);
	i = param->precision - param->len;
	while (i-- > 0)
		ft_print_len("0", param, 1);
	param->pourle = 0;
}


void ft_notConv(t_param *param)
{
		if (param->mini_champ > 0)
		return;
	return;
}

bool 	ft_cherche_tab(int *tab, int nb)
{
	int i;

	i = 0;
	while(i != 8)
		if (tab[i++] == nb)
			return true;
	return false;
}

void	ft_void(t_param *param)
{
		if (param->mini_champ > 0)
		return;
	return;
}