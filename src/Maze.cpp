/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/
#include <stdio.h>
#include<stdlib.h>
int check_path(int i, int j, int arr[][2], int len){
	int m = 0;
	while (m < len){
		if ((arr[m][0] == i) && (arr[m][1] == j))
			return 0;
		m++;
	}
	return 1;
}
int path_exists_wrapper1(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int arr[][2], int *i, int j, int len){
	int res = 0;
	if (x1 == x2 && y1 == y2){
		return 1;
	}
	if (*((maze + x1*columns) + y1) == 0){
		return 0;
	}
	if (x1 < 0 || x1 >(rows - 1) || y1 < 0 || y1 >(columns - 1)){
		return 0;
	}
	arr[*i][0] = x1;
	arr[*i][1] = y1;
	*i = *i + 1;
	int path = check_path(x1 + 1, y1, arr, len++);
	if (path == 1){
		res = path_exists_wrapper1(maze, rows, columns, x1 + 1, y1, x2, y2, arr, i, j, len);
		if (res == 1){
			return 1;
		}
	}
	path = check_path(x1, y1 + 1, arr, len);
	if (path == 1){
		res = path_exists_wrapper1(maze, rows, columns, x1, y1 + 1, x2, y2, arr, i, j, len);
		if (res == 1){
			return 1;
		}
	}
	path = check_path(x1 - 1, y1, arr, len);
	if (path == 1){
		res = path_exists_wrapper1(maze, rows, columns, x1 - 1, y1, x2, y2, arr, i, j, len);
		if (res == 1){
			return 1;
		}
	}
	path = check_path(x1, y1 - 1, arr, len);
	if (path == 1){
		res = path_exists_wrapper1(maze, rows, columns, x1, y1 - 1, x2, y2, arr, i, j, len);
		if (res == 1){
			return 1;
		}
	}
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0)
		return 0;
	if (x1 < 0 || x1 >(rows - 1) || y1 < 0 || y1 >(columns - 1))
		return 0;
	if (x2 < 0 || x2 >(rows - 1) || y2 < 0 || y2 >(columns - 1))
		return 0;
	if (*((maze + x1*columns) + y1) == 0 || *((maze + x2*columns) + y2) == 0)
		return 0;
	if (columns == 1){
		while (x1 <= x2){
			if ((*((maze + x1*columns) + y1)) == 1){
				x1++;
				continue;
			}
			else
				break;
		}
		if (x1 >= x2)
			return 1;
		else return 0;
	}
	if (rows == 1){
		while (y1 <= y2){
			if (*((maze + x1*columns) + y1) == 1){
				y1++;
				continue;
			}
			else{
				break;
			}
		}
		if (y1 >= y2)
			return 1;
		else return 0;
	}
	//printf("%d ", *((maze + x1*rows) + y1));
	int arr[50][2];
	int i = 0;
	return path_exists_wrapper1((int *)maze, rows, columns, x1, y1, x2, y2, arr, &i, 0, 0);
	return 1;
}
