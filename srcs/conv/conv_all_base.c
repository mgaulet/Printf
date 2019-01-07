#include "../../includes/ft_printf.h"



void ft_all_base(char *str, uint64_t *nb, uint8_t base, t_param *param)
{
	uint64_t tmp;

	tmp = nb[0];
	if (!nb[0])
	{
		if ((nb[1] == 0 && param->precision == -1) ||
			(nb[1] == 0 && param->precision == 0 &&
				ft_cherche_tab(param->tab, 6) &&
				param->spec == 'o'))
			ft_print_len("0", param, 1);
		return ;
	}
	nb[1] += 1;
	nb[0] = (nb[0] / base);
	ft_all_base(str, nb, base, param);
	ft_print_len((&str[tmp % base]), param, 1);
}

int ft_all_base_len(char *str, uint64_t nb, uint8_t base, int len)
{
	if (!nb)
	{
		if (len)
			return len;
		else
			return 1;
	}
	 return (ft_all_base_len(str, (nb / base), base, (len + 1)));
}
