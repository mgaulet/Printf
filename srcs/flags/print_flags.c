#include "../../includes/ft_printf.h"

void	ft_zero(t_param *param)
{
		if (param->mini_champ > 0)
		return;
	return;
}

void	ft_htg(t_param *param)
{
	if ((uint64_t)param->data != 0)
	{
		if ((param->spec == 'o' || param->spec == 'O') && param->precision < 1)
			ft_print_len("0", param, 1);
		else if (param->spec == 'x')
			ft_print_len("0x", param, 2);
		else if (param->spec == 'X')
			ft_print_len("0X", param, 2);
	}
}

void	ft_espace(t_param *param)
{
	if (param->mini_champ > 0)
		return;
	if (!param->moinsOuPas)
		ft_print_len(" ", param, 1);
}

void	ft_plus(t_param *param)
{
	if (param->plus == true)
			ft_print_len("+", param, 1);
	else
		param->mini_champ += 1;
}

void	ft_moins(t_param *param)
{
	int 	acumul;
	char	c;

	acumul = 0;
	if (param->moinsOuPas == true)
		param->pourle = 1;
	acumul += param->pourle;
	 if (param->spec == 'o' &&
	  (true == ft_cherche_tab(param->tab, 3)) &&
	  (true == ft_cherche_tab(param->tab, 6)))
	 	acumul -= 1;
	acumul += (ft_cherche_tab(param->tab, 5) ? 1 : 0);
	c = (ft_cherche_tab(param->tab, 4)) ? '0' : ' ';
	if ((param->spec == 'o') && (true == ft_cherche_tab(param->tab, 6)))
		acumul += 1;
	else if ((param->spec == 'x' || param->spec == 'X') && (true == ft_cherche_tab(param->tab, 6)))
		acumul += 2;
	acumul += (ft_cherche_tab(param->tab, 7) ? 1 : 0);
	acumul += (param->precision >= param->len) ? param->precision : param->len;
	param->mini_champ -= acumul;
	if (param->moinsOuPas == true && param->precision == -1 && ft_cherche_tab(param->tab, 4))
		ft_print_len("-", param, 1);
	while (param->mini_champ-- > 0)
		ft_print_len(&c, param, 1);
}