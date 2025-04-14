#include<stdlib.h>
#include<stdio.h>
int safe(char board[8][8],int col,int row){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q')
            return 0;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q')
            return 0;
    }
    for(int i=row,j=col;i>=0&&j<8;i--,j++){
        if(board[i][j]=='Q')
            return 0;
    }
    return 1;
}
void displayBoard(char board[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}
int nQueens(char board[8][8],int row){
    if(row>=8){
        return 1;
    }
    for(int i=0;i<8;i++){
        if(safe(board,i,row)){
            board[row][i]='Q';
            if(nQueens(board,row+1)){
                return 1;
            }
            board[row][i]='.';
        }
    }
    return 0;
}
void callNQueens(char board[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]='.';
        }
    }
    if(nQueens(board,0)){
        displayBoard(board);
    }else{
        printf("\nNo solution found!!");
    }
}
int main(){
    char board[8][8];
    callNQueens(board);
    return 0;
}
