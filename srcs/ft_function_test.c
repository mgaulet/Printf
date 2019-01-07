#include "../includes/ft_printf.h"


void ft_p_1(int *tab, t_param *param)
{
	if (tab[1] >= 0)
		tab[4] = (param->len + tab[1]);
	if (param->precision > 0)
		tab[3] = (param->len >= (param->precision + 2)) ? param->len : (param->precision + 2); 
	else
		tab[3] = param->len;
	tab[2] = param->mini_champ - tab[3];
	if (ft_cherche_tab(param->tab, 8))
		if (tab[2] > 0 && param->mini_champ > tab[4])
			while(tab[2] != tab[5]++)
				ft_print_len(" ", param, 1);
}

void ft_p(t_param *param)
{
	int tab[6];

	tab[5] = 0;
	tab[4] = 0;
	tab[0] = (ft_all_base_len(PETIT_X, param->data, 16, 0) + 2);
	tab[3] = tab[0];
	param->len = tab[0];
	tab[1] = param->precision - tab[0] + 2;
	ft_p_1(tab, param);
	ft_print_len("0x", param, 2);
	if (tab[1] > 0)
		while(tab[1]-- != 0)
			ft_print_len("0", param, 1);
	if ((param->data == 0 && param->precision != 0) || param->data > 0)
	{
		if (param->data == 0 && param->precision > 0)
			ft_print_len("0", param, 1);		
		ft_all_base(PETIT_X, &param->data, 16, param);	
	}
	if (ft_cherche_tab(param->tab, 1))
		if (tab[2] > 0 && param->mini_champ > param->len)
			while(tab[2] != tab[5]++)
				ft_print_len(" ", param, 1);
	return;
}

void ft_c(t_param *param)
{
	int x;
	int mini;
	int lenn;

	x = 0;
		lenn = 1;
	mini = param->mini_champ - lenn;
	
	if (ft_cherche_tab(param->tab, 8))
		if (mini > 0 && param->mini_champ > param->len)
			while(mini != x++)
				ft_print_len(" ", param, 1);

	x = 0;
	ft_print_len(&param->pourChar, param, 1);
	x = 0;
	if (ft_cherche_tab(param->tab, 1))
		if (mini > 0 && param->mini_champ > param->len)
			while(mini != x++)
				ft_print_len(" ", param, 1);
	return;
}

void ft_s_1(t_param *param, int *tab)
{
	if (param->precision >= 0)
		tab[2] = (param->len < param->precision) ? param->len : param->precision; 
	else
		tab[2] = param->len;
	tab[1] = param->mini_champ - tab[2];
	if (ft_cherche_tab(param->tab, 8))
		if (tab[1] > 0 && param->mini_champ > tab[2])
			while(tab[1] != tab[0]++)
				ft_print_len(" ", param, 1);
}

void ft_s(t_param *param)
{
	int tab[3];

	tab[0] = 0;
	if (param->ptr_char == NULL)
	{
		ft_print_len("(null)", param, 6);
		return;
	}
	ft_s_1(param, tab);
	tab[0] = 0;
	while(tab[2] != tab[0]++)
			ft_print_len(param->ptr_char++, param, 1);
	tab[0] = 0;
	if (ft_cherche_tab(param->tab, 1))
		if (tab[1] > 0 && param->mini_champ > tab[2])
			while(tab[1] != tab[0]++)
				ft_print_len(" ", param, 1);
	return;
}
