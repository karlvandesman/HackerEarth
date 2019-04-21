/* - - - - - - - - Hacker Earth Problems - - - - - - - -
	Problem:	N-Queens
	Author: 	Karl Sousa <karlvandesman@gmail.com
*/
//https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/n-queensrecursion-tutorial/

#include<stdio.h>

int isAttacked(int x, int y, int size, int board[size][size]){
    
	//cheking for row and column
	for(int i = 0; i < size; ++i)	//checking if any cell in xth row is 1
		if(board[x][i] == 1)
			return 1;

	for(int i = 0; i < size; ++i)	//checking if any cell in yth column is 1
		if(board[i][y] == 1)
			return 1;
    
	//checking for diagonals
	for(int i = 1; (x + i < size) && (y + i < size); ++i)   //cheking southeast of (x, y)
		if(board[x + i][y + i] == 1)
			return 1;

	for(int i = 1; (x - i >= 0) && (y - i >= 0); ++i)   //cheking northwest of (x, y)
		if(board[x - i][y - i] == 1)
			return 1;

	for(int i = 1; (x - i >= 0) && (y + i < size); ++i)	//cheking northeast of (x, y)
		if(board[x - i][y + i] == 1)
			return 1;

	for(int i = 1; (x + i < size) && (y - i >= 0); ++i) //cheking southwest of (x, y)
		if(board[x + i][y - i] == 1)
			return 1;

	return 0;   //If it passes through all conditions, return 0 (safe)
}

int Nqueens(int size, int board[size][size], int N){
    int a, b;
    
	if(!N)  //if there is no more queens to be placed, we've reached the base case!
		return 1;

	for(a = 0; a < size; ++a){      //iterate through matrix
		for(b = 0; b < size; ++b){
		    
			if(isAttacked(a, b, size, board))   //Checking if the position (a, b) is safe
				continue;   //if it returns 1, its not safe, so jump to the next point (a, b)

			board[a][b] = 1;    //If the place is safe, just put the queen on it!
			
			if(Nqueens(size, board, N - 1)) //Now we have to call the recursion and check
				return 1;                   //the board with N - 1 queens to put in it.
			
			board[a][b] = 0;    //If it returns 0, so remove the queen from this place :((
		}
	}

	return 0;
}

int main(){
    int N;  //Number of queens

    scanf("%d", &N);
    
    int size = N;   //We have to distinguish N (the number of queens) and the board
                    //size, because we will be decreasing the value of N, but size
                    //should remain the same.
    
    int board[N][N];
    
    //Initializing the values
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            board[i][j] = 0;
    
    if(Nqueens(size, board, N)){
        printf("YES\n");
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j)
                printf("%d ", board[i][j]);
                
            printf("\n");
        }
    }
    else    //If the function returns 0, so there is no way to arrange all the queens :(
        printf("NO\n");
    
    return 0;
}