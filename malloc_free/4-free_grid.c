#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a 2D grid created by alloc_grid
 * @grid: the grid to free
 * @height: number of rows in the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int h;

	if (grid == NULL)
		return;

	for (h = 0; h < height; h++)
		free(grid[h]);

	free(grid);
}
