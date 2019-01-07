#include "../../includes/ft_printf.h"

char 	init_spec_L(const char *str, t_param *param)
{
	param->tab_fl = 0;

	str++;
	while(	*str != 'c' && *str != 's' && *str != 'd' &&
			*str != 'x' && *str != 'o' && *str != 'i' && 
			*str != 'p' && *str != 'u' && *str != 'C' && 
			*str != 'S' && *str != 'D' && *str != 'X' && 
			*str != 'O' && *str != 'U' && *str != '%')
	{
		if ((CP(*str, 'h') && CP(*(str+1), 'h')) ||
		        (CP(*str, 'l') && CP(*(str+1), 'l')))
			return param->tab_fl = *(str++) - 32;
		else if ((CP(*str, 'l') || CP(*str, 'h')
		  || CP(*str, 'z') || CP(*str, 'j')))
				return param->tab_fl = *str;
		str++;
	}
	return 0;
}

char	init_spec_t(const char *ptr)
{
	while(*(ptr++))
	{
		if (CP(*ptr, 'c') || CP(*ptr, 's') || CP(*ptr, 'd') ||
			CP(*ptr, 'x') || CP(*ptr, 'o') || CP(*ptr, 'i') || 
			CP(*ptr, 'p') || CP(*ptr, 'u') || CP(*ptr, 'C') || 
			CP(*ptr, 'S') || CP(*ptr, 'D') || CP(*ptr, 'X') || 
			CP(*ptr, 'O') || CP(*ptr, 'U') || CP(*ptr, '%'))
				break;
	}
	return (*ptr);
}