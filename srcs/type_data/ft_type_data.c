#include "../../includes/ft_printf.h"

void ft_norme_une_vaarg(t_param *param, uint64_t *tmp, char tt, char c, va_list ap)
{
	*tmp = va_arg(ap, uint64_t);
	param->plus = true;
	if (tt == 'L' || c == 'D' || tt == 'j' || tt == 'z' || tt == 'l')
		ft_jecpas(0, 9223372036854775807, param, *tmp);
	else if (tt == 'h' && c != 'D')
		ft_jecpas(48, 32767, param, *tmp);
	else if (tt == 'H' && c != 'D')
		ft_jecpas(56, 127, param, *tmp);
	else
		ft_jecpas(32, 2147483647, param, *tmp);
}

void ft_norme_deux_vaarg(t_param *param, uint64_t *tmp, char tt, char c, va_list ap)
{
	*tmp = va_arg(ap, uint64_t);
	param->plus = false;
	if (tt == 'h' && c != 'U')
		ft_jecpas(48, 65535, param, *tmp);
	else if (tt == 'H' && c != 'U' && c != 'O')
		ft_jecpas(56, 255, param, *tmp);
	else if ((tt == 'j' || tt == 'z' ) && c != 'U')
		ft_JJ(param, *tmp);
	else if (tt == 'L' || tt == 'l' || c == 'O')
		ft_utu(param, *tmp);
	else
		if (c == 'U')
			ft_utu(param, *tmp);
		else
			ft_jecpas(32, 4294967295, param, *tmp);
}
void ft_varg_1(char *tab, t_param *param, uint64_t *tmp, va_list ap)
{
	if (tab[1] == 'd' || tab[1] == 'D' || tab[1] == 'i')
		ft_norme_une_vaarg(param, tmp, tab[0], tab[1], ap);
	else if (tab[1] == 'x' || tab[1] == 'X' || tab[1] == 'o' || tab[1] == 'u' || tab[1] == 'U' || tab[1] == 'O')
		ft_norme_deux_vaarg(param, tmp, tab[0], tab[1], ap);
	else if (tab[1] == 's' && tab[0] != 'l')
	{
		param->ptr_char = va_arg(ap, char *);
		if (param->ptr_char == NULL)
			return;
		param->len = ft_strlen(param->ptr_char);
	}
	else if (tab[1] == 'c' && tab[0] != 'l')
		param->pourChar = (char)va_arg(ap, int);
	else if (tab[1] == 'S' || (tab[0] == 'l' && tab[1] == 's'))
	{
		param->spec = 'S';
		param->ptr_S = va_arg(ap, wchar_t *);
		if (param->ptr_S == NULL)
			return;
	}
	else if (tab[1] == 'C' || (tab[0] == 'l' && tab[1] == 'c'))
	{
		param->spec = 'C';
		param->ptr_C = va_arg(ap, wint_t);
	}
}
void ft_init_vaarg(const char *str, char c, t_param *param, va_list ap)
{
	uint64_t 	tmp;
	char 		tab[2];

	tab[1] = c;
	if (tab[1] == '%')
		return;
	tab[0] = init_spec_L(str, param);
	if (tab[1] == 'p')
	{
		tab[1] = 'x';
		tab[0] = 'L';
	}
	tmp = 0;
	ft_varg_1(tab, param, &tmp, ap);

}

void ft_free(t_param *param)
{
	ft_bzero(param->tab, (8 * 4));
	param->mini_champ = 0;
	param->tab_fl = 0;
	param->precision = 0;
	param->spec = 0;
	param->len = 0;
	param->positif = true;
	param->data = 0;
	param->moinsOuPas = false;
	param->a = 0;
	param->ptr_char = NULL;
	param->pourChar = 0;
	param->moinsOuPas = false;
	param->pourle = 0;
	param->plus = false;
	param->ptr_C = 0;
	param->ptr_S = 0;	
	param->jsp_0 = 0;
}
