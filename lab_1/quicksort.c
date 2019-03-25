#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) do { int tmp = a; a = b; b = tmp; } while (0)

int partition(int* tab, int left, int right) {
    int x = tab[right];
    int j = left - 1;
    for(int i=left; i<right; i++){
        if(tab[i]<x){
            j++;
            SWAP(tab[i], tab[j]);
        }
    }
    j++;
    SWAP(tab[right], tab[j]);
    
    return j;
}

void quickSort(int tab[], int left, int right) {
    if(left>=right) return;
    int pivot=partition(tab, left, right);
    quickSort(tab, left, pivot - 1);
    quickSort(tab, pivot + 1, right);
}

int main() {
    int Z;

    scanf("%d", &Z);

    int val;

	while (Z--) {

		int n;
		scanf("%d", &n);
        int *tab = malloc(n*sizeof(n));
		for(int i=0; i<n; i++) {
			scanf("%d", &tab[i]);
		}
        
        quickSort(tab, 0, n-1);
        for(int i=0; i<n; i++) {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }
}
