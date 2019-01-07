#include "../includes/ft_printf.h"

void ft_nb(t_param *param)
{
	int index;

	param->len = ft_all_base_len(ft_init_char(param->spec), (uint64_t)param->data, ft_ibase(param->spec), 0);
	if (param->precision >= 0 && param->data == 0)
		param->len -= 1;
	index = 0;
	while (param->tab[index] != 0)
	{
		if (param->tab[index] == 2)
			if ((param->moinsOuPas == true && param->precision == -1 && !ft_cherche_tab(param->tab, 4))  || ((param->mini_champ == 0) && (param->moinsOuPas == true && param->precision == -1)))
				ft_print_len("-", param, 1);
		(*ptr_sur_fc_flags[param->tab[index++]])(param);
	}
}
