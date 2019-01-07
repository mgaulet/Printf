#include "../includes/ft_printf.h"

#define NP(fmt, c)  (fmt != c)


void ft_print_len(const char *c, t_param *param, int size)
{
	param->totolen += size;
	write(1, c, size);
}

int ft_all_1(t_param *param, int *ff, va_list ap, const char **fmt)
{
	if (**fmt == '%' && *((*fmt) + 1) != '%')
	{
		*ff = ft_ini_jsp(*fmt, fmt, param);
		if (*ff == 1)
		{
			ft_init_vaarg(*fmt, init_spec_t(*fmt), param, ap);
			ft_parce(*fmt, param);
  			(*ptr_sur_function[AJUST(param->spec)])(param);
  			if (param->error == -1)
  				return -1;		// return -1;
  			init_spec_par_ptr(fmt);
  			if (*(++(*fmt)) == '\0')
  				return 0;		// break;
  		}
  		else if (*ff == -1)
  			return 0; 			// break;
  	}
  	return 4;
}

void ft_all_2(t_param *param, int *ff, const char **fmt, int *XIX)
{
  	if (*ff == 1 || **fmt == '%')
  	{
		if (**fmt == '%' && *((*fmt) + 1) == '%')
		{
			*XIX = 1;
			ft_print_len(*fmt, param, 1);
			*fmt += 2;
		}
		else if ((**fmt != '%' && *((*fmt) - 1) != '%') || (*XIX == 1 && (**fmt != '%')))
		{
			if (*XIX == 1)
				*XIX = 0;
			ft_print_len((*fmt)++, param, 1);
		}
	}
	else if (param->jsp_0 != -1)
		ft_print_len((*fmt)++, param, 1);
	ft_free(param);
}

int		ft_all(const char *fmt, va_list ap)
{
	t_param param;
	int 	ff;
	int 	XIX;
	int 	rtn;

	rtn = 4;
	XIX = 0;
	ff = 0;
	param.totolen = 0;
	param.spec = 0;
	while (*fmt != '\0')
	{
		rtn = ft_all_1(&param, &ff, ap, &fmt);
		if (rtn == -1)
			return -1;
		else if (rtn == 0)
			break;
		ft_all_2(&param, &ff, &fmt, &XIX);
 	}
 	va_end(ap);
	return param.totolen;
}
