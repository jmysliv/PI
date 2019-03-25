#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if(n%2==0) return false;
    int b=3;
    while(b*b<=n){
        if(n%b==0) return false;
        b+=2;
    }

    return true;
}

bool Is_non_descending(int a){
    int tmp=a%10;
    a/=10;
    while(a>0){
        if(a%10>tmp) return false;
        tmp=a%10;
        a/=10;
    }
    return true;
}



int main() {
    int n;
    scanf("%d", &n);
    if(n>=2) printf("2\n");
    for(int i=3; i<=n; i+=2){
        if(Is_non_descending(i) && isPrime(i)) printf("%d\n", i);
    }
    return 0;
}