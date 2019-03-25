#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int** tab, int n) {
    bool flag=true;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(tab[i][j]!=0) flag=false;
        }
        if(!flag) break;
    }
   if(flag) return true;
   flag=true;
   for(int i=1; i<n; i++){
        for(int j=n-1; j>n-i-1; j--){
            if(tab[i][j]!=0) flag=false;
        }
        if(!flag) break;
    }
    return flag;

}
}

int main() {
    int n;
    scanf("%d", &n);
    int** tab = malloc(n*n* sizeof(int));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", tab[i][j]);
        }
    }

    printf(is_triangular(tab, n) ? "YES\n" : "NO\n");

    free(tab);