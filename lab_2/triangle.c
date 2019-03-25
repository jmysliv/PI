#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int** tab, int n) {
    if(n==1 && tab[0][0]==0) return true; //corner case
    if(n<2) return false;   //corner case
    bool flag=true;
    /*
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(tab[i][j]!=0) flag=false;
        }
        if(!flag) break;
    }
    if(flag) return true;
    flag=true; */
    for(int i=1; i<n; i++){
        for(int j=n-1; j>n-i-1; j--){
            if(tab[i][j]!=0) flag=false;
        }
        if(!flag) break;
    }
    return flag;

}


int main() {
    int n;
    scanf("%d", &n);
    int **tab;
    tab=(int**)malloc(n*sizeof(int *));
    for(int i=0; i<n; i++)
    {
        tab[i]=(int*)malloc(n*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    printf(is_triangular(tab, n) ? "YES\n" : "NO\n");

    free(tab);
}
