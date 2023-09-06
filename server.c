#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void    display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", GREEN, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", GREEN, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", GREEN, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", GREEN, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", GREEN, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: mdoulahi%s\n", BLUE, pid, END,
		GREEN, END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void handler(int sig)
{
    static int				bit = 0;
	static unsigned char	c = 0;
    c <<= 1;
    if (sig == SIGUSR1)
        c = c | 0b00000001;

    bit++;
    if (bit == 8)
    {
        ft_printf("%c", c);
        bit = 0;
        c = 0;
    }
}

int main(void)
{
    
    display_banner(getpid());
    signal(SIGUSR1, handler);  // 0
    signal(SIGUSR2, handler);  // 1
    while (1)
    {
        pause();
    }
    return (0);
}