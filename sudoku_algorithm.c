#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

int grid[ROW][COL];

int isDoneAll()
{
    for (int i = 1; i <= 9 ;i++){
        for (int j = 1; j <= 9; j++){
            if (grid[i][j] == 0) return 0;
        }
    }
    return 1;
}

int isUsedInCol(int consideredCol, int consideredNumb)
{
    for (int i = 1; i <= 9; i++){
        if (grid[i][consideredCol] == consideredNumb){
            return 1;
        }
    }
    return 0;
}

int isUsedInBox(int consideredRow, int consideredCol, int consideredNumb)
{
    for (int i = 1; i < 3; i++){
        int sameBoxRow;
        if ((consideredRow-1)%3 + i < 3){
            sameBoxRow = consideredRow + i;
        }else{
            sameBoxRow = consideredRow + i - 3;
        }
        for (int j = 1; j < 3; j++){
            int sameBoxCol;
            if ((consideredCol - 1)%3 + i < 3){
            sameBoxCol = consideredCol + j;
            }else{
                sameBoxCol = consideredCol + j - 3;
            }
            if (grid[sameBoxRow][sameBoxCol] == consideredNumb) return 1;
        }
    }
    return 0;
}

int isUsedInRow(int consideredRow, int consideredNumb)
{
    for (int i = 1; i <= 9; i++){
        if (consideredNumb == grid[consideredRow][i]){
            return 1;
        }
    }
    return 0;
}

int isSafe(int consideredRow, int consideredCol, int consideredNumb)
{
    if (isUsedInBox(consideredRow, consideredCol, consideredNumb)
      ||isUsedInCol(consideredCol, consideredNumb)
      ||isUsedInRow(consideredRow, consideredNumb)) return 0;
    return 1;
}

int solveSudoku(int consideredRow, int consideredCol)
{
    if (isDoneAll()) return 1;

    consideredCol++;
    if (consideredCol == 10){
            consideredCol = 1;
            consideredRow++;
    }

    if(grid[consideredRow][consideredCol] == 0){
        for (int i = 1; i <= 9; i++){
            if (isSafe(consideredRow, consideredCol, i)){
                grid[consideredRow][consideredCol] = i;
                if (solveSudoku(consideredRow, consideredCol)){
                    return 1;
                }else{
                    grid[consideredRow][consideredCol] = 0;
                }
            }
        }
    }else{
        if (solveSudoku(consideredRow,consideredCol)) return 1;
    }
    return 0;
}

void printSolution()
{
    for (int i = 1; i <= 9 ;i++){
        for (int j = 1; j <= 9; j++){
            printf("%d ", grid[i][j]);
        }
    }
}

void input()
{
    for (int i = 1; i <= 9 ;i++){
        for (int j = 1; j <= 9; j++){
            scanf("%d", &grid[i][j]);
        }
    }
}

void main()
{
    input();
    if (solveSudoku(1,0)){
        printSolution();
    }else{
        printf("No solution!");
    }
}