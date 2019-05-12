#include <stdio.h>
#include <stdlib.h>

int change(int amount, int* coins, int coins_count, int* result) {
    int i = coins_count - 1;
    int j=0;
    while(amount!=0){
        if(coins[i]<=amount){
            amount-=coins[i];
            result[j]=coins[i];
            j++;
        }
        else i--;
    }

    return j;
}

int main() {
    int RESULT_LIMIT = 20;
    int *results = malloc(RESULT_LIMIT*sizeof(int));
    int N, C;
    scanf("%d", &N); // number of test cases
    scanf("%d", &C); // number of coins
    int* coins = malloc(C*sizeof(int));
    for(int i=0; i<C; i++) scanf("%d", &coins[i]);

    int change_to_give, results_count;
    for(int i=0; i<N; i++) {
        scanf("%d", &change_to_give);
        results_count = change(change_to_give, coins, C, results);
        for(int i=0; i<results_count; i++) printf("%d ", results[i]);
        printf("\n");
    }

    free(results);
    free(coins);
}