void solve(char** board, int row, int col) {
    
    if(col<=2)return;
    if(row<=2)return;
    int i,j;
    bool mark[row][col];
    for (i=0;i<row-1;i++)
    {
        for(j=0;j<col-1;j++)
        {
            if(board[i][j]=='X')
                mark[i][j]=true;
            else
                mark[i][j]=false;
        }
        
    }
    for (i=0,j=0;j<col;j++)
        if(!mark[i][j])
             DEP(board,i,j,row,col,mark);
   
    for (i=0,j=0;i<row;i++)
        if(!mark[i][j])
             DEP(board,i,j,row,col,mark);
     
    for (i=row-1,j=0;j<col-1;j++)
        if(!mark[i][j])
             DEP(board,i,j,row,col,mark);
    //printf("ssadada");
    for (i=0,j=col-1;i<row;i++)
        if(!mark[i][j])
             DEP(board,i,j,row,col,mark);
        
    for (i=0;i<row-1;i++)
        for(j=0;j<col-1;j++)
            if(mark[i][j]==false)
                board[i][j]='X';
    
}
void DEP(char **board,int i,int j,int row,int col,bool mark[row][col])
{
   
    if(i<0||i>=row||j<0||j>=col||mark[i][j]||board[i][j]=='X')
        return;
     mark[i][j]=true;
    DEP(board,i-1,j,row,col,mark);
    DEP(board,i+1,j,row,col,mark);
    
    DEP(board,i,j+1,row,col,mark);
    //if(j>1)
    DEP(board,i,j-1,row,col,mark);
    
    
    
}