#include "../includes/ft_printf.h"

void	init_spec_par_ptr(const char **ptr)
{
	while(*((*ptr)++))
	{
		if (CP(**ptr, 'c') || CP(**ptr, 's') || CP(**ptr, 'd') ||
			CP(**ptr, 'x') || CP(**ptr, 'o') || CP(**ptr, 'i') || 
			CP(**ptr, 'p') || CP(**ptr, 'u') || CP(**ptr, 'C') || 
			CP(**ptr, 'S') || CP(**ptr, 'D') || CP(**ptr, 'X') || 
			CP(**ptr, 'O') || CP(**ptr, 'U') || CP(**ptr, '%'))
				break;
	}
}

int 	ft_ini_jsp_1(const char *ptr, t_param *param, const char **ft, int *i)
{
	if (CP(*ptr, 'c') || CP(*ptr, 's') || CP(*ptr, 'd') ||
		CP(*ptr, 'x') || CP(*ptr, 'o') || CP(*ptr, 'i') ||
		CP(*ptr, 'p') || CP(*ptr, 'u') || CP(*ptr, 'C') ||
		CP(*ptr, 'S') || CP(*ptr, 'D') || CP(*ptr, 'X') ||
		CP(*ptr, 'O') || CP(*ptr, 'U') || CP(*ptr, '%') ||
		CP(*ptr, ' ') || CP(*ptr, '#') || CP(*ptr, '+') ||
		CP(*ptr, '-') || CP(*ptr, '.') || CP(*ptr, '0') ||
		CP(*ptr, 'h') || CP(*ptr, 'l') || CP(*ptr, 'j') ||
		(*ptr > 47 && *ptr < 58) || CP(*ptr, 'z'))
	{
		if (CP(*ptr, 'c') || CP(*ptr, 's') || CP(*ptr, 'd') ||
			CP(*ptr, 'x') || CP(*ptr, 'o') || CP(*ptr, 'i') || 
			CP(*ptr, 'p') || CP(*ptr, 'u') || CP(*ptr, 'C') || 
			CP(*ptr, 'S') || CP(*ptr, 'D') || CP(*ptr, 'X') || 
			CP(*ptr, 'O') || CP(*ptr, 'U') || CP(*ptr, '%'))
		return 1;
	}
	else
	{
		if (*ptr == '\0')
			param->jsp_0 = -1;
		((*ft) += *i);
		return 0;
	}
	return 4;
}

int 	ft_ini_jsp(const char *ptr, const char **fmt, t_param *param)
{
	int i;
	int rtn;

	i = 1;
	ptr++;
	if(*ptr == '\0')
		return -1;
	rtn = 4;
	while(*ptr)
	{
		rtn = ft_ini_jsp_1(ptr, param, fmt, &i);
		if (rtn == 1)
			return 1;
		else if (rtn == 0)
			return 0;
		ptr++;
		i++;
	}
	if (*ptr == '\0')
		param->jsp_0 = -1;
	((*fmt) += i);
	return 0;
}
