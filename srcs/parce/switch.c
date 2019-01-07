#include "../../includes/ft_printf.h"

void	ft_switch(t_param *param)
{
	int tmp;

	if (ft_cherche_tab(param->tab, 4) == true && ft_cherche_tab(param->tab, 7) == true)
	{
		tmp = param->tab[0];
		param->tab[0] = param->tab[1];
		param->tab[1] = tmp;
	}
}

void	ft_switch2(t_param *param)
{
	int tmp;

	if (ft_cherche_tab(param->tab, 6) == true && ft_cherche_tab(param->tab, 8) == true)
	{
		tmp = param->tab[0];
		param->tab[0] = param->tab[1];
		param->tab[1] = tmp;
	}
}
