#include "../../includes/ft_printf.h"

void	ft_negatif(t_param *param)
{
	int i;

	i = 0;
	if (param->moinsOuPas == true)
		while(param->tab[i] != 0)
			{
				if (param->tab[i] == 7)
					param->tab[i] = 9;
				i++;
			}
}

void	ft_tris_re(t_param *param, int a)
{
	int tp[2];
	int i;

	i = 0;
	tp[0] = 0;
	tp[1] = 0;
	if (a == 8)
		return;
	while (i != 8)
	{
		if (param->tab[i] > tp[0])
		{
			tp[0] = param->tab[i];
			tp[1] = i;
		}
		i++;
	}
	param->tab[tp[1]] = 0;
	ft_tris_re(param, a + 1);
	param->tab[a] = tp[0];
}

void ft_parce_1(const char **ptr, t_param *param, const char *str)
{
	int i;

	i = 0;
	while(*((*ptr)++))
	{
		if (CP(**ptr, 'c') || CP(**ptr, 's') || CP(**ptr, 'd') ||
			CP(**ptr, 'x') || CP(**ptr, 'o') || CP(**ptr, 'i') || 
			CP(**ptr, 'p') || CP(**ptr, 'u') || CP(**ptr, 'C') || 
			CP(**ptr, 'S') || CP(**ptr, 'D') || CP(**ptr, 'X') || 
			CP(**ptr, 'O') || CP(**ptr, 'U') || CP(**ptr, '%'))
			break;
	}
	while(i != 10)
		param->tab[i++] = 0;
	param->a = 0;
	ft_parce_long(str, *ptr, param);
	ft_parce_precision(str, *ptr, param);
	ft_parce_op(str, param);
	ft_parce_mini_champ(str, param);
	if (!param->spec)
		ft_parce_spec(*ptr, param);
}

void	ft_parce(const char *str, t_param *param) 
{
	const char *ptr;

	ptr = str;
	str++;
	ft_parce_1(&ptr, param, str);
	if (param->spec != 97)
	{
		ft_ignor(param, 7, 5);
		ft_ignor(param, 1, 4);
		ft_ignor(param, 3, 4);
		ft_ignor2(param, param->spec, 5);
	}
	else
		ft_ignor3(param);
	if (param->spec == 'd'|| param->spec == 'i' || param->spec == 'D')
		ft_negatif(param);
	ft_tris_re(param, 0);
	if (param->spec != 97)
	{
		ft_switch(param);
		if (ft_cherche_tab(param->tab, 4) && ft_cherche_tab(param->tab, 6))
		ft_switch2(param);
	}
}
