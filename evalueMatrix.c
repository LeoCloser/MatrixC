#include <conio.h>
#include <stdio.h>
#define max 10
#define sizeS 3

int evalueCenter(int matrix[10][10], int a, int b)
{
	int cardinal[4][2] = { {1,0}, {0,1}, {-1,0}, {0, 1} };
	int i=0; 
	int x=0, y=0;
	int flag=0; 
	
	for(i=0; i<4; i++)
	{
		x = cardinal[i][0];
		y = cardinal[i][1];
		if( matrix[a + ( 1*(x) ) ][b + ( 1*(y) )] == 1)
			flag=1;
		else 
			return 0;
	}
	return flag;
}

int evalueOutsideMatrix(int matrix[10][10], int a, int b, int casa){
	int diagonal[4][2] = { {-1,1}, {-1,-1}, {1,1}, {1,-1} };
	int i=0;
	int x=0, y=0;
	int flag=0; 
	int cnt=0;
	
	for(i=0; i<4; i++)
	{
		x = diagonal[i][0];
		y = diagonal[i][1];
		
		if( matrix[a + ( 1*(x) ) ][b + ( 1*(y) )] == casa)
		{
			cnt++;
		}
	}
	return cnt;
}

//Evalue if as the same
int evalueTwoFigures(int figure1[3][3], int figure2[3][3], int a, int b)
{
	int directions[9][2] = { {0, 0}, {-1,1}, {-1,-1}, {1,1}, {1,-1}, {1,0}, {0,1}, {-1,0}, {0, 1} };
	int i=0, x=0, y=0; 
	int flag=0; 
	
	for(i=0; i<9; i++)
	{
		x = directions[i][0];
		y = directions[i][1]; 
		
		if( figure1[a+(1*(x))][b+(1*(y))] == figure2[a+(1*(x))][b+(1*(y))] ){
			flag=1;
		} else {
			return 0;
		}	
	}
	return flag;
}

//Evalue if as the same with 2, 3 or 4 ways
int evalueTwoFiguresGeneric(int figure1[3][3], int a, int b, int type)
{
	int directions[9][2] = {{0, 0},{-1,1},{-1,-1},{1,1},{1,-1},{1,0},{0,1},{-1,0},{0,1}};
	int i=0, x=0, y=0; 
	int flag=0; 
	int target=2;
	
	while( a < type && b < type)
	{
		for(i=0; i<9; i++)
		{
			x = directions[i][0];
			y = directions[i][1]; 	
			if( figure1[a+(1*(x))][b+(1*(y))] == target )
				flag=1;
			else 
				return 0;
			
		}
		a++;
		b++;
	}
	
	return flag;
}
/*
int **getSubMatrix(int matrix[10][10], int x, int y, int size)
{
	int i=0, j=0, a=0, b=0;
	int subMatrix[size][size];
	
	if( size < 10 )
	{
		for(i=x; i<10-size; i++)
		{
			for(j=y; j<10-size; j++)
			{
				subMatrix[a][b] = matrix[i][j];
				b++;
			}
			a++;
		}
		return subMatrix;	
	} else {
		return;
	}
}*/

void getSubstring(int matrix[10][10], int substring[sizeS][sizeS], int x, int y)
{
	int i=0, j=0; 
	int a=0, b=0;
	
	if( sizeS < max && ((x < max && x > 0) && (y < max && y > 0)) && ((x+sizeS)) < max && (y+sizeS) < max)
	{
		for(i=x; i< (x+sizeS); i++)
		{
			
			for(j=y; j< (y+sizeS); j++)
			{
				substring[a][b] = matrix[i][j];
				b++;
			}
			a++;
		}
	} 	
}

void printMatrix(int m[max][max]){
	int i=0, j=0; 
	
	for(i=0; i<max; i++){
		for(j=0; j<max; j++){
			printf(" %d|%d: %d ", i, j, m[i][j]);
		}
		printf("\n");
	}
	
}

void printMatrixTwo(int m[3][3]){
	int i=0, j=0; 
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("[%d][%d]= %d", i, j, m[i][j]);
		}
		printf("\n");
	}
	
}

int main(void){
	
	int matrix[max][max] = { 
	
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 4, 0, 0, 1, 4, 0, 0},
		{0, 1, 1, 1, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
		{1, 1, 1, 0, 1, 0, 0, 1, 1, 1},
		{0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
							 	
	};	
	
	int figure1[3][3] = { {1,0,0},
						  {1,0,0},
						  {1,1,1}
	};
	
	int figure2[3][3] = { {1,0,0},
						  {1,0,0},
						  {1,1,1}
	};
	
	int figure3[5][5] = {
						  {0,0,0,0,0},
						  {0,0,0,0,0},
						  {0,0,0,0,0},
						  {0,0,0,0,0},
						  {0,0,0,0,0}
	};
	
	int figure4[5][5] = {
						  {0,0,0,0,0},
						  {0,1,0,0,0},
						  {0,1,0,0,0},
						  {0,1,1,1,0},
						  {0,0,0,0,0}
	};
	int substring[sizeS][sizeS]; 
	
	printf("Si es centro: %d", evalueCenter(matrix, 3, 2)); 
	printf("Figuras Iguales: %d\n", evalueTwoFigures(figure1,figure2, 1, 1) ); 
	//printf("Si es centro: %d", evalueCenter(matrix, 3, 2)); 
	
	printMatrix(matrix); 
	printf("\n");
	getSubstring(matrix, substring, 2, 2);
	printf("\n");
	printMatrixTwo(substring);
	return 0;
}


