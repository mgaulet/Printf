/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:15:59 by agaulet           #+#    #+#             */
/*   Updated: 2017/06/13 11:29:30 by agaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

# include            <fcntl.h>
# include            <stdio.h>
# include            <stdlib.h>
# include            <inttypes.h>
# include            <stdint.h>
# include            <locale.h>
# include            <wchar.h>
# include            <string.h>
# include 			 <stdarg.h>
# include            <unistd.h>
# include 			 <locale.h>

# define	AJUST(i)			((i > 'Z') ? (i - 97) : (i - 41))
# define 	CP(i, a)  			(i == a)
# define 	IS_DEMI_CODETS(n)   (n > 0x0000D7FF && n < 0x0000E000)

# define 	GRAND_X	"0123456789ABCDEF"
# define 	PETIT_X	"0123456789abcdef"

# define 	BYTE_MAX_VALUE              0x000000FF
# define 	EIGHT_BITS_MIN_VALUE        0x00000080
# define 	TWELVE_BITS_MIN_VALUE       0x00000800
# define 	SEVENTEEN_BITS_MIN_VALUE    0x00010000
# define 	TWENTYTWO_BITS_MIN_VALUE    0x00400000


typedef struct s_param		t_param;

struct		s_param
{
	int 			tab[8];
	int 			a;
	int 			mini_champ;
	char			tab_fl;
	int 			precision;
	unsigned char	spec;
	int 			len;
	wchar_t 		*ptr_S;
	wint_t 			ptr_C;
	bool 			positif;
	uint64_t 		data;
	char 			*ptr_char;
	char 			pourChar;
	bool			moinsOuPas;
	int 			pourle;
	bool 			plus; // pour le plus
	int 			totolen;
	int 			error;
	int 			jsp_0;
};

void	init_spec_par_ptr(const char **ptr);
int 	ft_ini_jsp_1(const char *ptr, t_param *param, const char **ft, int *i);
int 	ft_ini_jsp(const char *ptr, const char **fmt, t_param *param);

void 		ft_putchar(char c);
void        pf_handle_four_bytes(wint_t c);
void        pf_handle_three_bytes(wint_t c);
void        pf_handle_two_bytes(wint_t c);
void        pf_handle_one_byte(wint_t c);

int64_t     pf_wint_tlen(wint_t c, t_param *param);
int64_t     pf_wint_tlens(wint_t c);
int64_t     pf_wchar_tlen(wchar_t *w);
int64_t     pf_wchar_tnlen(wchar_t *w, int precision);


void	ft_ignor(t_param *param, int nb, int nb2);
void	ft_ignor2(t_param *param, char c, int flags);
void	ft_ignor3(t_param *param);
void	ft_switch(t_param *param);
void	ft_switch2(t_param *param);


int		ft_printf(const char *fmt, ...);
void 	ft_putchar(char c);

void 	ft_print_len(const char *c, t_param *param, int size);
bool 	ft_cherche_tab(int *tab, int nb);

void	ft_bzero(void *m, size_t len);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *s);

bool 	ft_cherche_tab(int *tab, int nb);
void	ft_parce(const char *str, t_param *param); 
void	ft_parce_long(const char *str, const char *ptr, t_param *param);
void	ft_parce_precision(const char *str, const char *ptr, t_param *param);
void	ft_parce_mini_champ(const char *str, t_param *param);
void	ft_parce_op(const char *str, t_param *param);
void	ft_parce_spec( const char *ptr, t_param *param);

void 	ft_modulo(t_param *param);
void 	ft_s(t_param *param);
void 	ft_S(t_param *param);
void 	ft_p(t_param *param);
void 	ft_c(t_param *param);
void 	ft_C(t_param *param);
void	ft_nb(t_param *param);
void 	ft_notConv(t_param *param);

void	ft_all_bases(t_param *param);
void	ft_precision(t_param *param);
void	ft_zero(t_param *param);
void	ft_htg(t_param *param);
void	ft_espace(t_param *param);
void	ft_plus(t_param *param);
void	ft_moins(t_param *param);
void	ft_void(t_param *param);
void 	ft_all_bases(t_param *param);

char 	init_spec_L(const char *str, t_param *param);
void 	ft_init_vaarg(const char *str, char c, t_param *param, va_list ap);
char	init_spec_t(const char *ptr);
void 	ft_free(t_param *param);

char 	*ft_init_char(char c);
uint8_t ft_ibase(char c);
void 	ft_all_base(char *str, uint64_t *nb, uint8_t base, t_param *param);
int 	ft_all_base_len(char *str, uint64_t nb, uint8_t base, int len);
int		ft_all(const char *fmt, va_list ap);

void 	ft_jecpas(int nb, uint64_t maxi, t_param *param, uint64_t tmp);
void 	ft_JJ(t_param *param, uint64_t tmp);
void 	ft_utu(t_param *param, uint64_t tmp);

int64_t pf_wint_tlen(wint_t c, t_param *param);

static void (*ptr_sur_function[48])(t_param *param) =
{
	ft_modulo,
	0,
	ft_c,
	ft_nb,
	0,
	0,
	0,
	0,
	ft_nb,
	0,
	0,
	0,
	0,
	0,
	ft_nb,
	ft_p,
	0,
	0,
	ft_s,
	0,
	ft_nb,
	0,
	0,
	ft_nb,
	0,
	0,
	ft_C,
	ft_nb,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	ft_nb,
	0,
	0,
	ft_notConv, // R
	ft_S,
	0,
	ft_nb,
	0,
	0,
	ft_nb
};

static void (*ptr_sur_fc_flags[10])(t_param *param) =
{
	0,
	ft_moins,
	ft_all_bases,
	ft_precision,
	ft_zero,
	ft_espace,
	ft_htg,
	ft_plus,
	ft_moins,
	ft_void,
};

static void (*g_handle_byte[4])(wint_t) =
{
    pf_handle_one_byte,
    pf_handle_two_bytes,
    pf_handle_three_bytes,
    pf_handle_four_bytes
};

#endif
