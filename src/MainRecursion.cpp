#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"
void generate_array(int **input_array, int rows, int columns, int seq)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			input_array[i][j] = (k++)*seq;
}
int main(){
	int n = 16;
	int board[16][16];
	int i = 0, j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}

	int result = solve_nsnipers(&board[0][0], n);
	printf("result is %d\n", result);
	for (int i = 0; i <n; i++){
		for (int j = 0; j < n; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	//Check NSnipers

	//Check CountPairs Sample Code 
	/*int pairs = count_pairs_wrapper("abababababxxxyyy", 16);
	printf("pairs %d\n", pairs);
	
	//Check Steps Sample Code
	int result = get_steps(10);
	printf("steps %d\n", result);*/
	//Check Spiral Sample Code

	/*int rows = 5, columns = 5;
	int **input_array = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
		input_array[i] = (int *)malloc(columns * sizeof(int));

	generate_array((int**)input_array, rows, columns, 1);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++)
			printf("%d ", input_array[i][j]);
		printf("\n");
	}
	int *output_array = spiral(rows, columns, (int**)input_array);
	for (int i = 0; i < rows * columns; i++)
		printf("%d ", output_array[i]);*/
	//Check Maze Sample Code

	/*int maze[3][5] = {
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	int m = 3, n = 5;
	int x1 = 1, y1 = 0, x2 = 2, y2 = 3;
	/*int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;
	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d value\n", check);*/

	
	return 0;
}