#include "../../includes/ft_printf.h"

int		ft_init_signe(char c)
{
	if (CP(c, ' '))
		return 5;
	else if (CP(c, '+'))
		return 7;
	else if (CP(c, '#'))
		return 6;
	else if (CP(c, '0'))
		return 4;
	else if (CP(c, '-'))
		return 1;
	return 0;
}

void	ft_parce_spec( const char *ptr, t_param *param)
{
	if (*ptr == '%')
		param->spec = 97;
	else
		param->spec = *ptr;
	param->tab[(param->a)++] = 2;
}

void	ft_parce_op(const char *str, t_param *param)
{
	int i;

	i = 0;
	if (!(CP(*str, '0') || CP(*str, '#') || CP(*str, '+') ||
				CP(*str, '-') || CP(*str, ' ')))
			return;
	while(CP(*str, '0') || CP(*str, '#') || CP(*str, '+') ||
		  CP(*str, '-') || CP(*str, ' '))
	{		if (!ft_cherche_tab(param->tab, ft_init_signe(*str)))
				param->tab[(param->a)++] = ft_init_signe(*str);
			if (i++ == 5)
				break;
		str++;
	}
}

void	ft_parce_mini_champ(const char *str, t_param *param)
{
	int y;

	y = 0;
	param->mini_champ = 0;

	while(CP(*str, '0') || CP(*str, '#') || CP(*str, '+') ||
			CP(*str, '-') || CP(*str, ' '))
		str++;
	if (!(47 < *str && 58 > *str))
		return;	
	param->mini_champ = ft_atoi(str);

	while(y != 9)
	{
		if (param->tab[y] == 1)
			break;
		else if (param->tab[y] == 0)
		{
			param->tab[y] = 8;
			(param->a)++;
			break;
		}
		y++;
	}
}

void	ft_parce_precision(const char *str, const char *ptr, t_param *param)
{
	param->precision = -1;

	while(ptr > str)
	{
		if (CP(*str, '.'))
			{
				param->precision = 0;
				str++;
				if (47 < *str && 58 > *str)
					param->precision = ft_atoi(str);
				param->tab[(param->a)++] = 3;
				break;
			}
		str++;
	}
}

void	ft_parce_long(const char *str, const char *ptr, t_param *param)
{
	param->tab_fl = 0;

	while(ptr > str)
	{
		if ((CP(*str, 'h') && CP(*(str+1), 'h')) ||
		        (CP(*str, 'l') && CP(*(str+1), 'l')))
		{
			param->tab_fl = *(str++) - 32;
			break;
		}
		else if ((CP(*str, 'l') || CP(*str, 'h')
		  || CP(*str, 'z') || CP(*str, 'j')))
			{
				param->tab_fl = *str;
				break;
			}
		str++;
	}
}

