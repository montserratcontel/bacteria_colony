#include <stdio.h>
#include <stdlib.h>

void read_matrix(int n, int m[n][n]){ //read the matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&(m[i][j]));
        }
    }
}
void toroidal_conversion(int n, int m[n+2][n+2]){
    //first we define the corners
    m[0][0]=m[n][n]; m[0][n+1]=m[n][1];
    m[n+1][0]=m[1][n]; m[n+1][n+1]=m[1][1];
    //then the first and last col/row
    for(int i=1;i<n+1;i++){
        m[0][i]=m[n][i]; m[n+1][i]=m[1][i];
        m[i][0]=m[i][n]; m[i][n+1]=m[i][1];
    }
}
void copy_matrix(int n, int to[n+2][n+2], int m[n][n]){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++)
            to[i][j]=m[i-1][j-1];
    }
    toroidal_conversion(n, to);
}
void print_matrix(int n, int m[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}
void countneigh(int r, int col, int colony, int n, int tor[n+2][n+2], int m[n][n]){
    int enemy;
    //we define the number of the enemy colony depending on colony
    if(colony==0){enemy=1;}
    else if(colony==1){enemy=2;}
    else{enemy=0;}

    int nenemy=0;
    //counts the number of enemies around the position tor[r][col]
    for(int i=0;i<3;i++){
        if(tor[r-1][col-1+i]==enemy){nenemy=nenemy+1;}
        if(tor[r+1][col-1+i]==enemy){nenemy=nenemy+1;}
    }
    if(tor[r][col-1]==enemy){nenemy=nenemy+1;}
    if(tor[r][col+1]==enemy){nenemy=nenemy+1;}

    //if theres 3 or more enemies, they will invade
    if(nenemy>=3){m[r-1][col-1]=enemy;}
}
void iteration(int n, int tor[n+2][n+2], int m[n][n]){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            countneigh(i, j, tor[i][j], n, tor, m);
        }
    }
    copy_matrix(n,tor,m);
}
void do_iterations(int niterations, int n, int tor[n+2][n+2], int m[n][n]){
    for(int i=1;i<=niterations;i++)
        iteration(n, tor, m);
}
int main() {
    int n; //matrix dimension
    scanf("%d",&n);

    int m[n][n];
    int tor[n+2][n+2];
    read_matrix(n,m);
    copy_matrix(n,tor,m);
    int nit;
    scanf("%d",&nit);
    do_iterations(nit, n, tor, m);
    print_matrix(n,m);
}
