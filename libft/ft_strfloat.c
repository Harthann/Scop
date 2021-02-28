#include "libft.h"

#include <stdio.h>
static float decimal_part(const char *str, int *offset, int *error)
{
    float decimals;
    int     zero_count;

    if (str[*offset] != '\0' && str[*offset] < '0' && str[*offset] > '9')
    {
        *error = 1;
        return -1;
    }
    zero_count = 0;
    decimals = (float)ft_atoi(str + *offset);
    while (str[*offset] && str[*offset] == '0')
    {
        ++zero_count;
        ++*offset;
    }
    while (str[*offset] && str[*offset] >= '0' && str[*offset] <= '9')
        ++*offset;
    while (decimals > 1)
        decimals /= 10;
    while (zero_count-- > 0)
        decimals /=10;
    return decimals;
}

float   ft_strfloat(const char *str, int *offset, int *error)
{
    int     integer_part;
    int     sign;
    float   ret;

    if (!str)
        return (0);
    sign = 1;
    if (str[*offset] == '-')
        sign = -1;
    if (sign < 0)
        *offset -= sign;
    if (str[*offset] < '0' && str[*offset] > '9')
        *error = 1;
    integer_part = ft_atoi(str + *offset);
    while (str[*offset] && str[*offset] >= '0'  && str[*offset] <= '9')
        ++*offset;
    if (str[*offset] == '.')
        ++*offset;
    ret = decimal_part(str, offset, error);
    return (sign * (ret + integer_part));
}