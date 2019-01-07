#include "../../includes/ft_printf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_S_1(int *tab, t_param *param)
{
    if (param->ptr_S == NULL)
    {
        ft_print_len("(null)", param, 6);
        return;
    }
    param->len =  pf_wchar_tlen(param->ptr_S);
    tab[5] = pf_wchar_tnlen(param->ptr_S, param->precision);
    if (param->precision >= 0)
        tab[2] = (tab[5] < param->precision) ? tab[5] : param->precision; 
    else
        tab[2] = param->len;
    if (param->precision != -1)
    {
        param->totolen += tab[5];
        tab[1] = param->mini_champ - tab[5];
    }
    else
    {
        param->totolen += tab[2];
        tab[1] = param->mini_champ - tab[2];
    }
}

void ft_S(t_param *param)
{
    int tab[6];

    tab[3] = 0;
    tab[0] = 0;
    tab[4] = 0;
    ft_S_1(tab, param);
    if (ft_cherche_tab(param->tab, 8))
        if (tab[1] > 0 && param->mini_champ > tab[2])
            while(tab[1] != tab[0]++)
                ft_print_len(" ", param, 1);
    tab[0] = 0;
    while(tab[2] > tab[0])
    {
        tab[0] += pf_wint_tlens(param->ptr_S[tab[4]]);
        tab[3] = pf_wint_tlens(param->ptr_S[tab[4]]);
        if (tab[2] >= tab[0])
        (*g_handle_byte[(tab[3] - 1)])(param->ptr_S[tab[4]++]);
    }
    tab[0] = 0;
    if (ft_cherche_tab(param->tab, 1))
        if (tab[1] > 0 && param->mini_champ > tab[2])
            while(tab[1] != tab[0]++)
                ft_print_len(" ", param, 1);
    return;
}


void ft_C(t_param *param)
{
    int x;
    int mini;
    int lenn;

    x = 0;
    lenn = pf_wint_tlen(param->ptr_C, param);
    
    if (lenn == -1)
    {
        param->error = lenn;
        return;
    }
    mini = param->mini_champ - lenn;
    if (ft_cherche_tab(param->tab, 8))
        if (mini > 0 && param->mini_champ > lenn)
            while(mini != x++)
                ft_print_len(" ", param, 1);
    (*g_handle_byte[(lenn - 1)])(param->ptr_C);
    x = 0;
    if (ft_cherche_tab(param->tab, 1))
        if (mini > 0 && param->mini_champ > param->len)
            while(mini != x++)
                ft_print_len(" ", param, 1);
    return;
}