/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void left(int *result, int **input_array, int c, int index, int *i, int *j){
	if (c == 0)
		return;
	result[index++] = input_array[*i][*j];
	*j = *j + 1;
	c--;
	left(result, input_array, c, index, i, j);
}
void down(int *result, int **input_array, int r, int index, int *i, int *j){
	if (r == 0)
		return;
	result[index++] = input_array[*i][*j];
	*i = *i + 1;
	r--;
	down(result, input_array, r, index, i, j);
}
void right(int *result, int **input_array, int c, int index, int *i, int *j){
	if (c == 0){
		return;
	}
	result[index++] = input_array[*i][*j];
	*j = *j - 1;
	c--;
	right(result, input_array, c, index, i, j);
}
void up(int *result, int **input_array, int r, int index, int *i, int *j){
	if (r == 0)
		return;

	result[index++] = input_array[*i][*j];
	*i = *i - 1;
	r--;
	up(result, input_array, r, index, i, j);
}
void spiral_wrapper_1(int *result, int **input_array, int r, int c, int index, int i, int j){
	while (1){
		if (c == 1){
			result[index] = input_array[i][j];
			return;
		}
		left(result, input_array, c, index, &i, &j);
	
		r--;
		if (r == 0){
			return;
		}
		i++, j--;
		index = index + c;
		down(result, input_array, r, index, &i, &j);
		j--, i--;
		c--;
		index = index + r;
		right(result, input_array, c, index, &i, &j);
		i--;
		j++;
		index = index + c;
		c--;
		r--;
		if (r == 0){
			return;
		}
		up(result, input_array, r, index, &i, &j);
		index = index + r;
		i++, j++;
	}
}
int *spiral(int rows, int columns, int **input_array)
{ if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *result = (int*)malloc(sizeof(int) * rows * columns);
	if (rows == 1 && columns == 1)
	{
		result[0] = input_array[0][0];
		return result;
	}
	else if (columns == 1)
	{
		int i = 0, k = 0;
		while (k < rows){
			result[k++] = input_array[i][0];
			i++;
		}
		return result;
	}
	else if (rows == 1)
	{
		int j = 0, k = 0;
		while (k < columns){
			result[k++] = input_array[0][j];
			j++;
		}
		return result;
	}
	spiral_wrapper_1(result, input_array, rows, columns, 0, 0, 0);
	return result;
}
