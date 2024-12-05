#include <stdio.h>
#include <stdlib.h>

void	force_maximale(int longueur, int *tunnel)
{
	int	E, R, *dp, i, j;

	scanf("%d %d", &E, &R);
	dp = (int *)malloc((longueur + 1) * sizeof(int));
	for (i = 0; i <= longueur; ++i)
		dp[i] = -1000000;
	dp[0] = 0;
	i = 0;
	while (i < longueur)
	{
		if (tunnel[i] == 1)
		{
			j = 1;
			while (j <= E && i + j <= longueur)
			{
				if (i + j <= longueur)
					dp[i + j] = dp[i + j] > dp[i] + j ? dp[i + j] : dp[i] + j;
				++j;
			}
		}
		else
		{
			j = 1;
			while (j <= R && i + j <= longueur)
			{
				if (i + j <= longueur)
					dp[i + j] = dp[i + j] > dp[i] - j ? dp[i + j] : dp[i] - j;
				++j;
			}
		}
		++i;
	}
	printf("%d\n", dp[longueur]);
	free(dp);
}

int	main(void)
{
	int	longueur;
	int	*tunnel;
	int	i;

	scanf("%d", &longueur);
	tunnel = (int *)malloc(longueur * sizeof(int));
	i = 0;
	while (i < longueur)
	{
		scanf("%d", &tunnel[i]);
		++i;
	}
	force_maximale(longueur, tunnel);
	free(tunnel);
	return (0);
}
