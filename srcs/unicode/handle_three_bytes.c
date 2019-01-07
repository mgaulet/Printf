#include "../../includes/ft_printf.h"


void        pf_handle_four_bytes(wint_t c)
{
    ft_putchar(((c >> 18) | 0xF0));
    ft_putchar((((c >> 12) | 0x80) & 0xBF));
    ft_putchar((((c >> 6) | 0x80) & 0xBF));
    ft_putchar(((c | 0x80) & 0xBF));
}

void        pf_handle_three_bytes(wint_t c)
{
    ft_putchar(((c >> 12) | 0xE0));
    ft_putchar((((c >> 6) | 0x80) & 0xBF));
    ft_putchar(((c | 0x80) & 0xBF));
}

void        pf_handle_two_bytes(wint_t c)
{
    ft_putchar(((c >> 6) | 0xC0));
    ft_putchar(((c | 0x80) & 0xBF));
}

void        pf_handle_one_byte(wint_t c)
{
    ft_putchar(c);
}