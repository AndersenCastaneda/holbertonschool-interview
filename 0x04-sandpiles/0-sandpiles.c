#include "sandpiles.h"

/**
 * sandpiles_sum - Sum and stabilizes two sand piles
 * @grid1: First pile
 * @grid2: Second pile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (is_unstable(grid1, grid2))
	{
		printf("=\n");
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
				printf((j == len - 1) ? "%d\n" : "%d ", grid1[i][j]);
		}
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (grid2[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (i > 0)
						++grid1[i - 1][j];
					if (i < len - 1)
						++grid1[i + 1][j];
					if (j > 0)
						++grid1[i][j - 1];
					if (j < len - 1)
						++grid1[i][j + 1];
				}
			}
		}
	}
}

/**
 * is_unstable - Checks if a sandpile is unstable
 * @grid: Sandpile to check
 * @backup: Copy of the sandpile
 * Return: 1 if is unstable, otherwise 0
 */
int is_unstable(int grid[3][3], int backup[3][3])
{
	int i, j, unstable = 0;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			backup[i][j] = grid[i][j];
			if (backup[i][j] > 3)
				unstable = 1;
		}
	}

	return (unstable);
}
