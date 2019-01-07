#include "../../includes/ft_printf.h"

int64_t        pf_wint_tlen(wint_t c, t_param *param)
{
    if (IS_DEMI_CODETS(c) || c < 0)
        return (-1);
    if ((c < EIGHT_BITS_MIN_VALUE) || (c <= BYTE_MAX_VALUE && MB_CUR_MAX == 1))
    {
        param->totolen += 1;
        return (1);
    }
    else if (c < TWELVE_BITS_MIN_VALUE && MB_CUR_MAX > 1)
    {
        param->totolen += 2;
        return (2);
    }
    else if (c < SEVENTEEN_BITS_MIN_VALUE && MB_CUR_MAX > 2)
    {
        param->totolen += 3;
        return (3);
    }
    else if (c < TWENTYTWO_BITS_MIN_VALUE && MB_CUR_MAX > 3)
    {
        param->totolen += 4;
        return (4);
    }
    else
        return (-1);
}

int64_t        pf_wint_tlens(wint_t c)
{
    if (IS_DEMI_CODETS(c) || c < 0)
        return (-1);
    if ((c < EIGHT_BITS_MIN_VALUE) || (c <= BYTE_MAX_VALUE && MB_CUR_MAX == 1))
        return (1);
    else if (c < TWELVE_BITS_MIN_VALUE && MB_CUR_MAX > 1)
        return (2);
    else if (c < SEVENTEEN_BITS_MIN_VALUE && MB_CUR_MAX > 2)
        return (3);
    else if (c < TWENTYTWO_BITS_MIN_VALUE && MB_CUR_MAX > 3)
        return (4);
    else
        return (-1);
}



int64_t            pf_wchar_tlen(wchar_t *w)
{
    int64_t        len;

    len = 0;
    while (*w)
    {
        if (IS_DEMI_CODETS(*w) || w < 0)
            return (-1);
        if ((*w < EIGHT_BITS_MIN_VALUE) ||
                (*w <= BYTE_MAX_VALUE && MB_CUR_MAX == 1))
            len += 1;
        else if (*w < TWELVE_BITS_MIN_VALUE && MB_CUR_MAX > 1)
            len += 2;
        else if (*w < SEVENTEEN_BITS_MIN_VALUE && MB_CUR_MAX > 2)
            len += 3;
        else if (*w < TWENTYTWO_BITS_MIN_VALUE && MB_CUR_MAX > 3)
            len += 4;
        else
            return (-1);
        ++w;
    }
    return (len);
}

int64_t            pf_wchar_tnlen(wchar_t *w, int precision)
{
    int64_t        len;

    len = 0;
    while (*w && precision)
    {
        if (IS_DEMI_CODETS(*w) || *w < 0)
            return (-1);
        if ((*w < EIGHT_BITS_MIN_VALUE) ||
                (*w <= BYTE_MAX_VALUE && MB_CUR_MAX == 1))
        {
            --precision;
            ++len;
        }
        else if (*w < TWELVE_BITS_MIN_VALUE && MB_CUR_MAX > 1)
            ((precision -= 2) < 0) ? (precision = 0) : (len += 2);
        else if (*w < SEVENTEEN_BITS_MIN_VALUE && MB_CUR_MAX > 2)
            ((precision -= 3) < 0) ? (precision = 0) : (len += 3);
        else if (*w < TWENTYTWO_BITS_MIN_VALUE && MB_CUR_MAX > 3)
            ((precision -= 4) < 0) ? (precision = 0) : (len += 4);
        else
            return (-1);
        ++w;
    }
    return (len);
}
