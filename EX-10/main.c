#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int *board;

int isSafe(int row, int col)
{
    for(int r = 0; r < row; r++)
    {
        if(board[r] == col)
            return 0;

        if(abs(r - row) == abs(board[r] - col))
            return 0;
    }
    return 1;
}

void solve(int row)
{
    if(row == N)
    {
        for(int i = 0; i < N; i++)
            printf("%d ", board[i]);
        printf("\n");
        return;
    }

    for(int col = 0; col < N; col++)
    {
        if(isSafe(row, col))
        {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    printf("Enter N value: ");
    scanf("%d", &N);

    board = (int*)malloc(N * sizeof(int));

    solve(0);

    free(board);

    return 0;
}
