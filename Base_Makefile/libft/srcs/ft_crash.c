#include "../header/libft.h"

void	ft_crash(char **str)
{
	int	i;

	i = 0;
	*str = malloc(sizeof(char *) * 1);
	while (i < 10)
	{
		*str[i] = 'a';
		i++;
	}
}
