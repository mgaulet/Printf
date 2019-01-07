#include "../includes/ft_printf.h"


#define LS_BYTES				0x0101010101010101ULL
#define MS_BYTES				0x8080808080808080ULL
#define LONG_WORD_HAS_ZERO(lw)	(((lw - LS_BYTES) & ~(lw)) & MS_BYTES)
#define TEST_BYTE(x)			if (!ptr[x]) return (ptr - str + x)


void	ft_bzero(void *m, size_t len)
{
	uint64_t	*long_word;

	while (len % 8)
	{
		*(uint8_t *)m++ = (uint8_t)0;
		--len;
	}
	if (len)
	{
		long_word = (uint64_t *)m;
		while (len)
		{
			*long_word++ = (uint64_t)0;
			len -= 8;
		}
	}
}

int		ft_atoi(const char *s)
{
	int		n;
	bool	sign;

	while ((*s == ' ') || (*s > 8 && *s < 14))
		s++;
	sign = (*s == '-');
	if (*s == '+' || *s == '-')
		s++;
	n = (*s >= '0' && *s <= '9') ? *s++ - '0' : 0;
	while (*s >= '0' && *s <= '9')
		n = (n * 10) + *s++ - '0';
	return (sign) ? -n : n;
}


size_t	ft_strlen(const char *str)
{
	const char		*ptr;

	ptr = str;
	while ((uint64_t)ptr % 8)
	{
		if (!*ptr)
			return (ptr - str);
		++ptr;
	}
	while (1)
	{
		if (LONG_WORD_HAS_ZERO(*(uint64_t*)ptr))
		{
			TEST_BYTE(0);
			TEST_BYTE(1);
			TEST_BYTE(2);
			TEST_BYTE(3);
			TEST_BYTE(4);
			TEST_BYTE(5);
			TEST_BYTE(6);
			TEST_BYTE(7);
		}
		ptr += 8;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	return (ft_all(fmt, ap));
}