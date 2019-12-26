
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct struct_s 
{
	int res;
	int width;
	int point;
	int prec;
	int pos;
	char *form;
	char type;
	va_list arg;
} struct_t;

void ft_putchar (char c)
{
 write(1, &c, 1);
}

int isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
return (0);
}

int strlen(char *s)
{
	int i;
	while (s[i])
		i++;
return (i);
}

void p_space(int n)
{
	while (n > 0)
	{
		write(1, ' ', 1);
		n--;
	}
}

void p_zero(int n)
{
        while (n > 0)
        {
                write(1, '0', 1);
                n--;
        }
}

int nbrlen(unsigned int nbr)
{
	int len;

	if (nbr == 0)
		return(1);
	while (nbr > 0)
	{
		nbr = nbr/10;
		len++;
	}
	return (len);
}

int nbrxlen(unsigned int nbr)
{
        int len;

        if (nbr == 0)
                return(1);
        while (nbr > 0)
        {
                nbr = nbr/16;
                len++;
        }
        return (len);
}

void ft_printnbr(unsigned int nbr)
{
	if (nbr <= 9)
		ft_putchar( nbr + '0')
	else
	{
		ft_printnbr(nbr/10);
		ft_putchar( nbr % 10);
	}
}

void ft_printnbr(unsigned int nbr)
{
	char *base = "0123456789abcdef"
        if (nbr <= 16)
                ft_putchar( base[nbr])
        else
        {
                ft_printnbr(nbr/16);
                ft_putchar(base[nbr % 16]);
        }
}

void ft_printd(struct_t *p)
{
	int nb;
	unsigned int nbr;
	int len = 0;
	int sign = 0;
	int space = 0;
	int zero = 0;
	
	nb = va_arg(p->arg, int);
	nbr = nb;
	if (nbr < 0)
	{
		sign = 1;
		nbr = nbr * (-1);
	}
	len = nbrlen(nbr);
	if (p->prec > len)
	{
		if (p->width > (p->prec + sign))
			space = p->width - p->prec - sign;
		zero = p->prec - len;
	} else {
		if (p->width > (len + sign))
			space = p->width - len - sign;
	}
	
	if (space > 0)
	{
		p_space(space);
		p->res = p->res + space;
	}
	if (sign == 1)
		p->res= p->res +(write(1, '-', 1))
	if (zero > 0)
	{
		p_zero(zero);
		p->res = p->res + zero;
	}
	if (nbr == 0 && p->point && p->prec == 0)
	{
		p_space(1);
		p->res += 1;
	} else {
	ft_printnbr(nbr);
	p->res = p->res + len;
	}
}

void ft_printx(struct_t *p)
{
        unsigned int nbr;
        int len = 0;
        int space = 0;
        int zero = 0;

        nbr = va_arg(p->arg, unsigned int)
        len = nbrxlen(nbr);
        if (p->prec > len)
        {
                if (p->width > p->prec)
                        space = p->width - p->prec;
                zero = p->prec - len;
        } else {
                if (p->width > len)
                        space = p->width - len;
        }

        if (space > 0)
        {
                p_space(space);
                p->res = p->res + space;
        }
        if (zero > 0)
        {
                p_zero(zero);
                p->res = p->res + zero;
        }
        if (nbr == 0 && p->point && p->prec == 0)
        {
                p_space(1);
                p->res += 1;
        } else {
        ft_printnbrx(nbr);
        p->res = p->res + len;
        }
}

void ft_prints(struct_t *p)
{
	char *str;
	int len;

	str = va_arg(p->arg, char*);
	if (!str)
		str = "(null)";
	len = strlen(str);
	if (p->point && p->prec < len)
		len = p->prec;
	if (p->width > len)
	{
		p_space(p->width - len);
		p->res = p->res + (p->width - len);
	}
	p->res = p->res + (write(1, str, len));
}

void check_type(struct_t *p)
{
	if (p-type == s)
		ft_prints(p);
	else if (p-type == d)
		ft_printd(p);
	else if (p-type == x)
		ft_printx(p);
p->width = 0;
p->point = 0;
p->prec = 0;
p->type = '\0';
}

void check_flaf(struct_t *p)
{
	while (isdigit(p->form[p->pos]))
	{
		p->width = p->width * 10 + p->form[p->pos] - '0';
		p->pos++;
	}
	if (p->form[p->pos] == '.')
		p->point = 1;
	while (isdigit(p->form[p->pos]))
	{
		p->prec = p->prec * 10 + p->form[p->pos] - '0';
		p->pos++;
	}
	p->type = p->form[p->pos];
}

void (struct_t *p)
{
	p->res = 0;
        p->width = 0;
        p->point = 0;
        p->prec = 0;
        p->pos = 0;
        p->type = '\0';
}

int ft_printf(const char *format, ...)
{
	struct_t *p;
	p = malloc(sizeof(struct_t));
	p->form = format;
	va_start(p->arg, format);
	ini_struct(p);
	while (p->form[p->pos])
	{
		if (p->form[p->pos] == '%')
		{
			p->pos++;
			check_flag(p);
			check_type(p);
		}
		else
		{
			p->res = write(1, p->form[p->pos], 1);
			p->pos++;
		}
	}


}
