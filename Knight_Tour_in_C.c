// Knight Tour :
// Solution is one of the feasable solutions.(using naive method)
// Not optimal

#include <stdio.h>
#include <stdbool.h>
#define N 8

//C90 does not support the boolean data type.
//C99 does include it within stdbool

bool KnightTourUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

/* a utility function to check if i and j are valid indexes
   for N*N chessboard */
bool isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* A utility function to print solution matrix sol[N][N]
*/
void printSolution(int sol[N][N])
{
    for(int x = 0; x < N; x++)
    {
        for (int y =0; y < N; y++)
            printf("%2d ", sol[x][y]);
        printf("\n");
    }
}


/*
KnightTour() is a function that uses backtracking . i
It uses KnightTourUtil function. It return true only if
there is a solution. This solution is not unique.
The solution is only one of the feasible solutions.
*/
bool KnightTour()
{
    int sol[N][N];
    // initialization of solution matrix
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            sol[x][y] = -1;

    /*
    xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate
    */
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    //since the knight is initially at the first block
    sol[0][0] = 0;

    //start from 0,0 and explore all tours using KnightTourUtil()
    if(KnightTourUtil(0, 0, 1, sol, xMove, yMove))
    {
        printSolution(sol);
        return true;
    }
    else
    {
        printf("Solution does not exist");
        return false;
    }
}

/*
A recursive utility function to solve knight tour problem
*/
bool KnightTourUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if(movei == N*N)
        return true;

    /*
    try all next moves from the current coordinate x,y
    */
    for(k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y] = movei;
            if(KnightTourUtil(next_x, next_y, movei+1, sol, xMove, yMove))
                return true;
            else
                sol[next_x][next_y] = -1; //backtracking
        }
    }
    return false;
}



/* Driver program to test above functions */
int main()
{
    KnightTour();
    return 0;
}
