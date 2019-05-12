#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;

int distance(char* a, int a_length, char* b, int b_length) {
   int **tab = malloc((a_length+1)* sizeof(int *));
   for(int i=0; i<a_length+1; i++) tab[i] = malloc((b_length+1)* sizeof(int));
   for(int i=0; i<a_length+1; i++) tab[i][0] = i;
   for(int j=0; j<b_length+1; j++) tab[0][j] = j;

   int cost;
   for(int i=1; i<a_length+1; i++){
       for(int j=1; j<b_length+1; j++){
           if(a[i-1]==b[j-1]) cost=0;
           else cost=1;
           int min = tab[i-1][j] +1;
           if(tab[i][j-1]+1 < min) min = tab[i][j-1] +1;
           if(tab[i-1][j-1] + cost < min) min = tab[i-1][j-1] + cost;
           tab[i][j] = min;
       }
   }

   return tab[a_length][b_length];
}

int main() {
    char* a = malloc(MAX_TEXT_LENGTH*sizeof(char));
    char* b = malloc(MAX_TEXT_LENGTH*sizeof(char));
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    printf("%d\n", distance(a, strlen(a), b, strlen(b)));
}