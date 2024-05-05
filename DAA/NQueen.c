#include <stdio.h>

int main()
{
    int board[5][5];
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j - 0; j < 5; j++)
        {
            board[i][j] = 0;
        }
    }

    n_queen(1, 4, 4, board);

    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}



int is_attacking(int i, int j, int board[5][5], int N)
{
    // i(row number)
    // j(column number)
    // board(a 2D array representing the chessboard)
    // N(size of the chessboard)

    // This loop checks if there is any queen already placed in the same column j above the current row i.If a queen is found, it returns 1(indicating an attack).
    int k, l;
    for (k = 1; k <= i - 1; k++)
    {
        if (board[k][j] == 1)
        {
            return 1;
        }
    }


    // checks for upper right diagnol
    k = i - 1;
    l = j + 1;
    while (k >= 1 && l <= N)
    {
        if (board[k][l] == 1)
        {
            return 1;
        }
        k += 1;
        l += 1;
    }

    //upper left
    k=i-1;
    l=j-1;
    while(k>=1 && l>=1){
        if (board[k][l]==1){
            return 1;
        }
        k=k-1;
        l=l-1;
    }
    return 0;
}

int n_queen(int row,int n,int N,int board[5][5]){
    // row(the current row being processed)
    // n(the number of remaining queens to be placed)
    // N(the size of the chessboard)
    // board(a 2D array representing the chessboard)

    if (n==0){
        return 1;
    }
    int j;
    for(j=1;j<=N;j++){
        if(!is_attacking(row,j,board,N)){
            board[row][j]=1;
            if(n_queen(row+1,n-1,N,board)){
                return 1;
            }
            board[row][j]=0;
        }
    }
    return 0;
}