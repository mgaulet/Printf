#include "../../includes/ft_printf.h"

void ft_jecpas(int nb, uint64_t maxi, t_param *param, uint64_t tmp)
{
    param->data = ((tmp << nb) >> nb);
    if (param->data > maxi)
    {
		param->moinsOuPas = true;
        param->data = (~((param->data << nb) - 1) >> nb);
    }
}

void ft_utu(t_param *param, uint64_t tmp)
{
	param->data = tmp;
}

void ft_JJ(t_param *param, uint64_t tmp)
{
	intmax_t nb;

	nb = (intmax_t)tmp;
	param->data = nb;
}
